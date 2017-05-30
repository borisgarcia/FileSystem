#include <iostream>
#include "api.h"
using namespace std;
#include "DiscoVirtual.h"
#include "MasterBlock.h"
#include "Archivo.h"
#include "masterblock.h"

int main()
{
    API * api = new API();

    char * hola = {"Disco Virtual"};
    char * hola1 = {"Mis Documentos"};
    Archivo * archivo = new Archivo(hola,4194304);
  DiscoVirtual * dv = new DiscoVirtual(archivo,4194304,4096);
    dv->formatear(hola);
    api->addRootBloque(dv);

    char * hola2 = {"Descargas"};
    char * hola3 = {"Imagenes"};
    char * hola4 = {"Tarea"};
    char * hola5 = {"Cancion"};
    char * hola6 = {"Guia"};

    char * hola7 = {"PachecoPachecoPachecoPacheco"};
    char * contenido = {"qwerty"};

    char * hola8 = {"Tarea de Estructura de Datos"};
    char * hola9 = {"Tarea de Metodologia de la Investigacion"};
    char * hola10 = {"Tarea de Fisica"};
    char * hola11 = {"Tarea de Sistemas de Innovacion"};
    char * hola12 = {"Tarea de Ecuaciones Diferenciales"};

    api->addBloque(dv,hola4,"Folder",hola2);
    api->addBloque(dv,hola2,"Folder",hola2);
    api->addBloque(dv,hola3,"Folder",hola2);

    api->addBloque(dv,hola4,"Archivo",hola2);
    api->addBloque(dv,hola5,"Archivo",hola2);
    api->addBloque(dv,hola6,"Archivo",hola2);

    vector<BloqueFolder*> lista = dv->listaBloqueFolder;
    BloqueFolder * bf = lista[0];

    api->addData(dv,hola8,bf,contenido);
    api->addData(dv,hola9,bf,contenido);
    api->addData(dv,hola10,bf,contenido);
    api->addData(dv,hola11,bf,contenido);
    api->addData(dv,hola12,bf,hola7);
    //api->dir(dv);
    //api->printRoot();
}
