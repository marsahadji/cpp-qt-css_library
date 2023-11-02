#ifndef CSSSQL_H
#define CSSSQL_H

#include "csscore.h"

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlResult>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlQueryModel>
#include <QSQlRelationalTableModel>
#include <QSqlTableModel>
#include <QSqlError>
#include <QModelIndex>
#include <QSQlField>
#include <QSqlIndex>

#include "csssql_global.h"

namespace CssSql {

//Enums

enum DataType{
    IntType,
    DoubleType,
    ChaineType,
    DateType,
    TimeType,
    DateTimeType,
    BinaryType
};

enum KeyType{
    NoKey,
    PriKey,
    ForKey
};


//Structs

struct CSSSQLSHARED_EXPORT  crudElt
{
    crudElt(){
        field = "";
        value = "";
    }

    crudElt(QString f, QVariant v) : field(f), value(v){}

    QString field;
    QVariant value;
};

struct CSSSQLSHARED_EXPORT  Elmt
{

    Elmt(){
        field = "";
        value = "";
    }

    Elmt(QString f, QVariant v, CssSql::DataType dt, CssSql::KeyType kt) : field(f),
        value(v), fieldType(dt), fieldKeyType(kt){}

    QVariant field;
    QVariant value;
    CssSql::DataType fieldType;
    CssSql::KeyType fieldKeyType;
};

//to establish a connetion to a database
class CSSSQLSHARED_EXPORT  DataConnect
{
public:
    DataConnect();
    bool openDatabase(QString dv, QString db, QString user = "root",
                      QString pass = "root", QString host = "localhost", QString port = "3306");
    bool openDatabase(QString dv, QString db, QString user,
                      QString pass , QString host, QString port, QString connectionName);
    void closeDatabase();

    QSqlDatabase getDatabase();

private:
    QSqlDatabase m_db;

};

class CSSSQLSHARED_EXPORT MasterCrud
{
public:

    explicit MasterCrud(QString table);

    QSqlQuery readValue(crudElt e);

    bool insertValue(QList<crudElt> l);

    bool insertValue();

    bool updateValue(QList<crudElt> l);

    bool updateValue();

    bool deleteValue(crudElt e);

    static bool checkPresence(QString t, crudElt e);

    void setTable(QString t);

    QSqlQuery getQuery();

    QList<crudElt> elementList;

private :
    QString _table;
    QSqlQuery _q;

};

}


class CSSSQLSHARED_EXPORT CssSqlClass
{

public:
    CssSqlClass();
};

#endif // CSSSQL_H
