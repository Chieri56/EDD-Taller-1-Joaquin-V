#pragma once
#include <iostream>

using namespace std;

class MaterialBibliografico
{
    protected:
        string nombre;
        string isbn;
        string autor;
        bool prestado;
        string tipo;
    public:
        MaterialBibliografico();
        MaterialBibliografico(string, string, string, string);
        ~MaterialBibliografico();
        virtual void mostrarInformacion(); 
        string getNombre();
        string getIsbn();
        string getAutor();
        string getTipo();
        bool getPrestado();
        void setPrestado(bool);
};