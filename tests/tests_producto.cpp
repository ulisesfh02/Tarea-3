#include <gtest/gtest.h>
#include "../src/Producto.h"

/*
    string obtenerInfoProducto();
    int obtenerIdProducto();
    void modificarValores(int, string, int);

    friend ostream& operator << (ostream &o, const Producto*);
*/

namespace{

    TEST(Test_Producto, Test_CrearProducto){
        /// AAA

        // Arrange - configurar el escenario
        Producto producto(1, "Hamburguesas", 32);

        // Act - ejecute la operación
        string actual = producto.obtenerInfoProducto();
        string esperada = "1 Hamburguesas 32";

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);
    }
}