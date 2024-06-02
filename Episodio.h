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

#ifndef Episodio_h
#define Episodio_h

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class Episodio{
private:
    string Titulo;
    int Temporada;
    int Calificacion;

public:
    //Constructores
    Episodio();
    Episodio(string _Titulo, int _Temporada, int _Calificacion);

    //Métodos modificadores - setters
    void setTitulo(string _Titulo);
    void setTemporada(int _Temporada);
    void setCalificacion(int _Calificacion);

    //Métodos de acceso - getters
    string getTitulo();
    int getTemporada();
    int getCalificacion();

    //Métodos Particulares
    string str();

};
#endif 