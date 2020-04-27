#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<iostream>
#include<fstream>
#include<sstream>
#include<string.h>
#include<bitset>
#include"ALU.h"
#include"IAG.h"
#include"Decode.h"
#include"Fetch.h"
#include"MUX_Y.h"
#include"RegistryFile.h"
#include"RegUpdate.h"
#include"MemoryAccess.h"
#include"InterStateBuffers.h"
#include<string>
#include<QFile>
#include<QTextStream>
#include <QMainWindow>
#include <QPainter>

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
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();
    void writeInInputFile();
    void generateOutputFile();
private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
