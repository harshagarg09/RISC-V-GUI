#ifndef REGISTRYFILE_H
#define REGISTRYFILE_H
#pragma once
#include<iostream>
#include "Functions.h"
#include <bitset>
#include <vector>
#define REG_WIDTH 32
using namespace std;

class Registry_File {
private:
        vector < bitset <REG_WIDTH> > registers;

public:
        int r[32];
    Registry_File() {
        for (int i = 0;i<REG_WIDTH;i++) {
            registers.push_back(0);
           // r.push_back(0);
        }

        registers[2] = 200000; // INTIAL VALUE OF STACK POINTER
       // r[2]=200000;
    }

    void writeInt(int index, int value) {
        if (index != 0) {
            registers[index] = value;
           // r[index]=value;
        }
    }

    int readInt( int index ) {
        return bitsetRead(registers[index]);
    }

    void writeBits (int index , bitset <REG_WIDTH> value) {
        if (index != 0) {
            registers[index] = value;
         //   r[index]=value;
        }
    }

    bitset <REG_WIDTH> readBits ( int index) {
        return registers[index];
    }

    void print () {
        for(int i=0;i<32;i++){
            r[i]=bitsetRead(registers[i]);
            cout<<r[i];
        }
        cout << "====== Registry File ======"  <<endl;
        for (int i = 0;i<8;i++) {
            cout <<"Reg "<<i << " - " << bitsetRead(registers[i]) << "\t";
            cout <<"Reg "<<i+8 << " - " << bitsetRead(registers[i+8]) << "\t";
            cout <<"Reg "<<i+16 << " - " << bitsetRead(registers[i+16]) << "\t";
            cout <<"Reg "<<i+24 << " - " << bitsetRead(registers[i+24]) << endl;
        }
        cout<< "============================"<<endl;
    }

};
#endif // REGISTRYFILE_H
