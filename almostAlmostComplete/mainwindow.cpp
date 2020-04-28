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
                    cout<<"ERROR !! Instuction not identified : "<<line<<endl;
                    machineCode = bitset<32>(0);
                    insType = -1;
                }
                int error=1;
                for(int i=0;i<32;i++)
                {	if(machineCode[i]!=-1)
                        error=0;
                }
                if(error){
                    iFile.close();
                    oFile.close();
                    oFile2.close();
                    cout<<"ERROR !! Some parameters missing... :"<<line<<endl;
                    return 0;
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
