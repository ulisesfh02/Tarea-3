#include "Producto.h"
#include <cstring>
#include <sstream>
using namespace std;

Producto::Producto(int idProducto, string nombreProducto, int existencias){
    this->idProducto= idProducto;
    strcpy(this->nombreProducto, nombreProducto.c_str());
    this->existencias= existencias;
}

string Producto::obtenerInfoProducto(){
    string out="";
    stringstream outStream;
    outStream << this->idProducto << " " << this->nombreProducto << " " << this->existencias;
    out= outStream.str();
    return out;
}