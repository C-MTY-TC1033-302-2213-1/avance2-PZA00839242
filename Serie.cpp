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

#include "Serie.h"


using namespace std;

Serie::Serie():Video(){
    //Solo vamos a inicializar cantidad
    cantidad = 0;
}
Serie::Serie(string _iD, string _Nombre, int _Duracion,
    string _Genero, double _Calificacion):Video(_iD, _Nombre,_Duracion, _Genero, _Calificacion){

}

    //Métodos modificadores
void Serie::setEpisodio(int posicion, Episodio episodio){
    //Primero validamos si existe el episodio a modificar
    if( posicion >= 0 && posicion < cantidad){
        episodios[posicion] = episodio;
    }
}

void Serie::setCantidad(int _cantidad){
    cantidad = _cantidad;
}

    //Métodos de acceso
Episodio Serie::getEpisodio(int posicion){
    //Creamos un objeto del tipo episodio y lo inicializa con el Constructor default
    Episodio epi;
    //Validar queexista el episodio solicitado (posicion)
    if(posicion >= 0 && posicion < cantidad ){
        return episodios[posicion];
    }

    //Si no existe se retorna un Episodio default
    return epi;
}

int Serie::getCantidad(){
    return cantidad;
}

    //Métodos Particulares
double Serie::calculaPromedio(){
    double acum = 0;
    for(int index = 0; index < cantidad; index ++){
        acum = acum + episodios[index].getCalificacion();
    }

    if(cantidad > 0){
        return acum / cantidad;
    }
    else{
        return 0;
    }
}

//Overriding del metodo str() de la clase Base
string Serie::str(){
    string Eps;

    Eps = iD + ' ' + nombre + ' ' + to_string(duracion) + ' ' + genero + ' ' 
    + to_string(calificacion) + ' ' + to_string(cantidad) + "\n";

    for(int index = 0; index < cantidad; index ++){
        Eps +=  episodios[index].str() + "\n";
    }

    return Eps;
}

//agrega un epidosodio solo si existe espacio
void Serie::agregaEpisodio(Episodio episodio){
    if(cantidad < 5){
        episodios[cantidad++] = episodio;
    }

}

void Serie::calculaDuracion(){
    int Temporadas;

    Temporadas = 0;
    for(int index = 0; index < cantidad ; index++){
        Temporadas += episodios[index].getTemporada();
    }

    duracion = Temporadas;
}