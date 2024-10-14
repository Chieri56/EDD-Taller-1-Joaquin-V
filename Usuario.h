#pragma once
#include <iostream>
#include "MaterialBibliografico.h"

using namespace std;

class Usuario
{
    private:
        string nombre;
        string id;
        MaterialBibliografico* materialesPrestados[5];
        int cantPrestados;
    public:
        Usuario();
        Usuario(string, string);
        ~Usuario();
        void agregarPrestado(MaterialBibliografico*);
        MaterialBibliografico* borrarPrestado();
        string getNombre();
        string getId();
        int getCantPrestados();
};