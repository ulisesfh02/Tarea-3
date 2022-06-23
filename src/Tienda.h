#ifndef MI_TIENDA
#define MI_TIENDA

#include "Producto.h"
#include <string>
#include <vector>
using namespace std;

class Tienda{

    char nombreTienda[15];
    char emailTienda[24];
    char direccionTienda[24];
    char telefono[8];
    vector<Producto *> inventarioTienda;

    public:
    Tienda(string, string, string, string);
    ~Tienda();
    string obtenerInfoTienda();

    void insertarProducto(Producto*);
    string consultarProductos();
};

#endif