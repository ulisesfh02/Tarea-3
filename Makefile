FLAGS = -g -c --std=c++17

all:
	mkdir -p bin
	g++ $(FLAGS) src/TipoEnvio.cpp -o bin/TipoEnvio.o
	g++ $(FLAGS) src/FedEX.cpp -o bin/FedEX.o
	g++ $(FLAGS) src/ServicioPostal.cpp -o bin/ServicioPostal.o
	g++ $(FLAGS) src/main.cpp -o bin/main.o
	g++ -g -o bin/calcularEnvios bin/TipoEnvio.o bin/FedEX.o bin/ServicioPostal.o bin/main.o
test:
	mkdir -p bin
	g++ $(FLAGS) tests/tests_envio_fedex.cpp -o bin/tests_envio_fedex.o
	g++ $(FLAGS) tests/tests_envio_serviciopostal.cpp -o bin/tests_envio_serviciopostal.o
	g++ $(FLAGS) src/FedEX.cpp -o bin/FedEX.o
	g++ $(FLAGS) src/ServicioPostal.cpp -o bin/ServicioPostal.o
	g++ -g -o bin/tests bin/tests_envio_fedex.o bin/tests_envio_serviciopostal.o bin/FedEX.o bin/ServicioPostal.o -lgtest -lgtest_main -lpthread
clean:
	rm -Rf bin
