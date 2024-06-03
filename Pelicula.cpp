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


#include "Pelicula.h"

using namespace std;

Pelicula::Pelicula():Video(){
    oscares = 100;
    
}

Pelicula::Pelicula(string _iD, string _Nombre, int _Duracion,
string _Genero, double _Calificacion,int _Oscares):Video(_iD, _Nombre,_Duracion, _Genero, _Calificacion){
    oscares = _Oscares;
}

    //Métodos modificadores
void Pelicula::setOscares(int _Oscares){
    oscares = _Oscares;
}

    //Métodos de acceso
int Pelicula::getOscares(){
    return oscares;
}

    //Métodos particulares
string Pelicula::str(){
    //Tenemos acceso directo a los atributos de la clase padre porque son protected
    return iD + ' ' + nombre + ' ' + to_string(duracion) + ' ' + genero + ' ' + to_string(calificacion) + ' ' + to_string(oscares);
}