#ifndef MI_PRODUCTO
#define MI_PRODUCTO

#include <string>
using namespace std;

class Producto{

    int idProducto;
    char nombreProducto[20];
    int existencias;

    public:
    Producto(int, string, int);
    string obtenerInfoProducto();
};

#endif