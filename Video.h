/*
Añade por favor en cada clase este comentario con toda tu información 
Nombre: José Pablo Zapata Lozao
Matricula: A00839242
Carrera: ITC
Fecha: 30/05/2024
Reflexión: Aprendí el concepto de polimorfismo y un ejemplo de su aplicación, el cual fue utilizar apuntadores para obtener distintos
resultados de un método, uno fue, por ejemplo, el método str, el cual nos devuelve la información de la película, de la serie o de los episodios
según corresponda.
*/

#ifndef Video_h
#define Video_h

#include <stdio.h>
#include <iostream>
#include <typeinfo>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

class Video{
protected:
    string Id;
    string Nombre;
    int Duracion;
    string Genero;
    double Calificacion;

public:
    //Constructores
    Video();
    Video(string _Id, string _Nombre, int _Duracion,
    string _Genero, double _Calificacion);

    //Métodos modificadores - setters 
    void setId(string _Id);
    void setNombre(string _Nombre);
    void setDuracion(int _Duracion);
    void setGenero(string _Genero);
    void setCalificacion(double _Calificacion);

    //Métodos de acceso - getters
    string getId();
    string getNombre();
    int getDuracion();
    string getGenero();
    double getCalificacion();

    //Métodos particulares
    virtual string str(); 
};
#endif 
