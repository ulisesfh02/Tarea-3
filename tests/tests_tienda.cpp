#include <gtest/gtest.h>
#include "../src/Tienda.h"
#include "../src/Producto.h"


/*Se cubren los requerimientos de operaciones
(insertar, modificar, eliminar, consultar)
para los productos. La consulta de los productos es
nada más poder listar todos los productos
*/

namespace{

    TEST(Test_Tienda, Test_CrearTienda){
        /// AAA

        // Arrange - configurar el escenario
        Tienda * tienda = new Tienda("Super Ulises", "superulises@u.com", "Casa de Ulises", "34567345");

        // Act - ejecute la operación
        string actual = tienda->obtenerInfoTienda();
        string esperada = "Super Ulises superulises@u.com Casa de Ulises 34567345";

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);

        delete tienda;
    }
    
    TEST(Test_Tienda, Test_InsertarProducto){
        /// AAA

        // Arrange - configurar el escenario
        Tienda * tienda = new Tienda("Super Ulises", "superulises@u.com", "Casa de Ulises", "34567345");

        Producto * producto1 = new Producto(1, "Leche", 4);
        Producto * producto2 = new Producto(2, "Galletas", 67);
        
        tienda->insertarProducto(producto1);
        tienda->insertarProducto(producto2);

        // Act - ejecute la operación
        string actual = tienda->consultarProductos();
        string esperada = "1 Leche 4\n2 Galletas 67";

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);

        delete tienda;
        delete producto1;
        delete producto2;
    }   
}