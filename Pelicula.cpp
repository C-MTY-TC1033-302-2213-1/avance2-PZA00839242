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
    Oscares = 100;
    
}

Pelicula::Pelicula(string _Id, string _Nombre, int _Duracion,
string _Genero, double _Calificacion,int _Oscares):Video(_Id, _Nombre,_Duracion, _Genero, _Calificacion){
    Oscares = _Oscares;
}

    //Métodos modificadores
void Pelicula::setOscares(int _Oscares){
    Oscares = _Oscares;
}

    //Métodos de acceso
int Pelicula::getOscares(){
    return Oscares;
}

    //Métodos particulares
string Pelicula::str(){
    //Tenemos acceso directo a los atributos de la clase padre porque son protected
    return Id + ' ' + Nombre + ' ' + to_string(Duracion) + ' ' + Genero + ' ' + to_string(Calificacion) + ' ' + to_string(Oscares);
}