#include "databaseservice.h"
#include <QDebug>
#include <QtSql>
#include <QDir>
#include <QString>
#include <QList>
#include <stdbool.h>
#include <string.h>
DataBaseService::DataBaseService()
{
}
void DataBaseService ::init(){
    dataBase = QSqlDatabase::addDatabase("QSQLITE");
    QString path = QDir :: homePath() + "/expenses.db";
    dataBase.setDatabaseName(path);
    QSqlQuery initQuery;
    if(!dataBase.open()){
        qDebug() << dataBase.lastError().text();
    }
    QString initString = "CREATE TABLE expenses ("
                         "id integer PRIMARY KEY NOT NULL, "
                         "date VARCHAR(255), "
                         "category VARCHAR(255), "
                         "total VARCHAR(255)"
                         ");";
    bool b = initQuery.exec(initString);
    if(!b){
        qDebug() << initQuery.lastError().text();
    }

}
void DataBaseService :: close(){
    dataBase.close();
    qDebug() << "Data base has been closed";
}
void DataBaseService :: addItem(QString total, QString category, QString date){
    QSqlQuery addQuery;
    addQuery.prepare("INSERT INTO expenses (date, category, total) VALUES(?, ?, ?)");
    addQuery.addBindValue(date);
    addQuery.addBindValue(category);
    addQuery.addBindValue(total);
    bool b = addQuery.exec();

    if(!b){
        qDebug() << addQuery.lastError().text();
    }else{
        dataBase.commit();}

}

