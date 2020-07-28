#ifndef SERIALS_H
#define SERIALS_H
#include <QString>
#include <QMainWindow>
#include <QList>

class Serials
{
public:
    Serials();
    struct Serial_Str
    {
        QString sName;
        int nNumber;
    };
    QList<Serial_Str> aSerials;
    void addSerial(QString S);
    void delSerial(int i);
    void editSerial(QString S, int i);
    int count();
    void watched(int i);

    QString getSerialName(int i);
    int getSerialNum(int i);

    QString setWindowsTitle(int i);
    QString setNoticeMessage(int i);
    QString setMclnText(int i);
};

#endif // SERIALS_H
