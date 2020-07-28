#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serials.h"

#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QTextCodec>
#include <QString>
#include <QStandardItemModel>
#include <QList>
#include <QSettings>
#include <QSystemTrayIcon>
#include <QDir>
#include <QFileDialog>
#include <QMenu>
#include <QCloseEvent>

const QString sCaptionName = "The next series 1.0";
const QString sExeName = "The next series.exe";
const QString sFileName = "data.tns";
const QString sCfgName = "config.cfg";
const QString sININame = "config.ini";
const QString sCollectionName = "Collection.mcln";

QString dataSaveDir;
QDir dataDir;

int setRadio;

QFile dataFile;
QFile mclnFile;

QStandardItemModel *model;

QSettings *settings;
QSettings *dataFolder;
bool itemsLoaded = false;

int CurrentSerialIndex = -1;

QSystemTrayIcon *tray;

int serialIndex;    //Выбранный сериал в таблице
int selectSerial;   //Выбранный сериал в комбоБокс

Serials serials;

void MainWindow::PickRadio()
{
    int setRadio = 0;
    if (dataDir.path() == QCoreApplication::applicationDirPath() + "/tns_data")
    {
        setRadio = 1;
        qDebug() << "setRadio по умолчанию " + dataDir.path() + " == " + QCoreApplication::applicationDirPath() + "/tns_data";
    }
    if (dataDir.path() == QDir::homePath() + "/Dropbox/tns_data")
    {
        setRadio = 2;
        qDebug() << "setRadio dropbox " + dataDir.path() + " == " + QDir::homePath() + "/Dropbox/tns_data";
    }

    switch (setRadio)
    {
    case 0: //Пользовательский адресс - rb2
        ui->radioButton_2->setChecked(true);
        break;
    case 1: //По умолчанию
        ui->radioButton_3->setChecked(true);
        break;
    case 2: //ДропБокс
        ui->radioButton->setChecked(true);
        break;
    }
}

void MainWindow::trayIconClicked(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:  this->show();
    case QSystemTrayIcon::DoubleClick:

        break;
    case QSystemTrayIcon::MiddleClick:
        on_pushButton_10_clicked();
        SetSerial(ui->comboBox->currentIndex());
        break;
    default:
        ;
    }
}

void MainWindow::createActions()
{
    open = new QAction(tr("&Open"), this);
    connect(open, SIGNAL(triggered()), this, SLOT(show()));

    FormHide = new QAction(tr("&Hide"), this);
    connect(FormHide, SIGNAL(triggered()), this, SLOT(hide()));

    watched = new QAction(tr("&Watched  (Middle mouse)"), this);
    connect(watched, SIGNAL(triggered()), this, SLOT(on_pushButton_10_clicked()));

    close = new QAction(tr("&Quit"), this);
    connect(close, SIGNAL(triggered()), qApp, SLOT(quit()));
}

void MainWindow::createTrayIcon()
{
    trayIconMenu = new QMenu(this);


    trayIconMenu->addAction(open);
    trayIconMenu->addAction(FormHide);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(watched);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(close);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);


    connect(
            trayIcon,
            SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this,
            SLOT(trayIconClicked(QSystemTrayIcon::ActivationReason))
           );
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (ui->checkBox_3->isChecked()) return;
    if (trayIcon->isVisible())
    {
        if (!ui->checkBox_4->isChecked())
        {
            trayIcon->showMessage(tr("TNS here!!!"),
            tr("This application is still running. To quit please click this icon and select Quit"), QSystemTrayIcon::Information, 1000);
        }
        hide();
        event->ignore(); // Don't let the event propagate to the base class
    }
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTextCodec *cyrillicCodec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(cyrillicCodec);
    QTextCodec::setCodecForLocale(cyrillicCodec);
    QTextCodec::setCodecForCStrings(cyrillicCodec);

    ui->setupUi(this);
    ui->label_5->installEventFilter(this);

    this->setFixedSize(489, 371);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->comboBox->setEditable(false);

    createActions();
    createTrayIcon();

    QIcon icon = QIcon(":/res/icons/tns.png");
    trayIcon->setIcon(icon);
    trayIcon->setToolTip(tr("The next series"));
    trayIcon->show();

    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason )),
    this, SLOT(iconActivated(QSystemTrayIcon::ActivationReas on)));


    dataFolder = new QSettings(QCoreApplication::applicationDirPath() + "/DataFolder.ini", QSettings::IniFormat, 0);
    QFile dirSettings(QCoreApplication::applicationDirPath() + "/DataFolder.ini");
    if (!dirSettings.exists())
    {
        dataFolder->setValue("dataFolder", QCoreApplication::applicationDirPath() + "/tns_data");
        ui->radioButton_3->setChecked(true);
    }

    dataDir.setPath(dataFolder->value("dataFolder").toString());
    if (!dataDir.exists()) {
        dataDir.mkpath(".");
    }

    PickRadio();

    settings = new QSettings(dataDir.path() + "/Settings.ini", QSettings::IniFormat, 0);
    QFile serialsSettings(dataDir.path() + "/Settings.ini");
    if (!serialsSettings.exists())
    {
        settings->setValue("CurrentSerialIndex", -1);
        settings->setValue("DontShowNotifications", false);
        settings->setValue("SaveNumberSeriesAfterViewing", true);
        settings->setValue("ExitWhenClosingForm", false);
        settings->setValue("HideNotificationAboutHiding", false);
        settings->setValue("SavedOnExit", true);
    }

    ui->checkBox_2->setChecked(settings->value("SaveNumberSeriesAfterViewing").toBool());
    ui->checkBox->setChecked(settings->value("DontShowNotifications").toBool());
    ui->checkBox_3->setChecked(settings->value("ExitWhenClosingForm").toBool());
    if (ui->checkBox_3->isChecked()) ui->checkBox_4->setEnabled(false);
            else ui->checkBox_4->setEnabled(true);
    ui->checkBox_4->setChecked(settings->value("HideNotificationAboutHiding").toBool());
    ui->checkBox_5->setChecked(settings->value("SavedOnExit").toBool());

    ui->label_4->setText(tr("Later it will be shown the \nbatch number and the name \nof the show, which you \nyourself choose."));

//    QIcon icon = QIcon(QCoreApplication::applicationDirPath() + "2/address_32.png");
//    tray = new QSystemTrayIcon(icon, this);
//    tray->show();

    model = new QStandardItemModel(0, 0, this); //2 Rows and 2 Columns
    model->setHorizontalHeaderItem(0, new QStandardItem(QString(tr("Number"))));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString(tr("Title"))));
    ui->tableView->setModel(model);
    //qDebug() << serials.aSerials[1];
    //ui->label->setText(serials.aSerials[1]);
    this->setWindowTitle(sCaptionName);

    ui->tabWidget->setCurrentIndex(0);

    dataFile.setFileName(dataDir.path() + "/data.tns");
    if (!dataFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "*** Ошибка открытия для записи! *** ";
        qDebug() << "Директория: " + dataDir.path();
    }
    qDebug() << "*** Файл открыт. Начинаю чтение. ***";
    qDebug() << "Директория: " + dataDir.path();
    while (!dataFile.atEnd())
    {
            QByteArray line = dataFile.readLine();
            QString str = line.data();// <- прочитанная строка
            serials.addSerial(str.remove(str.length() - 1, 1));
            qDebug() << "# В массив и комбоБокс добавлена запись " + str;
    }
    FillCombo();

    qDebug() << "*** КомбоБокс заполнен. Было загружено  " + QString::number(serials.aSerials.length()) + "  элементов. ***";
    //qDebug() << serials.getSerialName(4) + " " + QString::number(serials.getSerialNum(4));
    FillTable(model);
    dataFile.close();

    QFile mclnFile(dataDir.path() + "/Collection.mcln");
    if (!mclnFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "*** Ошибка открытия коллекции для чтения! *** ";
        qDebug() << "Директория: " + dataDir.path();
    }
    QString Collection = mclnFile.readAll();
    ui->plainTextEdit->insertPlainText(Collection);
    mclnFile.close();

    itemsLoaded = true;
    CurrentSerialIndex = settings->value("CurrentSerialIndex").toInt();

    if ( CurrentSerialIndex == -1)
    {
        ui->label_4->setText(tr("At now I don't look anything."));
    }
    else
    {
        ui->comboBox->setCurrentIndex(CurrentSerialIndex);
        ui->label_4->setText(serials.setNoticeMessage(CurrentSerialIndex));
        this->setWindowTitle(serials.setWindowsTitle(CurrentSerialIndex));
        ui->statusBar->showMessage(serials.setWindowsTitle(CurrentSerialIndex));
    }
}

void MainWindow::FillCombo()
{
    QString S;
    for(int i = 0; i != serials.aSerials.length(); ++i)
    {
        S = "[" + QString::number(serials.getSerialNum(i)) + "] -- " + serials.getSerialName(i);
        ui->comboBox->addItem(S);
    }
}

void MainWindow::FillEditedCombo()
{
    QString S;
    for(int i = 0; i != serials.aSerials.length(); ++i)
    {
        S = "[" + QString::number(serials.getSerialNum(i)) + "] -- " + serials.getSerialName(i);
        ui->comboBox->setItemText(i, S);
    }
}

void MainWindow::FillTable(QStandardItemModel *model)
{
    model = new QStandardItemModel(0, 0, this); //2 Rows and 2 Columns
    model->setHorizontalHeaderItem(0, new QStandardItem(QString(tr("Number"))));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString(tr("Title"))));
    ui->tableView->setModel(model);
    for(int row = 0; row != serials.aSerials.length(); ++row)
    {
        for(int column = 0; column != 2; ++column)
        {
            QStandardItem *newNumItem = new QStandardItem(QString(QString::number(serials.getSerialNum(row))));
            model->setItem(row, 0, newNumItem);
            QStandardItem *newNameItem = new QStandardItem(QString(serials.getSerialName(row)));
            model->setItem(row, 1, newNameItem);
        }
    }
    ui->tableView->resizeColumnsToContents();
}

MainWindow::~MainWindow()
{
    if (ui->checkBox_5->isChecked())
    {
        saveSerials();
        saveCollection();
    }
    delete ui;
    delete trayIcon;
    delete trayIconMenu;
    delete open;
    delete close;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_pushButton_clicked()    //Добавление сериала
{
    QString Name = ui->lineEdit->text();
    QString Num = QString::number(ui->spinBox->value());
    QString S = "[" + Num + "] -- " + Name;
    serials.addSerial(S);
    ui->comboBox->addItem(S);
    FillTable(model);
    ui->statusBar->showMessage(tr("Serial \"") + Name + "\" (" + Num + ") " + tr(" was added!"), 7000);
}

void MainWindow::on_Hide_triggered()
{
    hide();
}

void MainWindow::on_Exit_triggered()
{
    qApp->quit();
}

void MainWindow::on_toolButton_clicked()
{
    //ui->statusBar->showMessage(tr("YAHO-HO!"));
    QMessageBox::question(0, tr("About"), tr("Copyright © 2012 Kucherov Roman \n\nI hope that most of the rights protected. \nAny criticism, questions, suggestions - \nGladly will read at quoe@mail.ru\n\nP.S: And sorry for my english :("));

    //QFile::setPermissions(dataDir.path() + "//Collection.mcln", QFile::ReadOwner | QFile::WriteOwner);
}

void MainWindow::on_pushButton_9_clicked()
{
    int button = QMessageBox::warning(this,
                 tr("Confirm the deletion"),  //QString::fromLocal8Bit
                 tr("Are you sure you want to delete\n all you viewed serials?"),
                 QMessageBox::Yes | QMessageBox::No);
    if (button == QMessageBox::Yes)
    {
        ui->plainTextEdit->clear();
        saveCollection();
    }
    else return;
}

void MainWindow::on_tableView_clicked(QModelIndex index)    //Щелчёк по TableView
{
    serialIndex = index.row();
    //buf = ui->tableView->model()->data(ui->tableView->model()->index(index.row(),index.column())).toString();
    qDebug() << "Элемент из класса: " + serials.getSerialName(serialIndex) + " " + QString::number(serials.getSerialNum(serialIndex));
    ui->lineEdit->setText(serials.getSerialName(serialIndex));
    ui->spinBox->setValue(serials.getSerialNum(serialIndex));
}

void MainWindow::on_pushButton_3_clicked()  //Удалить
{
    int button = QMessageBox::warning(this,
                 tr("Confirm the deletion"),  //QString::fromLocal8Bit
                 tr("Are you sure you want to delete\n \"") + serials.getSerialName(serialIndex) + "\"?",
                 QMessageBox::Yes | QMessageBox::No);
    if (button == QMessageBox::Yes)
    {
        //ui->statusBar->showMessage("Serial \"" + serials.getSerialName(serialIndex) + "\" was deleted", 7000);
        serials.delSerial(serialIndex);
        qDebug() << "Удалён сериал: " + ui->comboBox->itemText(serialIndex);
        ui->comboBox->removeItem(serialIndex);
        FillTable(model);
        FillEditedCombo();
    }
    else return;
}

void MainWindow::on_pushButton_2_clicked()  //Изменить
{
    QString Name = ui->lineEdit->text();
    QString Num = QString::number(ui->spinBox->value());

    int button = QMessageBox::question(this,
                 tr("Change confirmation"),  //QString::fromLocal8Bit
                 tr("Are you sure you want to change\n \"") + serials.getSerialName(serialIndex) + "\ (" + QString::number(serials.getSerialNum(serialIndex)) + tr(")\non\n") + Name + " (" + Num + ")?",
                 QMessageBox::Yes | QMessageBox::No);
    if (button == QMessageBox::Yes)
    {
        QString pastName = serials.getSerialName(serialIndex);
        QString pastNum = QString::number(serials.getSerialNum(serialIndex));
        QString S = "[" + QString::number(ui->spinBox->value()) + "] -- " + ui->lineEdit->text();
        serials.editSerial(S, serialIndex);
        ui->statusBar->showMessage(tr("Serial \"") + pastName + "\" (" + pastNum + tr(") was changed on\n\"") + Name + "\" (" + Num + ")", 7000);
        FillTable(model);
        FillEditedCombo();
    }
    else return;
}

void MainWindow::on_pushButton_10_clicked() //Серия просмотрена
{
    serials.watched(ui->comboBox->currentIndex());
    FillTable(model);
    FillEditedCombo();
    SetSerial(ui->comboBox->currentIndex());
    if (ui->checkBox_2->isChecked())
    {
        saveSerials();
    }
}

void MainWindow::saveSerials()
{
    QFile file(dataDir.path() + "/data.tns");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Ошибка открытия файла сериалов для сохранения";
    }
    QTextStream out(&file);
    QString S;
    for(int i = 0; i != serials.aSerials.length(); ++i)
    {
        S = "[" + QString::number(serials.getSerialNum(i)) + "] -- " + serials.getSerialName(i);
        out << S + "\n";
        qDebug() << "Сохранена запись " + S;
    }
    ui->statusBar->showMessage(tr("File saved in ") + dataDir.path() + "/data.tns", 7000);
    file.close();
}

void MainWindow::on_pushButton_4_clicked()  //Сохранить
{
    saveSerials();
}

void MainWindow::SetSerial(int index)
{
    if (itemsLoaded & serials.count() > 0)
    {
        settings->setValue("CurrentSerialIndex", index);
        qDebug() << "Просматриваемый сериал: " + QString::number(index) + " [" + QString::number(serials.getSerialNum(index)) + "] -- " + serials.getSerialName(index);
        ui->label_4->setText(serials.setNoticeMessage(index));
        this->setWindowTitle(serials.setWindowsTitle(index));
        ui->statusBar->showMessage(serials.setWindowsTitle(index));
        trayIcon->setToolTip(serials.setWindowsTitle(index));
        if (!ui->checkBox->isChecked())
        {
            trayIcon->showMessage(serials.setWindowsTitle(index), serials.setNoticeMessage(index), QSystemTrayIcon::Information, 0);
        }
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index) //Изменение просмотра сериала
{
    SetSerial(index);
}

void MainWindow::on_pushButton_11_clicked() //Ничего не смотрю
{
    ui->label_4->setText(tr("I tired and don't look anything."));
    settings->setValue("CurrentSerialIndex", -1);
}

void MainWindow::on_comboBox_activated(int index)
{
    SetSerial(index);
}

void MainWindow::saveCollection()
{
    QFile file(dataDir.path() + "/Collection.mcln");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Ошибка открытия файла коллекции для сохранения";
    }
    QTextStream out(&file);
    QString S = ui->plainTextEdit->toPlainText();
    out << S;
    qDebug() << "Сохранена запись " + S;
    //ui->statusBar->showMessage("File saved in " + QCoreApplication::applicationDirPath() + "//Collection.mcln", 7000);
    file.close();
}

void MainWindow::on_pushButton_12_clicked() //Конец сериала
{
    int i = ui->comboBox->currentIndex();
    QString Name = serials.getSerialName(i);
    qDebug() << "Элемент: " + serials.getSerialName(i);
    int button = QMessageBox::warning(this,
                 tr("Confirm the end of the series"),  //QString::fromLocal8Bit
                 tr("Are you sure that it's the end of the series\n \"") + Name + "\"?",
                 QMessageBox::Yes | QMessageBox::No);
    if (button == QMessageBox::Yes)
    {
        qDebug() << QString::number(i) + " Сериал полностью просмотрен: " + ui->comboBox->itemText(i);

        //ui->plainTextEdit->setStyleSheet("font: 8pt \"Arial\";\ntext-decoration: line-through;"); //Зачёркнутый текст

        ui->plainTextEdit->insertPlainText(serials.setMclnText(i));
        //ui->statusBar->showMessage("Serial " + Name + " was added in Viewed!", 7000);
        serials.delSerial(i);
        ui->comboBox->removeItem(i);
        FillTable(model);
        FillEditedCombo();
        saveCollection();
    }
    else return;
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    switch (index)
    {
    case 0:
        if (ui->comboBox->count() > 0)
        {
            ui->statusBar->showMessage(serials.setWindowsTitle(ui->comboBox->currentIndex()));
        }
        else
        {
            ui->statusBar->showMessage(tr("Go to the tab control to add a series"));
        }
        break;
    case 1:
        ui->statusBar->showMessage(tr("You saw ") + QString::number(ui->plainTextEdit->blockCount() - 1) + tr(" serials."));
        break;
    case 2:
        ui->statusBar->showMessage(tr("Type the name of the show in \"Name\" and number on which you are finished watching"));
        break;
    case 3:
        ui->statusBar->showMessage(tr("Files are stored here: ") + dataDir.path());
        break;
    case 4:
        ui->label_6->setText(tr("The program reminders \"") + sCaptionName + "\".\n\n" +
                             tr("This program was created to help avoid \nconfusion in numerous TV series, seasons and \nepisodes. Even to the ninth or eighth season \nwhether serial Friends or regular Pokemon, \nyou could say with certainty that: \nI HAVE STAYED IN THIS SERIES!"));
        ui->statusBar->showMessage(tr("Thanks to all that have installed the program! Even, at least for that."));
    }

}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        QMessageBox::information(0, tr("Information about Dropbox"), tr("Dropbox is a file hosting service operated by Dropbox, Inc. that offers cloud storage, file synchronization, and client software. Dropbox allows users to create a special folder on each of their computers, which Dropbox then synchronises so that it appears to be the same folder (with the same contents) regardless of the computer it is viewed on.<br> <a href=\"www.dropbox.com\">Visit the Web site</a>"));
        return true;
    }
    else {
         // standard event processing
         return QObject::eventFilter(obj, event);
     }
}

void MainWindow::CopyDelete(QString from, QString to)
{
    if (from != to)
    {
        QFile f1(from + "/data.tns");
        QFile::setPermissions(from + "/data.tns", QFile::ReadOwner | QFile::WriteOwner);
        if (!QFile::exists(to + "/data.tns"))
        {
            f1.copy(from + "/data.tns", to + "/data.tns");
            qDebug() << "Файл скопирован из: " + from + "/data.tns" + " в " + to + "/data.tns";
        }
        else
        qDebug() << "Файл data.tns уже существует";
        f1.remove();

        QFile f2(from + "/Collection.mcln");
        QFile::setPermissions(from + "/Collection.mcln", QFile::ReadOwner | QFile::WriteOwner);
        if (!QFile::exists(to + "/Collection.mcln"))
        {
            f2.copy(from + "/Collection.mcln", to + "/Collection.mcln");
            qDebug() << "Файл скопирован из: " + from + "/Collection.mcln" + " в " + to + "/Collection.mcln";
        }
        else
        qDebug() << "Файл Collection.mcln уже существует";
        f2.remove();

        QFile f3(from + "/Settings.ini");
        QFile::setPermissions(from + "/Settings.ini", QFile::ReadOwner | QFile::WriteOwner);
        if (!QFile::exists(to + "/Settings.ini"))
        {
            f3.copy(from + "/Settings.ini", to + "/Settings.ini");
            qDebug() << "Файл скопирован из: " + from + "/Settings.ini" + " в " + to + "/Settings.ini";
        }
        else
        qDebug() << "Файл Settings.ini уже существует";
        f3.remove();

        QDir d1(from);
        d1.rmdir(from);
    }
}

void MainWindow::on_radioButton_3_clicked() //Сохранение в папку по умолчанию
{
    QString S = dataDir.path();
    dataDir.setPath(QCoreApplication::applicationDirPath() + "/tns_data");
    if (!dataDir.exists()) {
        dataDir.mkpath(".");
    }
    PickRadio();
    CopyDelete(S, dataDir.path());
    dataFolder->setValue("dataFolder", dataDir.path());
    ui->statusBar->showMessage(tr("Files are stored here: ") + dataDir.path());
}

void MainWindow::on_radioButton_clicked()   //Сохранение в папку ДропБокс
{
    QDir dropboxDir(QDir::homePath() + "/Dropbox");
    if (dropboxDir.exists())
    {
        QString S = dropboxDir.path();
        dropboxDir.setPath(QDir::homePath() + "/Dropbox/tns_data");
        if (!dropboxDir.exists()) {
            dropboxDir.mkpath(".");
        }
        CopyDelete(dataDir.path(), dropboxDir.path());
        qDebug() << "dataDir.path: " + dataDir.path() + " dropboxDir.path: " + dropboxDir.path();
        dataDir.setPath(dropboxDir.path());
        qDebug() << "dataDir.path: " + dataDir.path() + " dropboxDir.path: " + dropboxDir.path();
        PickRadio();
        dataFolder->setValue("dataFolder", dataDir.path());
        ui->statusBar->showMessage(tr("Files are stored here: ") + QDir::homePath() + tr("/Dropbox"));
    }
    else
    {
        int button = QMessageBox::question(this,
                     tr("Dropbox not found"),  //QString::fromLocal8Bit
                     tr("Check if you have dropbox or select another directory.\nSelect another directory?"),
                     QMessageBox::Yes | QMessageBox::No);
        if (button == QMessageBox::Yes)
        {
            on_radioButton_2_clicked();
            ui->radioButton_2->setChecked(true);
        }
        else
        {
            PickRadio();
            return;
        }

    }
}

void MainWindow::on_radioButton_2_clicked() //Сохранение в собственную папку
{
    QString newDir = QFileDialog::getExistingDirectory(
    this,
    tr("Choose Directory"),
    QDir::homePath(),
    QFileDialog::ShowDirsOnly
    | QFileDialog::DontResolveSymlinks);

    if (newDir == "")
    {
        PickRadio();
        return;
    }
    qDebug() << "Сохранение в собственную папку: " + newDir;
    QString S = dataDir.path();

    dataDir.setPath(newDir + "/tns_data");
    if (!dataDir.exists()) {
        dataDir.mkpath(".");
    }
    CopyDelete(S, dataDir.path());
    dataFolder->setValue("dataFolder", dataDir.path());
    ui->statusBar->showMessage(tr("Files are stored here: ") + dataDir.path());
}


void MainWindow::on_checkBox_clicked()
{
    if (ui->checkBox->isChecked())
    {
        settings->setValue("DontShowNotifications", true);
    }
    else
    {
        settings->setValue("DontShowNotifications", false);
    }
}

void MainWindow::on_checkBox_2_clicked()
{
    if (ui->checkBox_2->isChecked())
    {
        settings->setValue("SaveNumberSeriesAfterViewing", true);
    }
    else
    {
        settings->setValue("SaveNumberSeriesAfterViewing", false);
    }
}

void MainWindow::on_checkBox_3_clicked()
{
    if (ui->checkBox_3->isChecked())
    {
        settings->setValue("ExitWhenClosingForm", true);
        ui->checkBox_4->setEnabled(false);
    }
    else
    {
        settings->setValue("ExitWhenClosingForm", false);
        ui->checkBox_4->setEnabled(true);
    }
}

void MainWindow::on_checkBox_4_clicked()
{
    if (ui->checkBox_4->isChecked())
    {
        settings->setValue("HideNotificationAboutHiding", true);
    }
    else
    {
        settings->setValue("HideNotificationAboutHiding", false);
    }
}

void MainWindow::on_checkBox_5_clicked()
{
    if (ui->checkBox_5->isChecked())
    {
        settings->setValue("SavedOnExit", true);
    }
    else
    {
        settings->setValue("SavedOnExit", false);
    }
}

void MainWindow::on_toolButton_2_clicked()
{
    QMessageBox::information(0, tr("A few words in conclusion"), tr("First, it is always better to have a stable copy of your series and collections. \nSecond, if the program simply takes off, it is best to help remove ini files: DataFolder and Settings. \nThird, like all I could test it, and when the crash bug, either corrected or it was not clear what the breakdown. \nAnd also want to thank the site freeiconsweb.com for his infinite selection of icons and, of course, Dropbox for what it is."));
}
