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

#include "Episodio.h"
using namespace std;

    //Constructores
Episodio::Episodio(){
    titulo = "Curso de Programacion Orienteada a Objetos";
    temporada = 1;
    calificacion = 56;
}

Episodio::Episodio(string _Titulo, int _Temporada, int _Calificacion){
    titulo = _Titulo;
    temporada = _Temporada;
    calificacion = _Calificacion;
}

    //Métodos modificadores - setters
void Episodio::setTitulo(string _Titulo){
    titulo = _Titulo;
}

void Episodio::setTemporada(int _Temporada){
    temporada = _Temporada;
}

void Episodio::setCalificacion(int _Calificacion){
    calificacion = _Calificacion;
}

    //Métodos de acceso - getters
string Episodio::getTitulo(){
    return titulo;
}

int Episodio::getTemporada(){
    return temporada;
}

int Episodio::getCalificacion(){
    return calificacion;
}

    //Métodos Particulares
string Episodio::str(){
    return titulo + ' ' + to_string(temporada) + ' ' + to_string(calificacion);
}