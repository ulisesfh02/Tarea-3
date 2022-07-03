#include <gtest/gtest.h>
#include "../src/Producto.h"

/*
    void modificarValores(int, string, int);

    friend ostream& operator << (ostream &o, const Producto*);
*/

namespace{

    TEST(Test_Producto, Test_CrearProducto_ObtenerInfoProducto){
        /// AAA

        // Arrange - configurar el escenario
        Producto *producto= new Producto(1, "Hamburguesas", 32);

        // Act - ejecute la operación
        string actual = producto->obtenerInfoProducto();
        string esperada = "1 Hamburguesas 32";

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);
    }

    TEST(Test_Producto, Test_ObtenerIdProducto){
        /// AAA

        // Arrange - configurar el escenario
        Producto *producto =new Producto(23, "Hamburguesas", 32);

        // Act - ejecute la operación
        int actual = producto->obtenerIdProducto();
        int esperada = 23;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);
    }

    TEST(Test_Producto, Test_ModificarValores){
        /// AAA

        // Arrange - configurar el escenario
        Producto *producto =new Producto(23, "Hamburguesas", 32);

        producto->modificarValores(43, "Papas", 444);

        // Act - ejecute la operación
        string actual = producto->obtenerInfoProducto();
        string esperada = "43 Papas 444";

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);
    }
}