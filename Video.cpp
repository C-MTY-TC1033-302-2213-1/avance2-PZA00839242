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
    iD = "0000";
    nombre = "Pablo Zapata";
    duracion = 10000;
    genero = "Masculino";
    calificacion = 100;
}

Video::Video(string _iD, string _Nombre, int _Duracion, string _Genero, double _CalificacionPromedio){
    iD = _iD;
    nombre = _Nombre;
    duracion = _Duracion;
    genero = _Genero;
    calificacion = _CalificacionPromedio;
}

    //Métodos modificadores - setters 
void Video::setID(string _iD){
    iD = _iD;
}

void Video::setNombre(string _Nombre){
    nombre = _Nombre;
}

void Video::setDuracion(int _Duracion){
    duracion = _Duracion;
}

void Video::setGenero(string _Genero){
    genero = _Genero;
}

void Video::setCalificacion(double _CalificacionPromedio){
    calificacion = _CalificacionPromedio;
}

    //Métodos de acceso - getters
string Video::getId(){
    return iD;
}

string Video::getNombre(){
    return nombre;
}

int Video::getDuracion(){
    return duracion;
}

string Video::getGenero(){
    return genero;
}

double Video::getCalificacion(){
    return calificacion;
}

    //Métodos particulares
 string Video::str(){
    return;
}


