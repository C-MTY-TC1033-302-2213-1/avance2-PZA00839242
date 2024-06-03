//
//  main.cpp
//  Avance2 31/05/24
//
//  Created by Ma. Guadalupe Roque Díaz de León on 31/05/24.
//

// Clases Base - Video - con método virtual str() para Poliformismo
// Clases Derivadas - Pelicula, Serie
// Clase usada para composición - Episodio
// Clase Polimorfismo -  para aplicar el polimorfismo con el método virtual y las clases derivadas
// Arreglo de apuntadores


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

#include <iostream>
#include "Video.h"
#include "Episodio.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Polimorfismo.h"

#include <string>
using namespace std;

void polimorfismo(Polimorfismo inventario){
  // Declaración de variables locales
 int opcion, oscares, cantidadEpisodios;
 double calificacion;
 string genero;

 cin >> opcion;

 switch (opcion) {
     case 1:
         cin >> calificacion;
         inventario.reporteCalificacion(calificacion);
         break;

     case 2:
         cin >> genero;
         inventario.reporteGenero(genero);
         break;

     case 3:
         inventario.reporteInventario();
         break;

     case 4:
         inventario.reportePeliculas();
         break;

     case 5:
         inventario.reporteSeries();
         break;

    default:
         cout << "Error\n";
         break;
    }
}

int main() {
    // Declaracion de objetos
    Polimorfismo neflix;
    int opcion;

    // leer la opcion
    cin >> opcion;

    switch (opcion){
        case 1:
           neflix.leerArchivo("Inventario1.csv");
           polimorfismo(neflix);
           break;

        case 2:
          neflix.leerArchivo("Inventario2.csv");
          polimorfismo(neflix);
          break;

    default:
          cout << "incorrecta" ;
    }

    return 0;
}
