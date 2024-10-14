#pragma once
#include <iostream>
#include "MaterialBibliografico.h"

using namespace std;

class Libro : public MaterialBibliografico
{
    private:
        string fechaPublicacion;
        string resumen;
    public:
        Libro();
        Libro(string, string, string, string, string, string);
        ~Libro();
        string getFecha();
        string getResumen();
        void mostrarInformacion();
};