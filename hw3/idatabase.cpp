#include "idatabase.h"
#include <QUuid>

void IDatabase::ininDatabase()
{
    database=QSqlDatabase::addDatabase("QSQLITE");
    QString aFile="D:/Lab4/Lab4.db";
    database.setDatabaseName(aFile);

    if(!database.open()){
        qDebug()<<"failed to open database";
    }else
        qDebug()<<"open database is ok";
}

bool IDatabase::initPatientModel()
{
    patienttabModel = new QSqlTableModel(this,database);
    patienttabModel->setTable("patient");
    patienttabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    patienttabModel->setSort(patienttabModel->fieldIndex("name"),Qt::AscendingOrder);
    if(!(patienttabModel->select()))
        return false;
    thePatientSelection = new QItemSelectionModel(patienttabModel);
    return true;
}

int IDatabase::addNewPatient()
{
    patienttabModel->insertRow(patienttabModel->rowCount(),QModelIndex());
    QModelIndex curIndex = patienttabModel->index(patienttabModel->rowCount() - 1,1);

    int curRecNo = curIndex.row();
    QSqlRecord curRec = patienttabModel->record(curRecNo);
    curRec.setValue("CREATEDTIMESTAMP",QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    curRec.setValue("ID",QUuid::createUuid().toString(QUuid::WithoutBraces));

    patienttabModel->setRecord(curRecNo,curRec);

    return curIndex.row();
}

bool IDatabase::searchPatient(QString filter)
{
    patienttabModel->setFilter(filter);
    return patienttabModel->select();
}

bool IDatabase::deleteCurrentPatient()
{
    QModelIndex curIndex = thePatientSelection->currentIndex();
    patienttabModel->removeRow(curIndex.row());
    patienttabModel->submitAll();
    patienttabModel->select();
}

bool IDatabase::submitPatientEdit()
{
    return patienttabModel->submitAll();
}

void IDatabase::reverPatientEdit()
{
    patienttabModel->revertAll();
}

QString IDatabase::userLogin(QString userName, QString password)
{
    //return "loginOK"
    QSqlQuery query;
    query.prepare("select username,password from user where username = :USER");
    query.bindValue(":USER",userName);
    query.exec();
    qDebug()<<query.lastQuery()<<query.first();

    if(query.first() && query.value("username").isValid()){
        QString passwd = query.value("password").toString();
        if(passwd == password){
            qDebug()<<"login ok";
            return "loginOK";
        }else{
            qDebug()<<"wrong password";
            return "wrongPassword";
        }
    }else{
        qDebug()<<"no such user";
        return "wrongUsername";
    }



}

IDatabase::IDatabase(QObject *parent): QObject{parent}
{
    ininDatabase();
}
