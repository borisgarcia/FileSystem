#include "MasterBlock.h"

MasterBlock::MasterBlock(Archivo * arch, const int tam, int cantB, int first,int sigDisp){
    archivo = arch;
    tamanoBloque = tam;
    cantBloques = cantB;
    primero = first;
    sigDisponible = sigDisp;
}

void MasterBlock::cargar(){
    this->archivo->abrir();
    char * data = archivo->leer(0, tamanoBloque);
    initFromChar(data);
}

void MasterBlock::guardar(){

}

MasterBlock * MasterBlock::charToMasterBlock(char * c){
    int tamB,cantB,first,sigDis = 0;

    int pos = 0;

    memcpy(&tamB, &c[pos], 4);
    pos+=4;
    memcpy(&cantB, &c[pos], 4);
    pos+=4;
    memcpy(&first, &c[pos], 4);
    pos+=4;
    memcpy(&sigDis, &c[pos], 4);
    pos+=4;

    return new MasterBlock(archivo,tamB,cantB,first,sigDis);

}

char * MasterBlock::masterBlockToChar(){
    char * data = new char[tamanoBloque];

    int pos = 0;
    memcpy(&data[pos], &this->tamanoBloque, 4);
    pos+=4;
    memcpy(&data[pos], &this->cantBloques, 4);
    pos+=4;
    memcpy(&data[pos], &this->primero, 4);
    pos+=4;
    memcpy(&data[pos], &this->sigDisponible, 4);
    pos+=4;

    return data;

}

void MasterBlock::initFromChar(char * d){
    int pos = 0;

    /*PRINT ??????*/

    memcpy(&this->tamanoBloque, &d[pos], 4);
    pos+=4;
    memcpy(&this->cantBloques, &d[pos], 4);
    pos+=4;
    memcpy(&this->primero, &d[pos], 4);
    pos+=4;
    memcpy(&this->sigDisponible, &d[pos], 4);
    pos+=4;

}