#include <iostream>
#include "Libro.h"

using namespace std;

Libro::Libro():MaterialBibliografico(){};
Libro::Libro(string nombre, string isbn, string autor, string fechaPublicacion, string resumen, string tipo) : MaterialBibliografico(nombre, isbn, autor, tipo)
{
    this -> fechaPublicacion = fechaPublicacion;
    this -> resumen = resumen;
}
Libro::~Libro(){cout<<"Se ha devuelto el libro"<<endl;};
string Libro::getFecha()
{
    return fechaPublicacion;
}
string Libro::getResumen()
{
    return resumen;
}
void Libro::mostrarInformacion()
{

}