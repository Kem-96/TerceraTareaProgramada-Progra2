FLAGS = -g -c --std=c++17

all:
	mkdir -p obj
	mkdir -p bin
	g++ $(FLAGS) src/tienda.cpp -o obj/tienda.o 
	g++ $(FLAGS) src/productos.cpp  -o obj/productos.o 
	g++ -shared -o bin/libtienda.so obj/tienda.o
	mkdir -p bin/include
	cp src/tienda.h ./bin/include src/productos.h ./bin/include
	
test:
	mkdir -p obj
	mkdir -p bin
	g++ $(FLAGS) src/tienda.cpp -o obj/tienda.o 
	g++ $(FLAGS) src/productos.cpp -o obj/productos.o
	g++ $(FLAGS) tests/tienda_test.cpp -o obj/tienda_test.o
	g++ -g -o bin/test obj/tienda.o obj/tienda_test.o obj/productos.o -lgtest -lgtest_main -lpthread 

clean:
	rm -Rf bin