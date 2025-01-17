#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QMessageBox>
#include "dialog.h"
#include "secdialog.h"
#include "thirddialog.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<string.h>
#include<bitset>
#include"RType.h"
#include"IType.h"
#include"SBType.h"
#include"SType.h"
#include"UJType.h"
#include"UType.h"
#include"RegistryFile.h"
#include"MemoryAccess.h"
#include"Assembler.h"
#include<string>
#include<QTextStream>

using namespace std;

void findLabels(string,vector<string>&,vector<int>&);


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
void MainWindow::paintEvent(QPaintEvent *event)
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

     if(isb.from=="RZ"&&isb.to=="RA")
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
       if(isb.from=="RZ"&&isb.to=="RB")
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
      if(isb.from=="RY"&&isb.to=="RA")
      {
          //line 13,line 12
          if(isb.to=="RA")
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
          if(isb.to=="RB")
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
      }



}

void MainWindow::paint(){

    if(isb.from=="RZ"&&isb.to=="RA")
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
      if(isb.from=="RZ"&&isb.to=="RB")
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
     if(isb.from=="RY"&&isb.to=="RA")
     {
         //line 13,line 12
         if(isb.to=="RA")
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
         if(isb.to=="RB")
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
     }


}

*/
void MainWindow::writeInInputFile(){
    QFile file("C:/Users/hp/Downloads/RISC-V-GUI-master/Project/input.txt");
    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream out(&file);
        QString text = ui->plainTextEdit->toPlainText();
        out<<text;
        file.flush();
        file.close();
        QMessageBox::information(this,"title","Code executed successfully!!");

}
void MainWindow::generateOutputFile(){
    RType rTypeInsObj;
        IType iTypeInsObj;
        SBType sbTypeInsObj;
      SType sTypeInsObj;
        UJType ujTypeInsObj;
        UType uTypeInsObj;

    //    InterStateBuffers isb;

        vector<string> labelNames;
        vector<int> labelLineNumber;

        int insType;
        int lineNo=0;

        string inputFileName = "input1.txt";
        string outputFileName = "machineCode.txt";
        string basicCodeFileName = "basicCode.txt";

        // Directory path to source instruction text files
        string dir = "C:/Users/hp/Downloads/RISC-V-GUI-master/Project/instruction/";

        rTypeInsObj.initialise(dir + "RType.txt");
        iTypeInsObj.initialise(dir + "IType.txt");
        sbTypeInsObj.initialise(dir + "SBType.txt");
      sTypeInsObj.initialise(dir + "SType.txt");
        ujTypeInsObj.initialise(dir + "UJType.txt");
        uTypeInsObj.initialise(dir + "UType.txt");


        MemoryAccess memAccess;

        assembler_initiate(memAccess);

        ifstream iFile("C:/Users/hp/Downloads/RISC-V-GUI-master/Project/input1.txt", ios :: in);
        ofstream oFile("C:/Users/hp/Downloads/RISC-V-GUI-master/Project/machineCode.txt");
        ofstream oFile2("C:/Users/hp/Downloads/RISC-V-GUI-master/Project/basicCode.txt");

        cout<<"\n::::::::::  RISC V SIMULATOR :::::::::::::\n\n"<<endl;

        //Find All Labels in the input file
        findLabels(inputFileName,labelNames,labelLineNumber);

        if(!iFile.is_open())
            cout<<"Error in reading input file";
        else{
            bitset<32> machineCode;
            string line;
            while(getline(iFile,line)) {
                // Skip Label descriptions
                size_t found = line.find(':');
                if(found != string::npos) continue;

                lineNo++;
                // replacing sp with x2
                for(int i=1;i<(line.size()-2);i++){
                    if(line[i]=='s' &&line[i+1]=='p'&&(line[i-1]==' '||line[i-1]==','||line[i-1]=='(')&&(line[i+2]==' ' ||line[i+2]==','||line[i+2]==')'||line[i+2]=='\n')){
                        line[i]='x';
                        line[i+1]='2';
                    }
                }

                // replacing labels
                for(int i=0;i<labelNames.size();i++){
                    size_t found = line.find(labelNames[i]);
                    if(found != string::npos){
                        string newline;
                        for(int j=0;j<found;j++) newline.push_back(line[j]);
                        int offset = labelLineNumber[i] - lineNo -i;
                    //	offset *= 4; // Multiplying offset by 4
                        ostringstream numStr;
                        numStr << offset;
                        string intStr = numStr.str();
                        line = newline + intStr;
                    }
                }

                if(rTypeInsObj.isPresent(line)) {
                    machineCode = rTypeInsObj.decode(line);
                    insType = 1;
                }
                else if(iTypeInsObj.isPresent(line)) {
                    machineCode = iTypeInsObj.decode(line);
                    insType = 2;
                }
                else if(sbTypeInsObj.isPresent(line)) {
                    machineCode = sbTypeInsObj.decode(line);
                    insType = 3;
                }
                else if(sTypeInsObj.isPresent(line)) {
                    machineCode = sTypeInsObj.decode(line);
                    insType = 4;
                }
                else if(ujTypeInsObj.isPresent(line)) {
                    machineCode = ujTypeInsObj.decode(line);
                    insType = 5;
                }
                else if(uTypeInsObj.isPresent(line)) {
                    machineCode = uTypeInsObj.decode(line);
                    insType = 6;
                }
                else {
                    cout<<"Hello\n";
                    cout<<"ERROR !! Instuction not identified : "<<line<<endl;
                    machineCode = bitset<32>(0);
                    insType = -1;
                }
                oFile <<lineNo<<" "<< machineCode <<" "<< insType << endl;
                oFile2 <<lineNo<<" "<< line << endl;
            }
            oFile<<lineNo+1<<" 0 0"<<endl;
            //isb.lines = lineNo;
         //  isb.init_btb();
        }
        iFile.close();
        oFile.close();
        oFile2.close();

}
void MainWindow::on_pushButton_clicked()
{
    writeInInputFile();
    generateOutputFile();
        Dialog first;
        first.setModal(true);
       first.setWindowState(Qt::WindowFullScreen);
        first.exec();

}

void MainWindow::on_pushButton_2_clicked()
{
    writeInInputFile();
    generateOutputFile();
        secDialog sec;
        sec.setModal(true);
       sec.setWindowState(Qt::WindowFullScreen);
        sec.exec();

}

void MainWindow::on_pushButton_3_clicked()
{
    writeInInputFile();
    generateOutputFile();
        thirdDialog third;
        third.setModal(true);
       third.setWindowState(Qt::WindowFullScreen);
        third.exec();

}

void findLabels(string inputFileName, vector<string> &labelNames, vector<int> &labelLineNumber){
    ifstream iFile("C:/Users/hp/Downloads/RISC-V-GUI-master/Project/input1.txt");
    if(iFile.is_open()){
        int lineNo = 0;
        string line;
       // cout<<"Hi\n";
        while(getline(iFile,line)) {

            lineNo++;
            size_t found = line.find(':');
            if(found != string::npos){
                string labelName;
                int i=0;
                while(!isalnum(line[i])) i++;
                while(line[i]!=':' && i<line.size()) labelName.push_back(line[i++]);
                labelNames.push_back(labelName);
                labelLineNumber.push_back(lineNo);
            }
        }
    }
    iFile.close();
}

/*
void MainWindow::on_pushButton2_clicked()
{
    cout<<"******************\n";
                    isb.from="";
                    isb.to="";
                    i++;

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
                            else iag.jumpPC(isb,isb.branch_address);
                            printOnTextEdit();

                        }
                        else
                       printOnTextEdit();
                        updateISB(isb);
                    }
                    else if(i==2) {
                        decode.decoder(isb,rFile);
                        if(isb.from!="" && isb.to!="")
                        {
                            //paintEvent(event);
                          //  paint();
                        }
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
                        if(isb.from!="" && isb.to!="")
                        {
                           // paint();
                            //paintEvent(event);
                        }
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
                        if(isb.from!="" && isb.to!="")
                        {
                           // paint();
                           // paintEvent(event);
                        }
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
                        if(isb.from!="" && isb.to!="")
                        {
                           // paint();
                            //paintEvent(event);
                        }
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
                            else iag.jumpPC(isb,isb.branch_address);
                        }
                        if(end)	{
                            printOnTextEdit();
                            updateISB(isb);
                        }
                    }
                    if(isb.IR.readInt() == 0 )
                        end = true;
                 print(i, isb,rFile);
                 this->repaint();

}
void MainWindow::printOnTextEdit(){
    ui->textEdit->setText(QString::fromStdString(isb.instruction));
    ui->textEdit_2->setText(QString::fromStdString(isb.instructionD));
    ui->textEdit_3->setText(QString::fromStdString(isb.instructionE));
    ui->textEdit_4->setText(QString::fromStdString(isb.instructionM));
    ui->textEdit_5->setText(QString::fromStdString(isb.instructionW));

}
void MainWindow::memory(InterStateBuffers &isb,MemoryAccess &memAccess ,MUX_Y &muxy){
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

void MainWindow::writeBack(InterStateBuffers &isb, RegUpdate &regUpdate, Registry_File &rFile){
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
void MainWindow::updateISB(InterStateBuffers &isb){
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

void MainWindow::print(int i, InterStateBuffers &isb, Registry_File &rFile){
    cout<<"===== < Cycle "<<i<<" > ====="<<endl;
   // if(isb.printRegFile)
        rFile.print();
   // if(isb.printISB)
        isb.printAll();
    cout<<endl;
}

void MainWindow::printSummary(InterStateBuffers &isb){
    cout<<" Total Cycles \t\t\t:\t"<<isb.totalCycles<<endl;
    cout<<" Total Instructions \t\t:\t"<<isb.lines<<endl;
    cout<<" CPI \t\t\t\t:\t"<<((float)isb.totalCycles/isb.lines)<<endl;
    // cout<<" Total Data Transfer Instructions :\t"<<<<endl;
    // cout<<" Total ALU Instructions :\t"<<<<endl;
    // cout<<" Total Control Instructions :\t"<<<<endl;
    cout<<" Total Stalls \t\t\t:\t"<<isb.numStall + isb.mispredNumber*2<<endl;
    cout<<" Number of Data Hazards :\t"<<isb.dataHazardNumber<<endl;
    // cout<<" Number of Control Hazards :\t"<<<<endl;
    cout<<" Total Branch Misprediction \t:\t"<<isb.mispredNumber<<endl;
    cout<<" Stalls due to Data Hazard :\t"<<isb.numStall<<endl;
    cout<<" Stalls due to Control Hazard :\t"<<isb.mispredNumber*2<<endl;
}

void MainWindow::updateAfterDecoder(InterStateBuffers &isb){
    isb.wblocD = isb.write_back_location;
    isb.isjalrD = isb.isjalr;
    isb.isMemD = isb.isMem;
}

void MainWindow::updateIfStall(InterStateBuffers &isb){
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

*/

