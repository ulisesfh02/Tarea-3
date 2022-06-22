FLAGS = -g -c --std=c++17

all:
	mkdir -p bin
	g++ $(FLAGS) src/Tienda.cpp -o bin/Tienda.o
	g++ -g -o bin/calcularEnvios bin/Tienda.o
test:
	mkdir -p bin
	g++ $(FLAGS) tests/tests_tienda.cpp -o bin/tests_tienda.o
	g++ $(FLAGS) src/Tienda.cpp -o bin/Tienda.o
	g++ -g -o bin/tests bin/tests_tienda.o bin/Tienda.o -lgtest -lgtest_main -lpthread
clean:
	rm -Rf bin
