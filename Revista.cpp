#include <iostream>
#include "Revista.h"

using namespace std;

Revista::Revista():MaterialBibliografico(){};
Revista::Revista(string nombre, string isbn, string autor, string numeroEdicion, string mesPublicacion, string tipo) : MaterialBibliografico(nombre, isbn, autor, tipo)
{
    this -> numeroEdicion = numeroEdicion;
    this -> mesPublicacion = mesPublicacion;
}
Revista::~Revista(){cout<<"Se ha devuelto la revista"<<endl;};
string Revista::getEdicion()
{
    return numeroEdicion;
}
string Revista::getMes()
{
    return mesPublicacion;
}
void Revista::mostrarInformacion()
{

};