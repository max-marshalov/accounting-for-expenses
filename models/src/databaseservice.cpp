#include "databaseservice.h"
#include <QDebug>
#include <QtSql>
#include <QString>
#include <QList>
#include <stdbool.h>
DataBaseService::DataBaseService()
{

}
void DataBaseService ::init(){
    QSqlDatabase dataBase = QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setDatabaseName("expenses.sqlite");
    if(!dataBase.open()){
        qDebug() << dataBase.lastError().text();
    }
    QSqlQuery initQuery;
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

