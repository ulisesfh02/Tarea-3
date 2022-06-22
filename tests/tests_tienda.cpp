#include <gtest/gtest.h>
#include "../src/Tienda.h"

namespace{

    TEST(Test_Tienda, Test_CrearTienda){
        /// AAA

        // Arrange - configurar el escenario
        Tienda tienda("Super Ulises", "superulises@u.com", "Casa de Ulises", "34567345");

        // Act - ejecute la operación
        string actual = tienda.obtenerInfoTienda();
        string esperada = "Super Ulises superulises@u.com Casa de Ulises 34567345";

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);
    }
    /*
    TEST(Test_Tienda, Test_CrearTienda){
        /// AAA

        // Arrange - configurar el escenario
        Tienda tienda("Super Ulises", "superulises@u.com", "Casa de Ulises", "34567345");

        // Act - ejecute la operación
        string actual = tienda.obtenerInfoTienda();
        string esperada = "Super Ulises superulises@u.com Casa de Ulises 34567345";

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);
    }
    */   
}