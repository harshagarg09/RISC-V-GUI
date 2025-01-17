#pragma once
#include "thirddialog.h"
#include "ui_thirddialog.h"
#include<QFile>
#include<QMessageBox>
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


thirdDialog::thirdDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::thirdDialog)
{
    ui->setupUi(this);
    this->count = 0;
    decode.initialise();
    isb.enablePipe = true;
    isb.enableDF = true;
    isb.init_btb();
}

thirdDialog::~thirdDialog()
{
    delete ui;
}
void thirdDialog::paintEvent(QPaintEvent *event)
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
/*
    QPainter line17(this);
    line17.drawLine(380,600,480,600);

     QPainter line18(this);
     line18.drawLine(480,600,480,450);

     QPainter line19(this);
     line19.drawLine(480,450,500,450);

     QPainter line20(this);
     line20.drawLine(500,450,500,480);
*/
     QPainter line12(this);
     line12.drawLine(350,620,350,690);

     QPainter line13(this);
     line13.drawLine(100,690,350,690);

     QPainter line21(this);
     line21.drawLine(100,295,300,295);

     QPainter line22(this);
     line22.drawLine(300,295,300,310);

     QPainter line23(this);
     line23.drawLine(100,290,370,290);

    QPainter line24(this);
    line24.drawLine(370,290,370,310);

    QPainter line17(this);
    line17.drawLine(380,600,480,600);

     QPainter line18(this);
     line18.drawLine(480,600,480,450);

     QPainter line19(this);
     line19.drawLine(480,450,500,450);

     QPainter line20(this);
     line20.drawLine(500,450,500,480);
     QPainter line25(this);
      line25.drawLine(350,510,440,510);

      QPainter line26(this);
       line26.drawLine(440,510,440,300);

       QPainter line27(this);
       line27.drawLine(440,300,400,300);

      QPainter line28(this);
       line28.drawLine(400,300,400,310);
       QPainter line29(this);
        line29.drawLine(350,510,200,510);

        QPainter line30(this);
          line30.drawLine(200,510,200,300);

          QPainter line31(this);
           line31.drawLine(200,300,290,300);

          QPainter line32(this);
           line32.drawLine(290,300,290,310);

     for(int i=0;i<isb.from.size();i++){
     if(isb.from[i]=="RZ"&&isb.to[i]=="RA")
      {
          QPainter line29(this);
          QPen linepen(Qt::red);
          linepen.setWidth(5);
          line29.setPen(linepen);
          line29.drawLine(350,510,200,510);

          QPainter line30(this);
          line30.setPen(linepen);
          line30.drawLine(200,510,200,300);

          QPainter line31(this);
          line31.setPen(linepen);
          line31.drawLine(200,300,290,300);

           QPainter line32(this);
          line32.setPen(linepen);
         line32.drawLine(290,300,290,310);
          //line 29,line 30,line 31,line 32
      }
      else
      {
          QPainter line29(this);
           line29.drawLine(350,510,200,510);

           QPainter line30(this);
             line30.drawLine(200,510,200,300);

             QPainter line31(this);
              line31.drawLine(200,300,290,300);

             QPainter line32(this);
              line32.drawLine(290,300,290,310);
      }
       if(isb.from[i]=="RZ"&&isb.to[i]=="RB")
      {
          //line 25,line 26,line 27,line 28
          QPainter line25(this);
          QPen linepen(Qt::red);
          linepen.setWidth(5);
          line25.setPen(linepen);
         line25.drawLine(350,510,440,510);

          QPainter line26(this);
          line26.setPen(linepen);
          line26.drawLine(440,510,440,300);

          QPainter line27(this);
          line27.setPen(linepen);
          line27.drawLine(440,300,400,300);

           QPainter line28(this);
          line28.setPen(linepen);
          line28.drawLine(400,300,400,310);
      }
      else
      {
          QPainter line25(this);
           line25.drawLine(350,510,440,510);

           QPainter line26(this);
            line26.drawLine(440,510,440,300);

            QPainter line27(this);
            line27.drawLine(440,300,400,300);

           QPainter line28(this);
            line28.drawLine(400,300,400,310);

      }
      if(isb.from[i]=="RY")
      {
          //line 13,line 12
          if(isb.to[i]=="RA")
          {
              //line 21,line 22
              QPainter line21(this);
              QPen linepen(Qt::red);
              linepen.setWidth(5);
              line21.setPen(linepen);
              line21.drawLine(100,295,300,295);

              QPainter line22(this);
              line22.setPen(linepen);
              line22.drawLine(300,295,300,310);

          }
          else
          {
               QPainter line21(this);
               line21.drawLine(100,295,300,295);

               QPainter line22(this);
               line22.drawLine(300,295,300,310);
          }
          if(isb.to[i]=="RB")
          {
              //line 23,line 24
              QPainter line23(this);
              QPen linepen(Qt::red);
              linepen.setWidth(5);
              line23.setPen(linepen);
              line23.drawLine(100,290,370,290);

              QPainter line24(this);
              line24.setPen(linepen);
              line24.drawLine(370,290,370,310);
          }
          else
          {
               QPainter line23(this);
               line23.drawLine(100,290,370,290);
              QPainter line24(this);
              line24.drawLine(370,290,370,310);

          }
          QPainter line12(this);
          QPen linepen(Qt::red);
          linepen.setWidth(5);
          line12.setPen(linepen);
          line12.drawLine(350,620,350,690);

          QPainter line13(this);
          line13.setPen(linepen);
            line13.drawLine(100,690,350,690);
      }
      else
      {
          QPainter line12(this);
          line12.drawLine(350,620,350,690);

          QPainter line13(this);
          line13.drawLine(100,690,350,690);

          QPainter line21(this);
          line21.drawLine(100,295,300,295);

          QPainter line22(this);
          line22.drawLine(300,295,300,310);

          QPainter line23(this);
          line23.drawLine(100,290,370,290);

         QPainter line24(this);
         line24.drawLine(370,290,370,310);
      }
      if(isb.from[i]=="RY"&&isb.to[i]=="RMD")
           {
               //line17, line 18, line 19 , line 20
               QPainter line17(this);
               QPen linepen(Qt::red);
               linepen.setWidth(5);
               line17.setPen(linepen);
              line17.drawLine(380,600,480,600);

               QPainter line18(this);
               line18.setPen(linepen);
               line18.drawLine(480,600,480,450);

               QPainter line19(this);
               line19.setPen(linepen);
             line19.drawLine(480,450,500,450);

                QPainter line20(this);
               line20.setPen(linepen);
             line20.drawLine(500,450,500,480);
           }
           else
           {
               QPainter line17(this);
               line17.drawLine(380,600,480,600);

                QPainter line18(this);
                line18.drawLine(480,600,480,450);

                QPainter line19(this);
                line19.drawLine(480,450,500,450);

                QPainter line20(this);
                line20.drawLine(500,450,500,480);
           }
}

}

void thirdDialog::on_pushButton_clicked()
{
    isb.from.clear();
    isb.to.clear();
    i++;
   // isb.fromDataHazard="";

    isb.isMispred = false;
    if(end)
        j++;
    if(j >= 4)
    {
        isb.totalCycles = i-1;
                cout<<"\n\n---------------- Code executed succesfully ----------------\n\n"<<endl;
                cout<<" Final register values :\n";
                rFile.print();
                cout<<" Summary :\n";
                printSummary(isb);
        QMessageBox::information(this,"title","Code executed successfully!!!");
        return;

    }
    if(i==1){
        if(!end){
            fetch.get(isb,rFile);
            if(!isb.hazard_type) iag.update(isb);
            else if(isb.hazard_type == 3){
                                    if(isb.btb[isb.PC-1]) iag.jumpPC(isb,isb.branch_address);
                                    else iag.update(isb);
                                }
            else iag.jumpPC(isb,isb.branch_address);
            printOnTextEdit();

        }
        else
       printOnTextEdit();
        updateISB(isb);
    }
    else if(i==2) {
        decode.decoder(isb,rFile);

        if(isb.stall){
            printOnTextEdit();
            updateIfStall(isb);
            return;
        }
        updateAfterDecoder(isb);
        if(isb.isMispred) iag.jumpPC(isb,isb.nextPC);
        if(!end){
            if(isb.hazard_type == 2){
                iag.jumpPC(isb, isb.branch_address);
            }
            fetch.get(isb,rFile);

            printOnTextEdit();

            updateISB(isb);
            if(!isb.hazard_type) iag.update(isb);
            else if(isb.hazard_type == 3){
                                    if(isb.btb[isb.PC-1]) iag.jumpPC(isb,isb.branch_address);
                                    else iag.update(isb);
                                }
            else iag.jumpPC(isb,isb.branch_address);
        }
        if(end)	{
            printOnTextEdit();
            updateISB(isb);
        }
    }
    else if(i==3) {
        if(!isb.stall) alu.compute(isb);
        decode.decoder(isb,rFile);

        if(isb.stall){
            printOnTextEdit();
            updateIfStall(isb);
            return;
        }
        updateAfterDecoder(isb);
        if(isb.isMispred) iag.jumpPC(isb,isb.nextPC);
        if(!end){
            if(isb.hazard_type == 2){
                iag.jumpPC(isb, isb.branch_address);
            }
            fetch.get(isb,rFile);
            printOnTextEdit();
            updateISB(isb);
            if(!isb.hazard_type) iag.update(isb);
            else if(isb.hazard_type == 3){
                                    if(isb.btb[isb.PC-1]) iag.jumpPC(isb,isb.branch_address);
                                    else iag.update(isb);
                                }
            else iag.jumpPC(isb,isb.branch_address);
        }
        if(end)	{
            printOnTextEdit();
            updateISB(isb);
        }
    }
    else if(i==4) {
        memory(isb, *memAccess, muxy);
        if(!isb.stall) alu.compute(isb);
        decode.decoder(isb,rFile);

        if(isb.stall){
            printOnTextEdit();
            updateIfStall(isb);
            return;
        }
        updateAfterDecoder(isb);
        if(isb.isMispred) iag.jumpPC(isb,isb.nextPC);
        if(!end){
            if(isb.hazard_type == 2){
                iag.jumpPC(isb, isb.branch_address);
            }
            fetch.get(isb,rFile);
            printOnTextEdit();

            updateISB(isb);
            if(!isb.hazard_type) iag.update(isb);
            else if(isb.hazard_type == 3){
                                    if(isb.btb[isb.PC-1]) iag.jumpPC(isb,isb.branch_address);
                                    else iag.update(isb);
                                }
            else iag.jumpPC(isb,isb.branch_address);
        }
        if(end)	{
            printOnTextEdit();

            updateISB(isb);
        }
    }
    else{
        writeBack(isb, regUpdate, rFile);
        memory(isb, *memAccess, muxy);
        if(!isb.stall) alu.compute(isb);
        decode.decoder(isb,rFile);

        if(isb.stall){
            printOnTextEdit();
            updateIfStall(isb);
            return;
        }
        updateAfterDecoder(isb);
        if(isb.isMispred) iag.jumpPC(isb,isb.nextPC);
        if(!end){
            if(isb.hazard_type == 2){
                iag.jumpPC(isb, isb.branch_address);
            }
            fetch.get(isb,rFile);
            printOnTextEdit();
            updateISB(isb);
            if(!isb.hazard_type) iag.update(isb);
            else if(isb.hazard_type == 3){
                                    if(isb.btb[isb.PC-1]) iag.jumpPC(isb,isb.branch_address);
                                    else iag.update(isb);
                                }
            else iag.jumpPC(isb,isb.branch_address);
        }
        if(end)	{
            printOnTextEdit();
            updateISB(isb);
        }
    }
    if(isb.IR.readInt() == 0 )
        end = true;
   // ui->regx1->setText(QString::fromStdString(to_string(bitsetRead(rFile.r[1]))));
 print(i, isb,rFile);
// cout<<rFile.r[1]<<endl;

 this->repaint();
}

void thirdDialog::printOnTextEdit(){

    ui->textEdit->setText(QString::fromStdString(isb.instruction));
    ui->textEdit_2->setText(QString::fromStdString(isb.instructionD));
    ui->textEdit_3->setText(QString::fromStdString(isb.instructionE));
    ui->textEdit_4->setText(QString::fromStdString(isb.instructionM));
    ui->textEdit_5->setText(QString::fromStdString(isb.instructionW));

   // ui->regx1->setText(QString::fromStdString(to_string(rFile.r[1])));
    //if()

}
void thirdDialog::memory(InterStateBuffers &isb,MemoryAccess &memAccess ,MUX_Y &muxy){
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

void thirdDialog::writeBack(InterStateBuffers &isb, RegUpdate &regUpdate, Registry_File &rFile){
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
void thirdDialog::updateISB(InterStateBuffers &isb){
    isb.wblocW = isb.wblocM;
    isb.wblocM = isb.wblocE;
    isb.wblocE = isb.wblocD;

    isb.returnAddW = isb.returnAddM;
    isb.returnAddM = isb.returnAddE;
    isb.returnAddE = isb.returnAddD;
    isb.returnAddD = isb.return_address;

    isb.insTypeW = isb.insTypeM;
    isb.insTypeM = isb.insTypeE;
    isb.insTypeE = isb.insTypeD;
    isb.insTypeD = isb.insType;

    isb.instructionW = isb.instructionM;
        isb.instructionM = isb.instructionE;
        isb.instructionE = isb.instructionD;
        isb.instructionD = isb.instruction;

    isb.isjalrW = isb.isjalrM;
    isb.isjalrM = isb.isjalrE;
    isb.isjalrE = isb.isjalrD;

    isb.isMemW = isb.isMemM;
    isb.isMemM = isb.isMemE;
    isb.isMemE = isb.isMemD;
}

void thirdDialog::print(int i, InterStateBuffers &isb, Registry_File &rFile){
    cout<<"===== < Cycle "<<i<<" > ====="<<endl;
        rFile.print();
        ui->regx0->setText(QString::fromStdString(to_string(rFile.r[0])));
        ui->regx1->setText(QString::fromStdString(to_string(rFile.r[1])));
        ui->regx2->setText(QString::fromStdString(to_string(rFile.r[2])));
        ui->regx3->setText(QString::fromStdString(to_string(rFile.r[3])));
        ui->regx4->setText(QString::fromStdString(to_string(rFile.r[4])));
        ui->regx5->setText(QString::fromStdString(to_string(rFile.r[5])));
        ui->regx6->setText(QString::fromStdString(to_string(rFile.r[6])));
        ui->regx7->setText(QString::fromStdString(to_string(rFile.r[7])));
        ui->regx8->setText(QString::fromStdString(to_string(rFile.r[8])));
        ui->regx9->setText(QString::fromStdString(to_string(rFile.r[9])));
        ui->regx10->setText(QString::fromStdString(to_string(rFile.r[10])));
        ui->regx11->setText(QString::fromStdString(to_string(rFile.r[11])));
        ui->regx12->setText(QString::fromStdString(to_string(rFile.r[12])));
        ui->regx13->setText(QString::fromStdString(to_string(rFile.r[13])));
        ui->regx14->setText(QString::fromStdString(to_string(rFile.r[14])));
        ui->regx15->setText(QString::fromStdString(to_string(rFile.r[15])));
        ui->regx16->setText(QString::fromStdString(to_string(rFile.r[16])));
        ui->regx17->setText(QString::fromStdString(to_string(rFile.r[17])));
        ui->regx18->setText(QString::fromStdString(to_string(rFile.r[18])));
        ui->regx19->setText(QString::fromStdString(to_string(rFile.r[19])));
        ui->regx20->setText(QString::fromStdString(to_string(rFile.r[20])));
        ui->regx21->setText(QString::fromStdString(to_string(rFile.r[21])));
        ui->regx22->setText(QString::fromStdString(to_string(rFile.r[22])));
        ui->regx23->setText(QString::fromStdString(to_string(rFile.r[23])));
        ui->regx24->setText(QString::fromStdString(to_string(rFile.r[24])));
        ui->regx25->setText(QString::fromStdString(to_string(rFile.r[25])));
        ui->regx26->setText(QString::fromStdString(to_string(rFile.r[26])));
        ui->regx27->setText(QString::fromStdString(to_string(rFile.r[27])));
        ui->regx28->setText(QString::fromStdString(to_string(rFile.r[28])));
        ui->regx29->setText(QString::fromStdString(to_string(rFile.r[29])));
        ui->regx30->setText(QString::fromStdString(to_string(rFile.r[30])));
        ui->regx31->setText(QString::fromStdString(to_string(rFile.r[31])));

   // if(isb.printISB)
        isb.printAll();
        ui->regRA->setText(QString::fromStdString(to_string(isb.RA.readInt())));
        ui->regRB->setText(QString::fromStdString(to_string(isb.RB.readInt())));
        ui->regRM->setText(QString::fromStdString(to_string(isb.RM.readInt())));
        ui->regRZ->setText(QString::fromStdString(to_string(isb.RZ.readInt())));
        ui->regRY->setText(QString::fromStdString(to_string(isb.RY.readInt())));


        if(!isb.from.empty()){
        ui->countDH->setText(QString::fromStdString(to_string(isb.dataHazardNumber)));
        ui->DFpaths->setText("");

        for(int i=0;i<isb.from.size();i++){
            ui->DFpaths->append("From "+QString::fromStdString(isb.from[i]) + " to "+QString::fromStdString(isb.to[i]));

        }
      //  ui->countDH->append(QString::fromStdString(to_string(isb.dataHazardNumber)));

        // ui->fromDH->setText(QString::fromStdString(isb.fromDataHazard));
        ui->toDH->setText(QString::fromStdString(isb.instructionE));
}
        else{
            ui->countDH->setText(QString::fromStdString(""));
           // ui->fromDH->setText(QString::fromStdString(isb.fromDataHazard));
            ui->DFpaths->setText("");
            ui->toDH->setText(QString::fromStdString(""));
        }



    cout<<endl;
}

void thirdDialog::printSummary(InterStateBuffers &isb){
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

void thirdDialog::updateAfterDecoder(InterStateBuffers &isb){
    isb.wblocD = isb.write_back_location;
    isb.isjalrD = isb.isjalr;
    isb.isMemD = isb.isMem;
}

void thirdDialog::updateIfStall(InterStateBuffers &isb){
    isb.wblocW = isb.wblocM;
    isb.wblocM = isb.wblocE;
    isb.wblocE = -1;
    isb.insTypeW = isb.insTypeM;
    isb.insTypeM = isb.insTypeE;
    isb.instructionW = isb.instructionM;
     isb.instructionM = isb.instructionE;
    isb.returnAddW = isb.returnAddM;
    isb.returnAddM = isb.returnAddE;
    isb.isjalrW = isb.isjalrM;
    isb.isjalrM = isb.isjalrE;
    isb.isMemW = isb.isMemM;
    isb.isMemM = isb.isMemE;
}



