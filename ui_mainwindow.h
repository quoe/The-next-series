/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 5. Nov 16:47:41 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *Hide;
    QAction *Exit;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QComboBox *comboBox;
    QLabel *label_4;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QWidget *tab_2;
    QPushButton *pushButton_9;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPlainTextEdit *plainTextEdit;
    QWidget *tab_3;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTableView *tableView;
    QWidget *tab_4;
    QGroupBox *groupBox;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout_3;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer;
    QRadioButton *radioButton_2;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget4;
    QGridLayout *gridLayout_4;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QWidget *tab_5;
    QToolButton *toolButton;
    QLabel *label_6;
    QToolButton *toolButton_2;
    QMenuBar *menuBar;
    QMenu *menuLOL;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(491, 372);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/icons/tns.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        Hide = new QAction(MainWindow);
        Hide->setObjectName(QString::fromUtf8("Hide"));
        Hide->setEnabled(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/icons/down_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        Hide->setIcon(icon1);
        Hide->setIconVisibleInMenu(true);
        Exit = new QAction(MainWindow);
        Exit->setObjectName(QString::fromUtf8("Exit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/icons/stop_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        Exit->setIcon(icon2);
        Exit->setIconVisibleInMenu(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 491, 331));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        QFont font;
        font.setStyleStrategy(QFont::PreferDefault);
        tabWidget->setFont(font);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        comboBox = new QComboBox(tab);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 10, 441, 31));
        comboBox->setEditable(true);
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 50, 471, 171));
        label_4->setStyleSheet(QString::fromUtf8("QLabel { font: 27pt \"Arial\"; color: rgb(0, 85, 255); }"));
        label_4->setFrameShape(QFrame::NoFrame);
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 240, 441, 51));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_10 = new QPushButton(layoutWidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/icons/tick_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon3);
        pushButton_10->setIconSize(QSize(32, 32));
        pushButton_10->setAutoDefault(false);
        pushButton_10->setDefault(true);
        pushButton_10->setFlat(false);

        gridLayout->addWidget(pushButton_10, 0, 0, 1, 1);

        pushButton_11 = new QPushButton(layoutWidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/res/icons/block_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon4);
        pushButton_11->setIconSize(QSize(32, 32));
        pushButton_11->setFlat(false);

        gridLayout->addWidget(pushButton_11, 0, 1, 1, 1);

        pushButton_12 = new QPushButton(layoutWidget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/res/icons/flag_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_12->setIcon(icon5);
        pushButton_12->setIconSize(QSize(32, 32));
        pushButton_12->setFlat(false);

        gridLayout->addWidget(pushButton_12, 0, 2, 1, 1);

        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/res/icons/home_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon6, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        pushButton_9 = new QPushButton(tab_2);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(360, 256, 111, 41));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/res/icons/trash_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon7);
        pushButton_9->setIconSize(QSize(32, 32));
        layoutWidget1 = new QWidget(tab_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 461, 241));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(8);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(label);

        plainTextEdit = new QPlainTextEdit(layoutWidget1);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        QFont font2;
        font2.setStrikeOut(false);
        plainTextEdit->setFont(font2);
        plainTextEdit->setStyleSheet(QString::fromUtf8(""));
        plainTextEdit->setReadOnly(true);

        verticalLayout->addWidget(plainTextEdit);

        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/res/icons/search_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_2, icon8, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        layoutWidget2 = new QWidget(tab_3);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(12, 11, 461, 281));
        gridLayout_2 = new QGridLayout(layoutWidget2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit = new QLineEdit(layoutWidget2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_3->addWidget(lineEdit);

        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        spinBox = new QSpinBox(layoutWidget2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(999999);

        horizontalLayout_3->addWidget(spinBox);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 0, 1, 4);

        pushButton = new QPushButton(layoutWidget2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setLayoutDirection(Qt::LeftToRight);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/res/icons/plus_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon9);
        pushButton->setIconSize(QSize(32, 32));
        pushButton->setDefault(true);
        pushButton->setFlat(false);

        gridLayout_2->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setLayoutDirection(Qt::LeftToRight);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/res/icons/pencil_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon10);
        pushButton_2->setIconSize(QSize(32, 32));
        pushButton_2->setFlat(false);

        gridLayout_2->addWidget(pushButton_2, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setLayoutDirection(Qt::LeftToRight);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/res/icons/delete_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon11);
        pushButton_3->setIconSize(QSize(32, 32));
        pushButton_3->setFlat(false);

        gridLayout_2->addWidget(pushButton_3, 1, 2, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setLayoutDirection(Qt::LeftToRight);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/res/icons/save_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon12);
        pushButton_4->setIconSize(QSize(32, 32));
        pushButton_4->setFlat(false);

        gridLayout_2->addWidget(pushButton_4, 1, 3, 1, 1);

        tableView = new QTableView(layoutWidget2);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setShowGrid(true);
        tableView->horizontalHeader()->setCascadingSectionResizes(false);
        tableView->horizontalHeader()->setDefaultSectionSize(103);

        gridLayout_2->addWidget(tableView, 2, 0, 1, 4);

        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/res/icons/monitor_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_3, icon13, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        groupBox = new QGroupBox(tab_4);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(40, 10, 401, 131));
        layoutWidget3 = new QWidget(groupBox);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 20, 316, 110));
        gridLayout_3 = new QGridLayout(layoutWidget3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        radioButton_3 = new QRadioButton(layoutWidget3);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/res/icons/help_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioButton_3->setIcon(icon14);
        radioButton_3->setIconSize(QSize(24, 24));

        gridLayout_3->addWidget(radioButton_3, 0, 0, 1, 1);

        radioButton = new QRadioButton(layoutWidget3);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/res/icons/Dropbox_Logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioButton->setIcon(icon15);
        radioButton->setIconSize(QSize(24, 24));

        gridLayout_3->addWidget(radioButton, 1, 0, 1, 1);

        label_5 = new QLabel(layoutWidget3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("QLabel::hover { color: rgb(0, 85, 255) };\n"
"QLabel {color: rgb(255, 0, 255) };\n"
"QLabe::pressed {color: rgb(255, 170, 127) };\n"
""));

        gridLayout_3->addWidget(label_5, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 2, 1, 1);

        radioButton_2 = new QRadioButton(layoutWidget3);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/res/icons/folder_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioButton_2->setIcon(icon16);
        radioButton_2->setIconSize(QSize(24, 24));

        gridLayout_3->addWidget(radioButton_2, 2, 0, 1, 3);

        groupBox_2 = new QGroupBox(tab_4);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(40, 140, 401, 161));
        layoutWidget4 = new QWidget(groupBox_2);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 20, 381, 132));
        gridLayout_4 = new QGridLayout(layoutWidget4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        checkBox = new QCheckBox(layoutWidget4);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/res/icons/bubble_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        checkBox->setIcon(icon17);
        checkBox->setIconSize(QSize(24, 24));

        gridLayout_4->addWidget(checkBox, 0, 0, 1, 2);

        checkBox_2 = new QCheckBox(layoutWidget4);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/res/icons/briefcase_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        checkBox_2->setIcon(icon18);
        checkBox_2->setIconSize(QSize(24, 24));

        gridLayout_4->addWidget(checkBox_2, 1, 0, 1, 3);

        checkBox_3 = new QCheckBox(layoutWidget4);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setIcon(icon2);
        checkBox_3->setIconSize(QSize(24, 24));

        gridLayout_4->addWidget(checkBox_3, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 2, 1, 1, 1);

        checkBox_4 = new QCheckBox(layoutWidget4);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/res/icons/warning_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        checkBox_4->setIcon(icon19);
        checkBox_4->setIconSize(QSize(24, 24));

        gridLayout_4->addWidget(checkBox_4, 2, 2, 1, 1);

        checkBox_5 = new QCheckBox(layoutWidget4);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/res/icons/present_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        checkBox_5->setIcon(icon20);
        checkBox_5->setIconSize(QSize(24, 24));

        gridLayout_4->addWidget(checkBox_5, 3, 0, 1, 1);

        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/res/icons/gear_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_4, icon21, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        toolButton = new QToolButton(tab_5);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(430, 250, 48, 48));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/res/icons/letter_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon22);
        toolButton->setIconSize(QSize(32, 32));
        label_6 = new QLabel(tab_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 0, 451, 241));
        label_6->setStyleSheet(QString::fromUtf8("QLabel { font: 16pt \"Arial\"; color: rgb(10, 125, 155); }"));
        toolButton_2 = new QToolButton(tab_5);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(380, 250, 48, 48));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/res/icons/key_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon23);
        toolButton_2->setIconSize(QSize(32, 32));
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/res/icons/info_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_5, icon24, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 491, 21));
        menuLOL = new QMenu(menuBar);
        menuLOL->setObjectName(QString::fromUtf8("menuLOL"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuLOL->menuAction());
        menuLOL->addAction(Hide);
        menuLOL->addSeparator();
        menuLOL->addAction(Exit);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);
        comboBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        Hide->setText(QApplication::translate("MainWindow", "Hide", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        Hide->setStatusTip(QApplication::translate("MainWindow", "Hide program", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        Hide->setShortcut(QApplication::translate("MainWindow", "Ctrl+H", 0, QApplication::UnicodeUTF8));
        Exit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        Exit->setStatusTip(QApplication::translate("MainWindow", "Exit completely", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        Exit->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        comboBox->setStatusTip(QApplication::translate("MainWindow", "Select series you're watching", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        label_4->setText(QApplication::translate("MainWindow", "Text.....", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        pushButton_10->setStatusTip(QApplication::translate("MainWindow", "Series looked", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        pushButton_10->setText(QApplication::translate("MainWindow", "Viewed", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        pushButton_11->setStatusTip(QApplication::translate("MainWindow", "None of the series has not looked", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        pushButton_11->setText(QApplication::translate("MainWindow", "Don't look anything", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        pushButton_12->setStatusTip(QApplication::translate("MainWindow", "End of the series (maybe the season)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        pushButton_12->setText(QApplication::translate("MainWindow", "End of the series", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "The next series", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        pushButton_9->setStatusTip(QApplication::translate("MainWindow", "Clear list of viewed serials", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        pushButton_9->setText(QApplication::translate("MainWindow", "Clear List", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Series shown here that you have already seen:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        plainTextEdit->setStatusTip(QApplication::translate("MainWindow", "This shows you all watched TV series", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        plainTextEdit->setDocumentTitle(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Viewed", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        label_2->setStatusTip(QApplication::translate("MainWindow", "Name of serial", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        label_2->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        lineEdit->setStatusTip(QApplication::translate("MainWindow", "Type name", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        lineEdit->setText(QString());
#ifndef QT_NO_STATUSTIP
        label_3->setStatusTip(QApplication::translate("MainWindow", "Number of serial", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_3->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_3->setText(QApplication::translate("MainWindow", "Number", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        spinBox->setStatusTip(QApplication::translate("MainWindow", "Choose number", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_STATUSTIP
        pushButton->setStatusTip(QApplication::translate("MainWindow", "Add new serial", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        pushButton->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        pushButton_2->setStatusTip(QApplication::translate("MainWindow", "Edit serial", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        pushButton_2->setText(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        pushButton_3->setStatusTip(QApplication::translate("MainWindow", "Delete serial", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        pushButton_3->setText(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        pushButton_4->setStatusTip(QApplication::translate("MainWindow", "Save serials", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        pushButton_4->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        tableView->setStatusTip(QApplication::translate("MainWindow", "You serials", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Control", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Where to save", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        radioButton_3->setStatusTip(QApplication::translate("MainWindow", "Save all files in the folder with the executable", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        radioButton_3->setText(QApplication::translate("MainWindow", "Use Defaul folder", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        radioButton->setStatusTip(QApplication::translate("MainWindow", "Save in synchronized folders dropbox", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        radioButton->setText(QApplication::translate("MainWindow", "Use Dropbox folder", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        label_5->setStatusTip(QApplication::translate("MainWindow", "If the folder is already stored files of the program, to display them need to be restarted", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        label_5->setText(QApplication::translate("MainWindow", "(?)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        radioButton_2->setStatusTip(QApplication::translate("MainWindow", "Use your location to save", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        radioButton_2->setText(QApplication::translate("MainWindow", "Use another place for saving serials and collection  files", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "General settings", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        checkBox->setStatusTip(QApplication::translate("MainWindow", "Do not display tray notifications", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        checkBox->setText(QApplication::translate("MainWindow", "Don't show notifications", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        checkBox_2->setStatusTip(QApplication::translate("MainWindow", "When you click the \"Series Viewed\" series is automatically saved", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        checkBox_2->setText(QApplication::translate("MainWindow", "Save number series after viewing", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        checkBox_3->setStatusTip(QApplication::translate("MainWindow", "When the form is closed the program it will not be minimized to tray", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        checkBox_3->setText(QApplication::translate("MainWindow", "Exit when closing form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        checkBox_4->setStatusTip(QApplication::translate("MainWindow", "Do not print a message when closing the program", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        checkBox_4->setText(QApplication::translate("MainWindow", "Hide notification about hiding", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        checkBox_5->setStatusTip(QApplication::translate("MainWindow", "Store all the data on exit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        checkBox_5->setText(QApplication::translate("MainWindow", "Saved on exit", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        toolButton->setStatusTip(QApplication::translate("MainWindow", "A little summary information about me", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        toolButton->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        label_6->setStatusTip(QApplication::translate("MainWindow", "A little summary information", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        label_6->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        toolButton_2->setStatusTip(QApplication::translate("MainWindow", "A couple of tips", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        toolButton_2->setText(QApplication::translate("MainWindow", "Tips", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Info", 0, QApplication::UnicodeUTF8));
        menuLOL->setTitle(QApplication::translate("MainWindow", "TNS", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
