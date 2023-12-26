#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "databaseservice.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void parseData();

private:
    Ui::MainWindow *ui;
    DataBaseService dataBaseService;
    void addToTable(QString total, QString category, QString date);

};
#endif // MAINWINDOW_H
