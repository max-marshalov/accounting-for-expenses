#ifndef DATABASESERVICE_H
#define DATABASESERVICE_H
#include <QString>
#include <QTableWidgetItem>
#include <QtSql>
#include <stdbool.h>
class DataBaseService
{
public:
    DataBaseService();
    void init();
    void close();
    void addItem(QString total, QString category, QString date);
    //    getAllData();
    //    getItemFromName(QString *name);
    //    removeItemFromName(QString *name);
    //    editItemFromName(QString *name);
    //    addItem(QTableWidgetItem *item);
private:
    QSqlDatabase dataBase;



};

#endif // DATABASESERVICE_H
