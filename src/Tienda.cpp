#include "Tienda.h"
#include "Producto.h"
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

Tienda::~Tienda(){
    for(Producto * producto: this->inventarioTienda){
        delete producto;
    }
}

string Tienda::obtenerInfoTienda(){
    stringstream subOut;
    string out;
    subOut << this->nombreTienda << " " << this->emailTienda << " " << this->direccionTienda << " " << this->telefono;
    out = subOut.str();
    return out;
}

void Tienda::insertarProducto(Producto * producto){
    this->inventarioTienda.push_back(producto);
}

string Tienda::consultarProductos(){
    stringstream subOut;
    string out;
    for(Producto * producto : this->inventarioTienda){
        subOut << producto << "\n";
    }
    out = subOut.str();
    return out;
}