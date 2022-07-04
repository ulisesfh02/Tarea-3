#include <gtest/gtest.h>
#include "../src/Tienda.h"
#include "../src/Producto.h"
#include "../src/ExcepcionModificarProductoInexistente.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

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
    
    TEST(Test_Tienda, Test_InsertarYConsultarProducto){
        /// AAA

        // Arrange - configurar el escenario
        Tienda * tienda = new Tienda("Super Ulises", "superulises@u.com", "Casa de Ulises", "34567345");

        Producto * producto1 = new Producto(1, "Leche", 4);
        Producto * producto2 = new Producto(2, "Galletas", 67);
        
        tienda->insertarProducto(producto1);
        tienda->insertarProducto(producto2);

        // Act - ejecute la operación
        string actual = tienda->consultarProductos();
        string esperada = "1 Leche 4\n2 Galletas 67\n";

        

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);

        delete tienda;
    }

    TEST(Test_Tienda, Test_EliminarYConsultarProducto){
        /// AAA

        // Arrange - configurar el escenario
        Tienda * tienda = new Tienda("Super Ulises", "superulises@u.com", "Casa de Ulises", "34567345");

        Producto * producto1 = new Producto(1, "Leche", 4);
        Producto * producto2 = new Producto(2, "Galletas", 67);
        
        tienda->insertarProducto(producto1);
        tienda->insertarProducto(producto2);

        tienda->eliminarProducto(1);

        // Act - ejecute la operación
        string actual = tienda->consultarProductos();
        string esperada = "2 Galletas 67\n";

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);

        delete tienda;
    }

    TEST(Test_Tienda, Test_ModificarYConsultarProducto){
        /// AAA
        
        // Arrange - configurar el escenario
        Tienda * tienda = new Tienda("Super Ulises", "superulises@u.com", "Casa de Ulises", "34567345");

        Producto * producto1 = new Producto(1, "Leche", 4);
        Producto * producto2 = new Producto(2, "Galletas", 67);
        
        tienda->insertarProducto(producto1);
        tienda->insertarProducto(producto2);

        tienda->modificarProducto(2, "Galletas", 32);

        

        // Act - ejecute la operación
        string actual = tienda->consultarProductos();
        string esperada = "1 Leche 4\n2 Galletas 32\n";

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);

        delete tienda;
    }

    TEST(Calculadora_Test, Test_Modificar_Producto_Inexistente)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tienda = new Tienda();

        // Act - ejecute la operación
        EXPECT_THROW({
            tienda->modificarProducto(1, "Galletas", 34);
        }, ExcepcionModificarProductoInexistente);

        delete tienda;

        // Assert - valide los resultados
    }


    TEST(Test_Tienda, Test_GuardarEnArchivoBinario){
        /// AAA

        // Arrange - configurar el escenario
        Tienda * tienda = new Tienda("Super Ulises", "superulises@u.com", "Casa de Ulises", "34567345");

        Producto * producto1 = new Producto(1, "Leche", 4);
        Producto * producto2 = new Producto(2, "Galletas", 67);
        Producto * producto3 = new Producto(3, "Cereal", 15);
        Producto * producto4 = new Producto(4, "Coca Cola", 45);
        Producto * producto5 = new Producto(5, "Pollo", 9);
        Producto * producto6 = new Producto(6, "Pizza", 33);
        
        
        tienda->insertarProducto(producto1);
        tienda->insertarProducto(producto2);
        tienda->insertarProducto(producto3);
        tienda->insertarProducto(producto4);
        tienda->insertarProducto(producto5);
        tienda->insertarProducto(producto6);

        ofstream archivoSalida;
        archivoSalida.open("productosTienda.dat", ios::out|ios::binary);

        tienda->guardarEnArchivoBinario(&archivoSalida);

        archivoSalida.close();
        

        // Act - ejecute la operación
        string actual = tienda->consultarProductos();
        string esperada = "1 Leche 4\n2 Galletas 67\n3 Cereal 15\n4 Coca Cola 45\n5 Pollo 9\n6 Pizza 33\n";

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);

        delete tienda;
    }

    TEST(Test_Tienda, Test_LeerDesdeArchivoBinario){
        /// AAA

        // Arrange - configurar el escenario
        
        ifstream archivoEntrada;
        archivoEntrada.open("productosTienda.dat", ios::in|ios::binary);

        Tienda *tienda = new Tienda();

        tienda->cargarDesdeArchivoBinario(&archivoEntrada);
        
        // Act - ejecute la operación
        string actual = tienda->consultarProductos();
        string esperada = "1 Leche 4\n2 Galletas 67\n3 Cereal 15\n4 Coca Cola 45\n5 Pollo 9\n6 Pizza 33\n";

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);

        delete tienda;
    }

    TEST(Test_Tienda, Test_GuardarYLeerArchivoBinario ){
        /// AAA

        // Arrange - configurar el escenario
        Tienda * tiendaEsperada = new Tienda("Super Ulises", "superulises@u.com", "Casa de Ulises", "34567345");

        Producto * producto1 = new Producto(4, "Coca Cola", 45);
        tiendaEsperada->insertarProducto(producto1);

        // Escribe arhcivo de prueba
        ofstream archivoSalida;
        archivoSalida.open("tienda_test.dat", ios::out|ios::binary);

        if(!archivoSalida.is_open()){
            cerr << "No se pudo abrir el archivo tienda.dat para escribir los datos";
            FAIL();
        }

        tiendaEsperada->guardarEnArchivoBinario(&archivoSalida);

        archivoSalida.close();

        // Lee archivo de prueba

        ifstream archivoEntrada;
        archivoEntrada.open("tienda_test.dat", ios::in|ios::binary);

        if(!archivoEntrada.is_open()){
            cerr << "No se pudo abrir el archivo tienda.dat para leer los datos";
            FAIL();
        }

        Tienda *tiendaLeida = new Tienda();

        tiendaLeida->cargarDesdeArchivoBinario(&archivoEntrada);
        
        ostringstream streamSalidaTiendaLeida;
        streamSalidaTiendaLeida << tiendaLeida;

        ostringstream streamSalidaTiendaEsperada;
        streamSalidaTiendaEsperada << tiendaEsperada;

        delete tiendaEsperada;
        delete tiendaLeida;

        // Act - ejecute la operación
        string esperada = "Tienda: Super Ulises\nCorreo: superulises@u.com\nDireccion: Casa de Ulises\nTelefono: 34567345\nProductos:\n4 Coca Cola 45\n";
        string salidaTiendaEsperada = streamSalidaTiendaEsperada.str();

        // Assert - valide los resultados
        EXPECT_EQ(esperada, salidaTiendaEsperada);

        string salidaTiendaLeidaDeArchivo = streamSalidaTiendaLeida.str();
        EXPECT_EQ(esperada, salidaTiendaLeidaDeArchivo);
    }
}