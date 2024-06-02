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

#include "Video.h"
using namespace std;

Video::Video(){
    Id = "0000";
    Nombre = "Pablo Zapata";
    Duracion = 10000;
    Genero = "Masculino";
    Calificacion = 100;
}

Video::Video(string _Id, string _Nombre, int _Duracion, string _Genero, double _CalificacionPromedio){
    Id = _Id;
    Nombre = _Nombre;
    Duracion = _Duracion;
    Genero = _Genero;
    Calificacion = _CalificacionPromedio;
}

    //Métodos modificadores - setters 
void Video::setId(string _Id){
    Id = _Id;
}

void Video::setNombre(string _Nombre){
    Nombre = _Nombre;
}

void Video::setDuracion(int _Duracion){
    Duracion = _Duracion;
}

void Video::setGenero(string _Genero){
    Genero = _Genero;
}

void Video::setCalificacion(double _CalificacionPromedio){
    Calificacion = _CalificacionPromedio;
}

    //Métodos de acceso - getters
string Video::getId(){
    return Id;
}

string Video::getNombre(){
    return Nombre;
}

int Video::getDuracion(){
    return Duracion;
}

string Video::getGenero(){
    return Genero;
}

double Video::getCalificacion(){
    return Calificacion;
}

    //Métodos particulares
 string Video::str(){
    return Id + ' ' + Nombre + ' ' + to_string(Duracion) + ' ' + Genero + ' ' + to_string(Calificacion);
}


