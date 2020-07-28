#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QModelIndex"
#include "QStandardItemModel"
#include <QSystemTrayIcon>

class QMenu; //Forward declaring the QMenu class

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    void createActions();
    void createTrayIcon();
    void closeEvent(QCloseEvent *); // Overriding the window's close event
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    QAction *open;
    QAction *FormHide;
    QAction *watched;
    QAction *close;

private slots:
    void trayIconClicked(QSystemTrayIcon::ActivationReason);
    void PickRadio();
    void FillTable(QStandardItemModel *model);
    void FillCombo();
    void FillEditedCombo();
    void SetSerial(int index);
    void saveSerials();
    void saveCollection();
    bool eventFilter(QObject *obj, QEvent *event);
    void CopyDelete(QString from, QString to);

    void on_pushButton_10_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_tableView_clicked(QModelIndex index);
    void on_pushButton_9_clicked();
    void on_toolButton_clicked();
    void on_Hide_triggered();
    void on_Exit_triggered();
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
    void on_comboBox_currentIndexChanged(int index);
    void on_pushButton_11_clicked();
    void on_comboBox_activated(int index);
    void on_pushButton_12_clicked();
    void on_tabWidget_currentChanged(int index);
    void on_radioButton_clicked();
    void on_radioButton_2_clicked();
    void on_radioButton_3_clicked();
    void on_checkBox_clicked();
    void on_checkBox_2_clicked();
    void on_checkBox_3_clicked();
    void on_checkBox_4_clicked();
    void on_checkBox_5_clicked();
    void on_toolButton_2_clicked();
};

#endif // MAINWINDOW_H
