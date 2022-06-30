#include "Tienda.h"
#include "Producto.h"
#include <cstring>
#include <sstream>
using namespace std;

Tienda::Tienda(){
    strcpy(this->nombreTienda, "");
    strcpy(this->emailTienda, "");
    strcpy(this->direccionTienda, "");
    strcpy(this->telefono, "");
}

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

void Tienda::eliminarProducto(int idProducto){
    int inventario= this->inventarioTienda.size();
    for(int i=0; i < inventario; i++){
        if(this->inventarioTienda[i]->obtenerIdProducto() == idProducto){
            this->inventarioTienda.erase(this->inventarioTienda.begin()+i);
            return;
        }
    }
}

void Tienda::modificarProducto(int idProducto, string nombreProducto, int existencias){
    int inventario= this->inventarioTienda.size();
    for(int i=0; i < inventario; i++){
        if(this->inventarioTienda[i]->obtenerIdProducto() == idProducto){
            this->inventarioTienda[i]->modificarValores(idProducto, nombreProducto, existencias);
            return;
        }
    }
}

string Tienda::consultarProductos(){
    stringstream subOut;
    string out;
    for(Producto * producto : this->inventarioTienda){
        subOut << producto << endl;
    }
    out = subOut.str();
    return out;
}

void Tienda::guardarEnArchivoBinario(ostream* streamSalida){
    streamSalida->write((char *)this , sizeof(Tienda)-sizeof(vector<Producto>)-1);
    for(Producto *producto : this->inventarioTienda){
        streamSalida->write((char *)producto, sizeof(Producto));
    }
}
    
void Tienda::cargarDesdeArchivoBinario(istream* streamEntrada){
    
    streamEntrada->seekg(0, ios::end);
    int tamanioArchivo = streamEntrada->tellg();
    tamanioArchivo-=(sizeof(Tienda)-sizeof(vector<Producto>)-1);
    int cantidadProductos = tamanioArchivo / sizeof(Producto);
    streamEntrada->seekg(0, ios::beg);

    streamEntrada->read((char *)this, sizeof(Tienda)-sizeof(vector<Producto>)-1);

    for(int i=0; i < cantidadProductos; i++){
        Producto *producto = new Producto();
        streamEntrada->read((char *)producto, sizeof(Producto));

        this->insertarProducto(producto);
    }

}