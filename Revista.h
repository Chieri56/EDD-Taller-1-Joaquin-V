#pragma once
#include <iostream>
#include "MaterialBibliografico.h"

using namespace std;

class Revista: public MaterialBibliografico
{
    private:
        string numeroEdicion;
        string mesPublicacion;
    public:
        Revista();
        Revista(string, string, string, string, string, string);
        ~Revista();
        string getEdicion();
        string getMes();
        void mostrarInformacion();
};