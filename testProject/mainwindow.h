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

    virtual void paintEvent(QPaintEvent *event);
private slots:
    void on_pushButton_clicked();
    void updateISB(InterStateBuffers &isb);
    void updateAfterDecoder(InterStateBuffers &isb);
    void updateIfStall(InterStateBuffers &isb);
    void memory(InterStateBuffers &isb,MemoryAccess &memAccess ,MUX_Y &muxy);
    void writeBack(InterStateBuffers &isb, RegUpdate &regUpdate, Registry_File &rFile);
    void printOnTextEdit();

private:
    Ui::MainWindow *ui;
    int count;
    int i=0,j=0;
    bool end=false;
    InterStateBuffers isb;
    Registry_File rFile;
    Fetch fetch;
    MUX_Y muxy;
    Decode decode;
    RegUpdate regUpdate;
    MemoryAccess *memAccess;
    ALU alu;
    IAG iag;
    QVector<QStringList>ins;
};
#endif // MAINWINDOW_H
