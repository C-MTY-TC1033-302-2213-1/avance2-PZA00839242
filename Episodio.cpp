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
    Titulo = "Curso de Programacion Orienteada a Objetos";
    Temporada = 1;
    Calificacion = 56;
}

Episodio::Episodio(string _Titulo, int _Temporada, int _Calificacion){
    Titulo = _Titulo;
    Temporada = _Temporada;
    Calificacion = _Calificacion;
}

    //Métodos modificadores - setters
void Episodio::setTitulo(string _Titulo){
    Titulo = _Titulo;
}

void Episodio::setTemporada(int _Temporada){
    Temporada = _Temporada;
}

void Episodio::setCalificacion(int _Calificacion){
    Calificacion = _Calificacion;
}

    //Métodos de acceso - getters
string Episodio::getTitulo(){
    return Titulo;
}

int Episodio::getTemporada(){
    return Temporada;
}

int Episodio::getCalificacion(){
    return Calificacion;
}

    //Métodos Particulares
string Episodio::str(){
    return Titulo + ' ' + to_string(Temporada) + ' ' + to_string(Calificacion);
}