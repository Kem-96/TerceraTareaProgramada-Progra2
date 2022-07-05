#include "tienda.h"
#include <iostream>
#include <cstring>
Tienda::Tienda(string nombre, string direccionInternet, string direccionFisica, string telef)
{
    strcpy(this->nombreTienda, nombre.c_str());
    strcpy(this->direccionInternet, direccionInternet.c_str());
    strcpy(this->direccionFisica, direccionFisica.c_str());
    strcpy(this->telefono, telef.c_str());

}

Tienda::Tienda()
{

}



void Tienda::AgregarProducto(Productos *nuevoProducto)
{
    this->productos.push_back(nuevoProducto);
}

void Tienda::Guardar(ostream *streamSalida)
{
    for (Productos *producto : this->productos)
    {
        streamSalida->write((char *)producto, sizeof(Productos));
    }
}

void Tienda::CargarPorPosicionDesdeStreamBinario(istream *streamEntrada, int posicion)
{
    streamEntrada->seekg(sizeof(productos) * posicion);

    Productos *producto = new Productos();
    streamEntrada->read((char *)producto, sizeof(Productos));

    this->AgregarProducto(producto);
}

void Tienda::CargarDesdeStreamBinario(istream *streamEntrada)
{
    // Calcule cantidad de registros
    streamEntrada->seekg( 0, std::ios::end );
    int cantidadBytesEnArchivo = streamEntrada->tellg();
    int cantidadEmpleados = cantidadBytesEnArchivo / sizeof(Productos);

    // Leer cada empleado
    streamEntrada->seekg( 0, std::ios::beg ); // Empezar desde el principio del archivo
    for (int indice = 0; indice < cantidadEmpleados; indice++)
    {
        Productos *producto = new Productos();
        streamEntrada->read((char *)producto, sizeof(Productos)); // variable para guardar y cuántos bytes leo

        this->AgregarProducto(producto);
    }
    
}

ostream& operator << (ostream &o, const Tienda *tienda)
{
    o << "Tienda: " << std::endl;

    for (Productos *producto : tienda->productos)
    {
        o << producto << endl;
    }
    
    return o;
}