#include <iostream>
#include <fstream>
#include "MaterialBibliografico.cpp"
#include "Libro.cpp"
#include "Revista.cpp"
#include "Usuario.cpp"

using namespace std;

int menu();
void agregarMaterial(MaterialBibliografico* b[100]);
void informacionBiblioteca(MaterialBibliografico* biblioteca[100]);
static int bibl = 0;
MaterialBibliografico* buscarMaterial(MaterialBibliografico* biblioteca[100], bool t);
void prestarDevolver(MaterialBibliografico* biblioteca[100], Usuario* user);
void gestionUsuarios(Usuario* usuarios[5]);
Usuario* login(Usuario* usuarios[5]);
static int usrs = 0;
void escribir();
//void lectura();

int main()
{   
    MaterialBibliografico* biblioteca[100];
    Usuario* usuarios[5];
    escribir();
    //lectura();

    while (true)
    {   
        int opcion = menu();
        if (opcion==6)
        {   
            cout<<"Terminando ejecucion..."<<endl;
            exit(1);
        }
        switch (opcion)
        {
        case 1:
            agregarMaterial(biblioteca);
            break;
        case 2:
            informacionBiblioteca(biblioteca);
            break;
        case 3:
            buscarMaterial(biblioteca, false);
            break;
        case 4:
            if (usrs>0)
            {   
                Usuario* usr = login(usuarios);
                if (usr!=nullptr)
                {
                    prestarDevolver(biblioteca, usr);
                }
            }
            else
            {
                cout<<"No hay ningun usuario"<<endl;
            }
            break;
        case 5:
            gestionUsuarios(usuarios);
            break;
        }
    }

    return 0;
}

int menu() 
{   
    int opcion = 0;
    while (opcion<1 || opcion>6)
    {   
        cout<<"1. Agregar material a la biblioteca"<<endl;
        cout<<"2. Mostrar informacion de los materiales"<<endl;
        cout<<"3. Buscar material"<<endl;
        cout<<"4. Prestar y devolver material"<<endl;
        cout<<"5. Gestion de usuario"<<endl;
        cout<<"6. Terminar ejecucion"<<endl;
        cout<<"Ingrese numero de la opcion"<<endl;
        cin>>opcion;
        cout<<endl;
    }
    return opcion;
}

void agregarMaterial(MaterialBibliografico* biblioteca[100])
{
    string tipo, nombre, isbn, autor, fechaPublicacion, resumen, numeroEdicion, mesPublicacion;

    while (true)
    {   
        cout<<"Libro o Revista"<<endl;
        cin>>tipo;
        while (tipo!="Libro" && tipo!="Revista")
        {
            cout<<"Libro o Revista"<<endl;
            cin>>tipo;
        }
        cout<<"Nombre"<<endl;
        cin>>nombre;
        cout<<"isbn"<<endl;
        cin>>isbn;
        cout<<"Autor"<<endl;
        cin>>autor;
        if (tipo=="Libro")
        {
            cout<<"Fecha de publicacion (dia/mes/año)"<<endl;
            cin>>fechaPublicacion;
            cout<<"Resumen"<<endl;
            cin>>resumen;
            cout<<endl;
        }
        else
        {
            cout<<"Numero de edicion"<<endl;
            cin>>numeroEdicion;
            cout<<"Mes de publicacion"<<endl;
            cin>>mesPublicacion;
            cout<<endl;
        }
        break;
    }

    if (tipo=="Libro" && bibl<100)
    {
        biblioteca[bibl] = new Libro(nombre, isbn, autor, fechaPublicacion, resumen, tipo);
        bibl++;
    }
    else if (tipo=="Revista" && bibl<100)
    {
        biblioteca[bibl] = new Revista(nombre, isbn, autor, numeroEdicion, mesPublicacion, tipo);
        bibl++;
    }
    else
    {
        cout<<"Biblioteca llena"<<endl;
    }
}

void informacionBiblioteca(MaterialBibliografico* biblioteca[100])
{
    for (int i=0;i<bibl;i++)
    {   
        MaterialBibliografico* mat = biblioteca[i];
        cout<<"Nombre: "<<mat->getNombre()<<", isbn: "<<mat->getIsbn()<<", Autor: "<<mat->getAutor();
        if (mat->getTipo()=="Libro")
        {   
            Libro* l = static_cast<Libro*>(mat);
            cout<<", Fecha: "<<l->getFecha()<<", Resumen: "<<l->getResumen()<<endl;
        }
        else
        {
            Revista* r = static_cast<Revista*>(mat);
            cout<<", Num edicion: "<<r->getEdicion()<<", Mes de publicacion: "<<r->getMes()<<endl;
        }
    }
    cout<<endl;
}

MaterialBibliografico* buscarMaterial(MaterialBibliografico* biblioteca[100], bool t)
{
    MaterialBibliografico* material;
    MaterialBibliografico* validos[100];
    int j=0;
    string nombre, autor;
    int opcion = 0;
    while (opcion<1 || opcion>2)
    {
        cout<<"Seleccione opcion"<<endl;
        cout<<"1. Buscar por titulo"<<endl;
        cout<<"2. Buscar por autor"<<endl;
        cin>>opcion;
        cout<<endl;
    }
    switch (opcion)
    {
    case 1:
        cout<<"Titulo a buscar: ";
        cin>>nombre;
        cout<<endl;
        for (int i=0; i<bibl;i++)
        {
            if (biblioteca[i]->getNombre()==nombre) 
            {
                cout<<j<<". "<<biblioteca[i]->getNombre()<<", "<<biblioteca[i]->getIsbn()<<", "<<biblioteca[i]->getIsbn()<<endl;
                validos[j] = biblioteca[i];
                j++;
            }
        }
        break;
    
    case 2:
        cout<<"Autor a buscar: ";
        cin>>autor;
        cout<<endl;
        for (int i=0; i<bibl;i++)
        {
            if (biblioteca[i]->getAutor()==autor) 
            {
                cout<<j<<". "<<biblioteca[i]->getNombre()<<", "<<biblioteca[i]->getIsbn()<<", "<<biblioteca[i]->getIsbn()<<endl;
                validos[j] = biblioteca[i];
                j++;
            }
        }
        break;
    
    default:
        break;
    }

    if (t==true)
    {
        int num = 0;
        if (j==0)
        {
            return nullptr;
        }
        while (num<=0 || num>j)
        {
            cout<<endl;
            cout<<"Seleccione numero del libro/revista"<<endl;
            for (int i=0; i<j; i++)
            {
                cout<<i+1<<". "<<validos[i]->getNombre()<<", "<<validos[i]->getAutor()<<endl;
            }
            cin>>num;
            cout<<endl;
        }
        num -= 1;
        material = validos[num];
        return material;
    }
    else
    {
        return nullptr;
    }
}

void prestarDevolver(MaterialBibliografico* biblioteca[100], Usuario* user)
{
    int opcion = 0;
    while (opcion<1 || opcion>2)
    {
        cout<<"Seleccione opcion"<<endl;
        cout<<"1. Tomar prestado"<<endl;
        cout<<"2. Devolver"<<endl;
        cin>>opcion;
        cout<<endl;
    }


    if (opcion==1)
    {
        MaterialBibliografico* mat = buscarMaterial(biblioteca, true);
        if (mat->getPrestado()==false && mat!= nullptr)
        {
            mat->setPrestado(true);
            user->agregarPrestado(mat);
        }
        else if (mat->getPrestado()==true && mat!= nullptr) 
        {
            cout<<"Ya esta prestado"<<endl;
            cout<<endl;
        }
    }
    else if (opcion == 2)
    {
        MaterialBibliografico* mat = user->borrarPrestado();
        mat->setPrestado(false);
    }
    else 
    {

    }
}

void gestionUsuarios(Usuario* usuarios[5])
{
    int opcion = 0;
    string nombre, id;

    while (opcion <1 || opcion>3)
    {
        cout<<"1. Crear usuario"<<endl;
        cout<<"2. Buscar usuario"<<endl;
        cout<<"3. Eliminar usuario"<<endl;
        cin>>opcion;
        cout<<endl;
    }

    switch (opcion)
    {
    case 1:
        if (usrs>=5)
        {
            cout<<"No se pueden agregar mas usuarios"<<endl;;
            break;
        }
        else
        {
            cout<<"Ingrese nombre"<<endl;
            cin>>nombre;
            cout<<"Ingrese ID"<<endl;
            cin>>id;
            cout<<endl;
            usuarios[usrs] = new Usuario(nombre, id);
            cout<<usuarios[usrs]->getNombre()<<endl;
            usrs+=1;
            break;
        }

    case 2:
        cout<<"Buscar por ID: ";
        cin>>id;
        cout<<endl;
        for (int i=0; i<usrs;i++)
        {
            if (usuarios[i]->getId()==id) 
            {
                cout<<"1. "<<usuarios[i]->getNombre()<<", "<<usuarios[i]->getId()<<endl;
                break;
            }
        }
        cout<<endl;
        break;
    
    case 3:
        cout<<"Buscar por ID para eliminar: ";
        cin>>id;
        cout<<endl;
        for (int i=0; i<usrs;i++)
        {
            if (usuarios[i]->getId()==id) 
            {
                cout<<"1. "<<usuarios[i]->getNombre()<<", "<<usuarios[i]->getId()<<endl;
                usuarios[i]->~Usuario();
                usrs-=1;
            }
        }
        cout<<endl;
        break;
        
    default:
        break;
    }
}

Usuario* login(Usuario* usuarios[5])
{   
    string id;
    Usuario* user;
    cout<<"Buscar usuario por ID: ";
    cin>>id;
    cout<<endl;
    for (int i=0; i<usrs;i++)
    {
        if (usuarios[i]->getId()==id) 
        {
            cout<<"1. "<<usuarios[i]->getNombre()<<", "<<usuarios[i]->getId()<<endl;
            user = usuarios[i];
            cout<<endl;
            return user;
        }
    }
    cout<<"No se encontro el usuario"<<endl;
    cout<<endl;
    return nullptr;
}

void escribir()
{
    ofstream archivo;

    archivo.open("example.txt", ios::out);

    if (archivo.fail())
    {
        cout<<"Error al crear el archivo";
        exit(1);
    }
    
    archivo<<1<<endl;
    archivo<<"Juan,823";

    archivo.close();
}

/* void lectura()
{
    ifstream archivo;
    string linea;
    string texto[2];
    int found, i = 0;

    archivo.open("example.txt", ios::in);

    if (archivo.fail())
    {
        cout<<"Error al abrir el archivo";
        exit(1);
    }

    while (!archivo.eof())
    {
        getline(archivo, linea);
        while (linea != "\0")
        {   
            found = linea.find(",");
            for (int f=0; f<found; f++)
            {
                texto[i] += linea[f];
            }
            linea.erase(0, found + 1);
            i++;
        }
    }
    for (int d=0; d<i; d++)
    {
        cout<<texto[d]<<endl;
    }

    archivo.close();
} */