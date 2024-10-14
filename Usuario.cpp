#pragma once
#include <iostream>
#include "Usuario.h"
#include "MaterialBibliografico.h"

using namespace std;

Usuario::Usuario(){};
Usuario::Usuario(string nombre, string id)
{
    this -> nombre = nombre;
    this -> id = id;
    this -> cantPrestados = 0;
    this -> materialesPrestados;
}
Usuario::~Usuario(){cout<<"Se ha eliminado al usuario"<<endl;};
string Usuario::getNombre()
{
    return nombre;
}
string Usuario::getId()
{
    return id;
}
void Usuario::agregarPrestado(MaterialBibliografico* material)
{
    materialesPrestados[cantPrestados] = material;
    cantPrestados++;
}
MaterialBibliografico* Usuario::borrarPrestado()
{
    for (int i=0; i<cantPrestados; i++)
    {
        cout<<i+1<<". "<<materialesPrestados[i]->getNombre()<<endl;
    }
    int opcion = 0;
    while (opcion<1 || opcion>cantPrestados)
    {
        cout<<"Ingrese numero del libro que desea devolver"<<endl;
        cin>>opcion;
    }
    MaterialBibliografico* material = materialesPrestados[opcion-1];
    cout<<"Se ha devuelto el libro "<<material->getNombre()<<endl;
    materialesPrestados[opcion-1] = nullptr;
    return material;
}
int Usuario::getCantPrestados()
{
    return cantPrestados;
}
