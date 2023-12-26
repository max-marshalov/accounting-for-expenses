#include "mainwindow.h"
#include "databaseservice.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>
#include <QTableWidgetItem>
#include <QDate>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dataBaseService.init();
    connect(ui->addBtn, SIGNAL(clicked()), this, SLOT(parseData()));

}

MainWindow::~MainWindow()
{
    delete ui;
    dataBaseService.close();
}
void MainWindow::parseData(){
    QString totalString = ui->totalLinedit->text();
    QString categoryString = ui->categoryLineEdit->text();
    QString date = ui->dateWidget->selectedDate().toString("yyyy-MM-dd");
    ui->statusbar->showMessage(QString("Date: ") + date + QString(" Price: ") + totalString + QString(" Category: ") + categoryString);
    qDebug() <<"Date:" << date<<"Price:"<< totalString << "Category:" << categoryString;
    addToTable(totalString, categoryString, date);


}
void MainWindow::addToTable(QString total, QString category, QString date){
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new QTableWidgetItem(date));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, new QTableWidgetItem(category));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2, new QTableWidgetItem(total));
    dataBaseService.addItem(total, category, date);
}


