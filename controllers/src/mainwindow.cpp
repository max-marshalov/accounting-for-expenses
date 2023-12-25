#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->addBtn, SIGNAL(clicked()), this, SLOT(parseData()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::parseData(){
    QString totalString = ui->totalLinedit->text();
    QString categoryString = ui->categoryLineEdit->text();
    QString date = ui->dateWidget->selectedDate().toString();
    ui->statusbar->showMessage(QString("Date: ") + date + QString(" Price: ") + totalString + QString(" Category: ") + categoryString);
    qDebug() <<"Date:" << date<<"Price:"<< totalString << "Category:" << categoryString;
}


