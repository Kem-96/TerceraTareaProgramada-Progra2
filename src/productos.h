#ifndef PRODUCTOS_H
#define PRODUCTOS_H

#include <string>
#include <iostream>
using namespace std;

class Productos {

    protected:

    int idProducto; //4
    char nombreProducto[20]; //20 caracteres  
    int existenciasEnTienda; //4 

    public:
    
    Productos(int id, string nombre, int existencias);
    Productos();
    
    //void agregarProductos();
    //void guardar(ostream *streamSalida);
    //string consultar(int id);
    //void Cargar(istream *streamEntrada); // desde stream binario a memoria 
    //void CargarEmpleadoPorPosicionDesdeStreamBinario(istream *streamEntrada, int posicionEmpleado);

    friend ostream& operator << (ostream &o, const Productos *productos);
    friend istream& operator >> (istream &o, Productos *productos);
    


};

#endif