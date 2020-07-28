#include "serials.h"
#include <QDebug>
#include <QDateTime>
#include <QObject>

Serials::Serials()
{

}

void Serials::addSerial(QString S)
{
    QString sNum = S;
    QString sName = sNum;
    sNum.remove(0, 1);
    sNum.remove(sNum.indexOf("]"), sNum.length());

    sName.remove(0, sName.indexOf("--") + 3);
    sName.remove(sName.length(), 1);

    Serial_Str Serial;
    Serial.sName = sName;
    Serial.nNumber = sNum.toInt();
    aSerials.append(Serial);
}

void Serials::delSerial(int i)
{
    aSerials.removeAt(i);
}

void Serials::editSerial(QString S, int i)
{
    QString sNum = S;
    QString sName = sNum;
    sNum.remove(0, 1);
    sNum.remove(sNum.indexOf("]"), sNum.length());

    sName.remove(0, sName.indexOf("--") + 3);
    sName.remove(sName.length(), 1);

    Serial_Str Serial;
    Serial.sName = sName;
    Serial.nNumber = sNum.toInt();
    aSerials[i] = Serial;
}

int Serials::count()
{
    return aSerials.count();
}

void Serials::watched(int i)
{
    aSerials[i].nNumber++;
}

QString Serials::getSerialName(int i)
{
    return aSerials[i].sName;
}

int Serials::getSerialNum(int i)
{
    return aSerials[i].nNumber;
}

QString Serials::setWindowsTitle(int i)
{
    return QObject::tr("Watch ") + QString::number((aSerials[i].nNumber + 1)) + QObject::tr(" in \"") + aSerials[i].sName + "\"";
}

QString Serials::setNoticeMessage(int i)
{
    return QObject::tr("In the series \n\"") +  aSerials[i].sName + QObject::tr("\"\nyou stop on a series of ") + QString::number(aSerials[i].nNumber) + ".\n" + QObject::tr("So now watch ") +  QString::number(aSerials[i].nNumber + 1) + QObject::tr(" series");
}

QString Serials::setMclnText(int i)
{
    QDateTime dateTime = QDateTime::currentDateTime();
    return QString::number(dateTime.date().day()) + "." + QString::number(dateTime.date().month()) + "." + QString::number(dateTime.date().year()) + " " + dateTime.date().shortDayName(dateTime.date().dayOfWeek()) + " " + dateTime.time().toString() + ": " + aSerials[i].sName + "\n";
}
