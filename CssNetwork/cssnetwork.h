#ifndef CSSNETWORK_H
#define CSSNETWORK_H

#include "cssnetwork_global.h"


#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>

#include <QVariant>
#include <QTimer>
#include <QDebug>
#include <QRegularExpression>
#include <QRegExp>
#include <QTime>
#include <QDate>
#include <QDateTime>
#include <QFileInfo>
#include <QFile>
#include <QDir>
#include <QProcess>
#include <QCryptographicHash>
#include <QByteArray>
#include <QBuffer>
#include <QSharedMemory>

namespace CssNetwork {

namespace NetworkCalculations {

inline QString makeByteBinary(QString input){
    while(input.size()<8)
        input.prepend("0");
    return input;
}

inline QString maskFromInt(int m){

    QString mask("");

    for (int i = 0; i < 32; ++i) {

        if(m > 0)
            mask+= "1";
        else
            mask+= "0";
        m--;

        if((i+1)% 8 == 0 && i!=31) mask+= ".";
    }

    return mask;
}

inline QString ipDecimalToBinary(QString ipAdr){

    bool ok = false;
    QStringList st = ipAdr.split(".");

    QString ad = "";

    foreach (QString x, st) {
        ad += makeByteBinary(QString::number(x.toInt(&ok, 10),2)) + ".";
    }

    return ad;
}

inline QString ipBinaryToDecimal(QString ipBin){

    bool ok = false;

    QStringList st = ipBin.split(".");
    QString ad = "";

    foreach (QString x, st) {
        ad += QString::number(x.toInt(&ok, 2),10) + ".";
    }

    return ad.remove(ad.size()-1, 1);

}


inline QString deciToBin(QString input){
    bool ok = false;
    return QString::number(input.toInt(&ok, 10),2);
}

inline QString binToDeci(QString input){
    bool ok = false;
    return QString::number(input.toInt(&ok, 2),10);
}

}
}


class CSSNETWORKSHARED_EXPORT CssNetworkClass
{

public:
    CssNetworkClass();
};

#endif // CSSNETWORK_H
