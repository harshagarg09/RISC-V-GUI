#pragma once
#include "dialog.h"
#include "ui_dialog.h"
#include<QFile>
#include<QMessageBox>
#include "secdialog.h"
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
#include<QTextStream>

using namespace std;


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->count = 0;
    decode.initialise();
    isb.enablePipe = false;
    isb.enableDF = false;
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::paintEvent(QPaintEvent *event)
{
    QPainter line(this);
    line.drawLine(100,100,100,690);

    QPainter  rect(this);
    rect.drawRect(QRect(300,120,100,100));

    QPainter line1(this);
    line1.drawLine(100,100,350,100);

    QPainter line2(this);
    line2.drawLine(350,100,350,120);

    QPainter line3(this);
    line3.drawLine(320,220,320,250);

    QPainter line4(this);
    line4.drawLine(380,220,380,250);

    QPainter  rect1(this);
    rect1.drawRect(QRect(300,250,30,30));

    QPainter  rect2(this);
    rect2.drawRect(QRect(365,250,30,30));

    QPainter line5(this);
    line5.drawLine(320,280,320,310);

    QPainter line6(this);
    line6.drawLine(380,280,380,310);

    QPainter  rect3(this);
    rect3.drawRect(QRect(280,310,50,40));

    QPainter  rect4(this);
    rect4.drawRect(QRect(360,310,50,40));

    QPainter line7(this);
    line7.drawLine(300,350,320,390);

    QPainter line8(this);
    line8.drawLine(400,350,380,390);

    QPainter  rect5(this);
    rect5.drawRect(QRect(300,390,100,40));

    QPainter line9(this);
    line9.drawLine(350,430,350,460);

    QPainter  rect6(this);
    rect6.drawRect(QRect(320,460,60,40));

    QPainter line10(this);
    line10.drawLine(350,500,350,520);

    QPainter  rect7(this);
    rect7.drawRect(QRect(320,520,60,40));

    QPainter line11(this);
    line11.drawLine(350,560,350,580);

    QPainter  rect8(this);
    rect8.drawRect(QRect(320,580,60,40));

    QPainter line14(this);
    line14.drawLine(380,295,520,295);

    QPainter line15(this);
    line15.drawLine(520,295,520,360);

    QPainter  rect9(this);
    rect9.drawRect(QRect(500,360,60,40));

    QPainter line16(this);
    line16.drawLine(520,400,520,480);

    QPainter  rect10(this);
    rect10.drawRect(QRect(490,480,60,40));

    QPainter line17(this);
    line17.drawLine(380,600,480,600);

     QPainter line18(this);
     line18.drawLine(480,600,480,450);

     QPainter line19(this);
     line19.drawLine(480,450,500,450);

     QPainter line20(this);
     line20.drawLine(500,450,500,480);


          QPainter line29(this);
           line29.drawLine(350,510,200,510);

           QPainter line30(this);
             line30.drawLine(200,510,200,300);

             QPainter line31(this);
              line31.drawLine(200,300,290,300);

             QPainter line32(this);
              line32.drawLine(290,300,290,310);

          QPainter line25(this);
           line25.drawLine(350,510,440,510);

           QPainter line26(this);
            line26.drawLine(440,510,440,300);

            QPainter line27(this);
            line27.drawLine(440,300,400,300);

           QPainter line28(this);
            line28.drawLine(400,300,400,310);


               QPainter line21(this);
               line21.drawLine(100,295,300,295);

               QPainter line22(this);
               line22.drawLine(300,295,300,310);

               QPainter line23(this);
               line23.drawLine(100,290,370,290);
              QPainter line24(this);
              line24.drawLine(370,290,370,310);


          QPainter line12(this);
          line12.drawLine(350,620,350,690);

          QPainter line13(this);
          line13.drawLine(100,690,350,690);


}

void Dialog::on_pushButton_clicked()
{

        i++;
        fetch.get(isb,rFile);
        printOnTextEdit();
        if(isb.IR.readInt() == 0 )
            return;

        decode.decoder(isb,rFile);
        alu.compute(isb);
        memory(isb, *memAccess, muxy);
        writeBack(isb, regUpdate, rFile);
        iag.step(isb,alu);
        isb.resetAll();

        if(isb.printRegFile) print(i,isb,rFile);

    isb.totalCycles = i-1;
    cout<<"\n\n---------------- Code executed succesfully ----------------\n\n"<<endl;
    cout<<" Final register values :\n";
    rFile.print();
    cout<<" Summary :\n";
    printSummary(isb);
}


void Dialog::printOnTextEdit(){

    ui->lineEdit->setText(QString::fromStdString(isb.instruction));
    ui->lineEdit_2->setText(QString::fromStdString(isb.instruction));
    ui->lineEdit_3->setText(QString::fromStdString(isb.instruction));
    ui->lineEdit_4->setText(QString::fromStdString(isb.instruction));
    ui->lineEdit_5->setText(QString::fromStdString(isb.instruction));

}
void Dialog::memory(InterStateBuffers &isb,MemoryAccess &memAccess ,MUX_Y &muxy){
    if(!isb.enablePipe){
            if(isb.isMem == true){
                if(isb.insType == 4){
                    memAccess.writeWord(isb);
                    muxy.MUX_Y_SELECT = 1;
                }
                else {
                    memAccess.readWord(isb);
                    muxy.MUX_Y_SELECT = 2; // for getting register val from memory
                }
        }
        else if(isb.isjalr == true || isb.insType == 5){
            muxy.MUX_Y_SELECT = 3;
        }
        else
            muxy.MUX_Y_SELECT = 1;
        isb.RY.writeInt(muxy.output(isb));
    }
    else{
        if(isb.isMemM == true){
                if(isb.insTypeM == 4){
                    memAccess.writeWord(isb);
                    muxy.MUX_Y_SELECT = 1;
                }
                else {
                    memAccess.readWord(isb);
                    muxy.MUX_Y_SELECT = 2; // for getting register val from memory
                }
        }
        else if(isb.isjalrM == true || isb.insTypeM == 5){
            muxy.MUX_Y_SELECT = 3;
        }
        else
            muxy.MUX_Y_SELECT = 1;
        isb.RY.writeInt(muxy.output(isb));
    }
}

void Dialog::writeBack(InterStateBuffers &isb, RegUpdate &regUpdate, Registry_File &rFile){
    if(!isb.enablePipe){
        if(isb.write_back_location != -1){
            regUpdate.update(isb,rFile, isb.write_back_location);
        }
    }
    else{
        if(isb.wblocW != -1){
            regUpdate.update(isb,rFile, isb.wblocW);
        }
    }
}

void Dialog::print(int i, InterStateBuffers &isb, Registry_File &rFile){
    cout<<"===== < Cycle "<<i<<" > ====="<<endl;
   // if(isb.printRegFile)
        rFile.print();
   // if(isb.printISB)
        isb.printAll();
    cout<<endl;
}

void Dialog::printSummary(InterStateBuffers &isb){
	cout<<" Total Cycles \t\t\t\t\t:\t"<<isb.totalCycles<<endl;
	cout<<" Total Instructions in Code \t\t\t:\t"<<isb.lines<<endl;
	cout<<" Total Instructions Fetched \t\t\t:\t"<<isb.instFetchNumber<<endl;
	cout<<" CPI \t\t\t\t\t\t:\t"<<((float)isb.totalCycles/isb.instFetchNumber)<<endl;
	cout<<" Total Data Transfer Instructions Fetched \t:\t"<<isb.dataInstNumber<<endl;
	cout<<" Total ALU Instructions Fetched \t\t:\t"<<isb.aluInstNumber<<endl;
	cout<<" Total Control Instructions Fetched\t\t:\t"<<isb.ctrlInstNumber<<endl;
	cout<<" Total Stalls \t\t\t\t\t:\t"<<isb.numStall + isb.mispredNumber<<endl;
	cout<<" Number of Data Hazards \t\t\t:\t"<<isb.dataHazardNumber<<endl;
	cout<<" Number of Control Hazards \t\t\t:\t"<<isb.mispredNumber<<endl;
	cout<<" Total Branch Misprediction \t\t\t:\t"<<isb.mispredNumber<<endl;
	cout<<" Stalls due to Data Hazard \t\t\t:\t"<<isb.numStall<<endl;
	cout<<" Stalls due to Control Hazard \t\t\t:\t"<<isb.mispredNumber<<endl;
}
