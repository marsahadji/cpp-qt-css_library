#ifndef CSSSPACE_H
#define CSSSPACE_H

#include "cssspace_global.h"

#include "csssql.h"
#include "csscore.h"
#include "cssgui.h"

#include <QCoreApplication>
#include <QApplication>
#include <QSettings>
#include <QMainWindow>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>

namespace Css {


struct  infoUser{
    QVariant idUser;
    QVariant categUser;
    QVariant username;

};

namespace AppSettings {

CSSSPACESHARED_EXPORT void writeSettings(QString iniFile, QString group, QString key, QVariant value);
CSSSPACESHARED_EXPORT QVariant readSettings(QString iniFile, QString group, QString key);

}

namespace StringMan {

// empty entry manager
CSSSPACESHARED_EXPORT QString empEnMan(QString s);

//random word
CSSSPACESHARED_EXPORT QVariant randomChar(int size, int type = 1);

//set first letter to Upper
CSSSPACESHARED_EXPORT QString firstUpper(QString s);

//Hashing

CSSSPACESHARED_EXPORT QString chaineHAS(QString s);

//Formating

CSSSPACESHARED_EXPORT QString moneyformatSpace(QString input, QString sep = " ", QString currency =" F");

CSSSPACESHARED_EXPORT QString moneyformatSpace(double input, QString sep = " ", QString currency =" F");

CSSSPACESHARED_EXPORT QString moneyformatSpace(int input, QString sep = " ", QString currency =" F");
}

/*
 * General Functions
 * */

//Every Action
CSSSPACESHARED_EXPORT void actionWriter(QString action, QVariant idUser, QSqlDatabase db = QSqlDatabase::database());

/*
 * Regular Expressions
 * */

//Phone number RegExp
CSSSPACESHARED_EXPORT bool phoneNumberTest(QString s, int n=1, int country=0);

//Name RegExp
CSSSPACESHARED_EXPORT bool nameTest(QString s);

// pattern map for Validator
CSSSPACESHARED_EXPORT QRegularExpression qreval(QString s);

}


class CSSSPACESHARED_EXPORT CssSpaceClass
{

public:
    CssSpaceClass();
};

#endif // CSSSPACE_H
