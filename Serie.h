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

#ifndef Serie_h
#define Serie_h

#include <stdio.h>
#include <iostream>
#include <typeinfo>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

//Herencia
#include "Video.h"

//Composicion
#include "Episodio.h"

using namespace std;

class Serie : public Video{
private:
    Episodio episodios[5];
    int cantidad;

public:
    //Constructores
    Serie();
    Serie(string _Id, string _Nombre, int _Duracion,
    string _Genero, double _Calificacion);

    //Métodos modificadores
    void setEpisodio(int posicion, Episodio episodio);
    void setCantidad(int _cantidad);

    //Métodos de acceso
    Episodio getEpisodio(int posicion);
    int getCantidad();

    //Métodos Particulares
    double calculaPromedio();
    string str();
    void agregaEpisodio(Episodio episodio);
    void calculaDuracion();

};

#endif