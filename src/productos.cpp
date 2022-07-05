#include "productos.h"
#include <iostream>
#include <cstring>

Productos::Productos(int id, string nombre, int existencias)
{
    this->idProducto = id;
    strcpy(this->nombreProducto, nombre.c_str());
    this->existenciasEnTienda = existencias;
}

Productos::Productos()
{

}

ostream& operator << (ostream &o, const Productos *producto)
{
    o << "[" << producto->idProducto << "] - " << producto->nombreProducto << " " << producto->existenciasEnTienda;  
    return o;
}