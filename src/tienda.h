#ifndef TIENDA_H
#define TIENDA_H

#include "productos.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Tienda {

    protected:

    vector<Productos *> productos;
    char nombreTienda[15]; //15 caracteres
    char direccionInternet[24]; //24 caracteres
    char direccionFisica[24]; // 24 caracteres
    char telefono[8];    //8 caracteres

    public:
    
    Tienda(string nombre, string direccionInternet, string direccionFisica, string telef);
    Tienda();
    //~Tienda();
    void Guardar(ostream *streamSalida);
    string Consultar();
    //void GuardarEnStreamBinario(ostream *streamSalida);
    void CargarDesdeStreamBinario(istream *streamEntrada);
    void CargarPorPosicionDesdeStreamBinario(istream *streamEntrada, int posicion);
    void AgregarProducto(Productos *nuevoProducto);

    friend ostream& operator << (ostream &o, const Tienda *tienda);
    friend istream& operator >> (istream &o, Tienda *tienda);


};

#endif