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

#ifndef Pelicula_h
#define Pelicula_h

#include <stdio.h>
#include <iostream>
#include <string>
#include "Video.h"

using namespace std;

//Clase Pelicula es derivada de Video
class Pelicula : public Video{
private:
    int Oscares;

public:

    //Constructores
    Pelicula();
    Pelicula(string _Id, string _Nombre, int _Duracion,
    string _Genero, double _Calificacion,int _Oscares);

    //Métodos modificadores
    void setOscares(int _Oscares);

    //Métodos de acceso
    int getOscares();

    //Métodos particulares
    string str();

};

#endif