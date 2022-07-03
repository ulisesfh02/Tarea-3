FLAGS = -g -c --std=c++17

all:
	mkdir -p obj
	mkdir -p bin
	g++ $(FLAGS) src/Tienda.cpp -o obj/Tienda.o
	g++ $(FLAGS) src/Producto.cpp -o obj/Producto.o
	g++ -shared -o bin/libtienda.so obj/Tienda.o obj/Producto.o
	mkdir -p bin/include
	cp src/Tienda.h  src/Producto.h ./bin/include

test:
	mkdir -p obj
	mkdir -p bin
	g++ $(FLAGS) src/Tienda.cpp -o obj/Tienda.o
	g++ $(FLAGS) tests/tests_tienda.cpp -o obj/tests_tienda.o
	g++ $(FLAGS) src/Producto.cpp -o obj/Producto.o
	g++ $(FLAGS) tests/tests_producto.cpp -o obj/tests_producto.o
	g++ -g -o bin/tests obj/tests_tienda.o obj/Tienda.o obj/tests_producto.o obj/Producto.o -lgtest -lgtest_main -lpthread
clean:
	rm -Rf bin
