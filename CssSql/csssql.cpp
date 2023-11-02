#include "csssql.h"


CssSqlClass::CssSqlClass()
{
}

namespace CssSql {

//establish connection to database

DataConnect::DataConnect()
{
    m_db = QSqlDatabase();
}

bool DataConnect::openDatabase(QString dv, QString db, QString user, QString pass, QString host,
                               QString port)
{
    QSqlDatabase m_db;

    if(dv == "QMYSQL"){
        m_db = QSqlDatabase::addDatabase(dv);
        m_db.setDatabaseName(db);
        m_db.setUserName(user);
        m_db.setPassword(pass);
        m_db.setHostName(host);
        m_db.setPort(port.toInt());
    }

    //    if(dv == "QODBC"){
    //        m_db = QSqlDatabase::addDatabase(dv);
    //        m_db.setDatabaseName(db);
    //        m_db.setUserName(user);
    //        m_db.setPassword(pass);
    //        Q_UNUSED(host)
    //        Q_UNUSED(port)
    //    }

    return m_db.open();

}

bool DataConnect::openDatabase( QString dv, QString db, QString user,QString pass, QString host,
                                QString port, QString connectionName)
{

    if(dv == "QMYSQL"){
        m_db = QSqlDatabase::addDatabase(dv,connectionName);
        m_db.setDatabaseName(db);
        m_db.setUserName(user);
        m_db.setPassword(pass);
        m_db.setHostName(host);
        m_db.setPort(port.toInt());
    }

    //    QSqlDatabase m_db;
    //    if(dv == "QODBC"){
    //        m_db = QSqlDatabase::addDatabase(dv);
    //        m_db.setDatabaseName(db);
    //        m_db.setUserName(user);
    //        m_db.setPassword(pass);
    //        Q_UNUSED(host)
    //        Q_UNUSED(port)
    //    }

    return m_db.open();
}

void DataConnect::closeDatabase()
{
    m_db.close();
}

QSqlDatabase DataConnect::getDatabase()
{
    return m_db;
}

MasterCrud::MasterCrud(QString table)
{
    _table = table;
}

bool MasterCrud::insertValue(QList<crudElt> l)
{
    QString req = " insert into %1(%2) "
                  " values(%3)";
    QStringList f, v;

    for(int i=0; i < l.size(); i++){
        f << l[i].field;

        if(i != l.size()-1)
            v << "?,";
        else
            v << "?";
    }
    _q.prepare(req.arg(_table, f.join(", "), v.join(" ")));

    for(int i = 0; i < l.size(); i++)
        _q.addBindValue(l[i].value);

    return _q.exec();

}

bool MasterCrud::insertValue()
{
    QString req = " insert into %1(%2) "
                  " values(%3)";
    QStringList f, v;

    for(int i=0; i < elementList.size(); i++){
        f << elementList[i].field;

        if(i != elementList.size()-1)
            v << "?,";
        else
            v << "?";
    }
    _q.prepare(req.arg(_table, f.join(", "), v.join(" ")));

    for(int i = 0; i < elementList.size(); i++)
        _q.addBindValue(elementList[i].value);

    return _q.exec();
}

QSqlQuery MasterCrud::readValue(crudElt e)
{
    QString req = QString("select * from %1").arg(_table);

    if(!e.field.isEmpty())
        req += " where %2 = ?";

    _q.prepare(req);

    if(!e.field.isEmpty())
        _q.addBindValue(e.value);

    return _q;
}

bool MasterCrud::updateValue(QList<crudElt> l)
{
    QString req = " update %1 "
                  " set  %2 "
                  " where %3 = ?";
    QString st="";

    for(int i = 1; i < l.size(); i++){

        if(i != l.size()-1)
            st.append(l[i].field + " =?, ");
        else
            st.append(l[i].field + " =? ");
    }

    _q.prepare(req.arg(_table, st, l[0].field));

    for(int i = 1; i < l.size(); i++)
        _q.addBindValue(l[i].value);
    _q.addBindValue(l[0].value);

    return _q.exec();

}

bool MasterCrud::updateValue()
{
    QString req = " update %1 "
                  " set  %2 "
                  " where %3 = ?";
    QString st="";

    for(int i = 1; i < elementList.size(); i++){

        if(i != elementList.size()-1)
            st.append(elementList[i].field + " =?, ");
        else
            st.append(elementList[i].field + " =? ");
    }

    _q.prepare(req.arg(_table, st, elementList[0].field));

    for(int i = 1; i < elementList.size(); i++)
        _q.addBindValue(elementList[i].value);
    _q.addBindValue(elementList[0].value);

    return _q.exec();
}

bool MasterCrud::deleteValue(crudElt e)
{
    _q.prepare(QString("delete from %1 where %2 = ?").arg(_table, e.field));
    _q.addBindValue(e.value);

    return _q.exec();
}

bool MasterCrud::checkPresence(QString t, crudElt e)
{
    QSqlQuery qr;
    qr.prepare(QString("select count(*) from %1 where %2 = ?").arg(t, e.field));
    qr.addBindValue(e.value);

    qr.exec();

    qr.first();

    return qr.value(0).toInt() > 0;
}

void MasterCrud::setTable(QString t)
{
    _table = t;
    elementList.clear();

}

QSqlQuery MasterCrud::getQuery()
{
    return _q;
}

}
