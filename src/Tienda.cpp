#include "Tienda.h"
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

Tienda::Tienda(string nombreTienda, string emailTienda, string direccionTienda, string telefono){
    strcpy(this->nombreTienda, nombreTienda.c_str());
    strcpy(this->emailTienda, emailTienda.c_str());
    strcpy(this->direccionTienda, direccionTienda.c_str());
    strcpy(this->telefono, telefono.c_str());
}

string Tienda::obtenerInfoTienda(){
    stringstream subOut;
    string out;
    subOut << this->nombreTienda << " " << this->emailTienda << " " << this->direccionTienda << " " << this->telefono;
    out = subOut.str();
    return out;
}