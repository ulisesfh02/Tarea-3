#ifndef MI_TIENDA
#define MI_TIENDA

#include <string>
using namespace std;

class Tienda{

    char nombreTienda[15];
    char emailTienda[24];
    char direccionTienda[24];
    char telefono[8];

    public:
    Tienda(string, string, string, string);
    string getInfoTienda();
};

#endif