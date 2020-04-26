#ifndef REGUPDATE_H
#define REGUPDATE_H
#pragma once
#include "RegistryFile.h"
#include "InterStateBuffers.h"

class RegUpdate {
public:
    void update (InterStateBuffers & buffer, Registry_File & Reg,int destination ) { //
        Reg.writeInt( destination, buffer.RY.readInt() );
    }
};
#endif // REGUPDATE_H
