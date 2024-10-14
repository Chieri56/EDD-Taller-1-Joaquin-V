#include <iostream>
#include "MaterialBibliografico.h"

using namespace std;

MaterialBibliografico::MaterialBibliografico(){};
MaterialBibliografico::MaterialBibliografico(string nombre, string isbn, string autor, string tipo)
{
    this -> nombre = nombre;
    this -> isbn = isbn;
    this -> autor = autor;
    this -> prestado = false;
    this -> tipo = tipo;
}
MaterialBibliografico::~MaterialBibliografico(){};
void MaterialBibliografico::mostrarInformacion()
{

};
string MaterialBibliografico::getNombre()
{
    return nombre;
}
string MaterialBibliografico::getIsbn()
{
    return isbn;
}
string MaterialBibliografico::getAutor()
{
    return autor;
}
bool MaterialBibliografico::getPrestado()
{
    return prestado;
}
string MaterialBibliografico::getTipo()
{
    return tipo;
}
void MaterialBibliografico::setPrestado(bool prestado)
{
    this -> prestado = prestado;
}