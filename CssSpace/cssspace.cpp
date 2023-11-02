#include "cssspace.h"


CssSpaceClass::CssSpaceClass()
{
}


namespace Css {

//historique action
CSSSPACESHARED_EXPORT void actionWriter(QString action, QVariant idUser, QSqlDatabase db )
{
    QSqlQuery go(db);
    go.prepare("insert into action "
               " set dateHeureAction = now(), libelleAction=?,  idUser = ?");
    go.addBindValue(action);
    go.addBindValue(idUser);
    if(!go.exec()) qDebug() << go.lastError().text() << " not done";
}


/*
 * Expressions regulieres
 * */
//regex telephone
CSSSPACESHARED_EXPORT bool phoneNumberTest(QString s, int n , int country)
{
    QRegularExpression rx;

    if(n == 1)
        rx = QRegularExpression("\\+\\d{1,3} \\d{8,10}");

    if(n ==2 )
        rx = QRegularExpression("(/{0,1}\\+\\d{1,3} \\d{8,10}){1,2}");

    if(n == 3)
        rx = QRegularExpression("(\\+|\\d|\\(|\\s|\\))+");

    if(country == 228)
        rx = QRegularExpression("\\+228 \\d{8}");
    return rx.match(s).hasMatch();
}

//nom et prenoms
CSSSPACESHARED_EXPORT bool nameTest(QString s)
{
    QRegularExpression rx("([a-z]|[A-Z]|[0-9]})+");
    return rx.match(s).hasMatch();
}

//generatrice de validateur basés sur regex
QRegularExpression qreval(QString s)
{
    QRegularExpression rx1("(\\+|\\d|\\(|\\s)+");
    QRegularExpression rx2("([a-z]|[A-Z]|[0-9]|\\s)+");
    QRegularExpression rx3("([a-z]|[A-Z]|[À-ÿ]|\\s|\\.|-|_)+");
    if(s == "alphan")
        return rx2;
    if(s == "contact")
        return rx1;
    else return rx3;
}



QVariant StringMan::randomChar(int size,int type )
{
    QString final="";

    QVector<int> tab;

    if(type==1){
        for(int i =97; i <123; i++)
            tab.push_back(i);
    }

    if(type==2){
        for(int i =48; i <58; i++)
            tab.push_back(i);
    }

    if(type==3){

        for(int i =48; i <123; i++)
            if(!(i > 57 && i<97))
                tab.push_back(i);
    }

    srand(QDateTime::currentMSecsSinceEpoch());

    while (final.size() < size)
        final += (char) (tab[ (rand()%(tab.size()-1))]);

    return QVariant(final);
}

namespace StringMan {

//gestion caracteres vides
QString empEnMan(QString s)
{
    return (s.isEmpty() ? "Non-Spécifié" : s);
}

// hachage
QString chaineHAS(QString s)
{
    return QCryptographicHash::hash(QByteArray(QCryptographicHash::hash(QString("vfibyhzRVBRBF").toUtf8(), QCryptographicHash::Md5) +
                                               QCryptographicHash::hash(s.toUtf8(), QCryptographicHash::Md5)+
                                               QCryptographicHash::hash(QString("vfibBVDBRBF").toUtf8(), QCryptographicHash::Md5)),
                                    QCryptographicHash::Sha1).toHex();
}


CSSSPACESHARED_EXPORT QString firstUpper(QString s)
{
    s[0] = s[0].toUpper();
    return s;
}

CSSSPACESHARED_EXPORT QString moneyformatSpace(QString input, QString sep, QString currency)
{
    QString output = "";
    int navette = 3;

    for (int i = input.size() ; i > 0; --i) {

        output.prepend(input[i-1]);

        navette--;

        if(navette == 0){
            output.prepend(sep);
            navette = 3;
        }
    }

    if(output[0] == sep){
        output = output.remove(0,1);
    }


    return output + " " + currency;
}

CSSSPACESHARED_EXPORT QString moneyformatSpace(double value, QString sep, QString currency)
{
    QString input = QString::number(value, 'f', 0);
    //    QString output = "";
    //    int navette = 3;

    //    for (int i = input.size() ; i > 0; --i) {

    //        output.prepend(input[i-1]);

    //        navette--;

    //        if(navette == 0){
    //            output.prepend(sep);
    //            navette = 3;
    //        }
    //    }

    //    if(output[0] == sep){
    //        output = output.remove(0,1);
    //    }


    //    return output + " " + currency;

    return moneyformatSpace(input, sep, currency);
}

CSSSPACESHARED_EXPORT QString moneyformatSpace(int input, QString sep, QString currency)
{
    double val = input;

    return moneyformatSpace(val, sep, currency);
}

}

namespace AppSettings {

void writeSettings(QString iniFile, QString group, QString key, QVariant value){

    QSettings settings(iniFile, QSettings::IniFormat);

    settings.setIniCodec("UTF-8");

    settings.beginGroup(group);

    settings.setValue(key, value);

    settings.endGroup();
}

QVariant readSettings(QString iniFile, QString group, QString key){

    QSettings settings(iniFile, QSettings::IniFormat);

    settings.setIniCodec("UTF-8");

    settings.beginGroup(group);

    QVariant value = settings.value(key, value);

    settings.endGroup();

    return value;
}


}

}
