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

#ifndef Polimorfismo_h
#define Polimorfismo_h

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include "Video.h"
#include "Serie.h"
#include "Episodio.h"
#include "Pelicula.h"

using namespace std;

const int MAX_VIDEOS = 100;

//Para identificar si un objeto es de cierta clase usaremos la funcion typeinfo()

class Polimorfismo{
private:
    Video * arrPtrVideos[MAX_VIDEOS];
    int cantidad;

public:
    //Constructores
    Polimorfismo();

    //Métodos modificadores
    void setPtrVideo(int index, Video* video);
    void setCantidad(int _cantidad);

    //Métodos de acceso
    Video* getPtrVideo(int index);
    int getCantidad(); 

    //Métodos Particulares
    void leerArchivo(string _nombre);

    void reporteInventario();
    void reporteCalificacion(double _calificacion);
    void reporteGenero(string _genero);
    void reportePeliculas();
    void reporteSeries();

};
#endif 