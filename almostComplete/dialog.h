#ifndef DIALOG_H
#define DIALOG_H
#include"RegistryFile.h"
#include <QDialog>
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
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    virtual void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();
    void memory(InterStateBuffers &isb,MemoryAccess &memAccess ,MUX_Y &muxy);
    void writeBack(InterStateBuffers &isb, RegUpdate &regUpdate, Registry_File &rFile);
    void printOnTextEdit();
    void print(int i, InterStateBuffers &isb, Registry_File &rFile);
    void printSummary(InterStateBuffers &isb);

private:
    Ui::Dialog *ui;
    QPaintEvent *event;
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

#endif // DIALOG_H

