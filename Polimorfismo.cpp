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

#include "Polimorfismo.h"

using namespace std;

Polimorfismo::Polimorfismo(){
    for(int index = 0; index < MAX_VIDEOS; index++){
        arrPtrVideos[index] = nullptr;
    } 

    cantidad = 0;
}

void Polimorfismo::leerArchivo(string nombre){
    Serie *arrPtrSeries[50];
    Pelicula *arrPtrPeliculas[50];
    Episodio episodio;
    fstream entrada;
    string row[7];      // row - arreglo de 7 elementos de strings, para almacenar los datos de la línea del archivo ya separados 
    string line, word;      // line - almacena la línea leída, y word la palabra que se saca de line
    int cantidadPeliculas = 0;      //contadores de películas y series, inicialmente son 0
    int cantidadSeries = 0;
    int iR = 0, index;
    double promedio;

    entrada.open(nombre, ios::in);      //Abrir archivo de entrada

    while (getline(entrada, line)){         //lee una línea del archivo y la almacena en line 
        stringstream s(line);       // usado para separar las palabras de split()
        iR = 0;         //Cada vez que inicia una nueva linea inicializa iR = 0
        
        //Ciclo que extrae caracteres de s y los almacena en word hasta que encuentra el delimitador ','
        while(getline(s,word, ',')){
            row[iR++] = word;       // añade word al arreglo row e incrementa iR p/la proxima palabra
        }

        //Determinar si la línea  es P-pelicula, S-serie, E-episodio
        if(row[0] == "P"){
            //Se crea  un apuntador usando el operador new y el constructor con parámetros y se guarda en el arrPtrPeliculas
            arrPtrPeliculas[cantidadPeliculas] = new Pelicula( row[1], row[2], stoi(row[3]), row[4], stod(row[5]), stoi(row[6]));
            cantidadPeliculas++;
        }
        else if(row[0] == "S"){
            arrPtrSeries[cantidadSeries] = new Serie(row[1], row[2], stoi(row[3]), row[4], stod(row[5]));
            cantidadSeries++;
        }
        else if(row[0] == "E"){
            //Calcular a que Serie le pertenece el episodio
            index = stoi(row[1]) - 500;
            //Se agrega el epidosio usando el método AgregaEpisodio
            //Se crea el apuntador y se convierte a objeto usando el operador de indirección
            arrPtrSeries[index] -> agregaEpisodio(*(new Episodio(row[2], stoi(row[3]), stoi(row[4])))); 
        }

        //Guardamos todos los apuntadores de Películas y Series en el arrPtrVideo
        //Copiamos todos los apuntadores del arreglo de Series al arreglo de apuntadores de Video calculando su calificacionPromedio
    }
    for(int index = 0; index < cantidadSeries; index++){
        promedio = arrPtrSeries[index] -> calculaPromedio(); //Calcula la calificacion de la serie
        arrPtrSeries[index] -> setCalificacion(promedio); //Cambiamos la calificacion de la serie
        arrPtrSeries[index] -> calculaDuracion(); //Calculamos la duracion de la serie
        arrPtrVideos[cantidad++] = arrPtrSeries[index];

    }

    //Copiamos todos los apuntadores del arreglo de Pelicula al arreglo de apuntadores de Video
    for(int index = 0; index < cantidadPeliculas; index++){
        arrPtrVideos[cantidad++] = arrPtrPeliculas[index];

    }

    //Desplegamos todo el contenido del arreglo de apuntadores de la clase Video(base)
    //ejecutamos el metodo str() del apuntador correspondiente almacenado
    
    /*
    for(int index = 0; index < cantidadVideos;index++){
        cout << index << " " << arrPtrVideos[index] -> str() << endl;
    } 
    */

    entrada.close(); // cerramos el archivo
}

void Polimorfismo::setPtrVideo(int index, Video* video){
    // validar index - >= 0 && < cantidad
    if(index >=0 && index < cantidad){
        //cambiar modificar el apuntador
        arrPtrVideos[index] = video ; 
    }
}


//cambia el valor de atributo cantidad
//cantidad este entre 0 .. MAX_VIDEOS -1 , de lo contrario NO se modifica el valor del atributo
void Polimorfismo::setCantidad(int _cantidad){
    //Validar el valor de _Cantidad
    if(_cantidad >= 0 && _cantidad <= MAX_VIDEOS){
        cantidad = _cantidad;
    } 

}

Video* Polimorfismo::getPtrVideo(int index){
    //Validar que exista el index
    if( index >= 0 && index < cantidad){
        return arrPtrVideos[index];
    }
    
    return nullptr;

}

int Polimorfismo::getCantidad(){
    return cantidad;

}

void Polimorfismo::reporteInventario(){
    //Declaracion de contadores
    int contPeliculas, contSeries;

    //Inicializar 
    contPeliculas = 0;
    contSeries = 0;

    //recorrer rodo el arreglo de ptr usando un for
    for (int index = 0; index < cantidad; index++){

        //dentro del for, fuera de los ifs
        cout << arrPtrVideos[index] -> str() << endl;

        if(typeid(*arrPtrVideos[index]) == typeid(Pelicula)){
            contPeliculas++; 
        }
        else if(typeid(*arrPtrVideos[index]) == typeid(Serie)){
            contSeries++;
        }
        
    }
    //fuera del for
    cout << "Peliculas = " << contPeliculas << endl;
    cout << "Series = " << contSeries << endl;
     
}

void Polimorfismo::reporteCalificacion(double _calificacion){
    int Total;

    Total = 0;

    for (int index = 0; index < cantidad; index++){
        //Verificar si tiene la calificación == _calificacion
        //Apuntador se usa ->
        if( arrPtrVideos[index] ->getCalificacion() == _calificacion){
            cout << arrPtrVideos[index] -> str() << endl;
            Total++;
        }
    }
    //Fuera del for
    cout << "Total = " << Total << endl;

}

void Polimorfismo::reporteGenero(string _genero){
    int TotalGen;

    TotalGen = 0;

    for (int index = 0; index < cantidad; index++){
        //Verificar si tiene el genero == _genero
        //Apuntador se usa ->
        if( arrPtrVideos[index] ->getGenero() == _genero){
            cout << arrPtrVideos[index] -> str() << endl;
            TotalGen++;
        }
    }
    //Fuera del for
    cout << "Total = " << TotalGen << endl;
}

void Polimorfismo::reportePeliculas(){
    int TotalPeliculas;

    TotalPeliculas = 0;

    for (int index = 0; index < cantidad; index++){
        //Verificar si tiene el id de Película
        //Apuntador se usa ->
        if(typeid(*arrPtrVideos[index]) == typeid(Pelicula)){
            cout << arrPtrVideos[index] -> str() << endl;
            TotalPeliculas++;
        }
    }
    //Fuera del for
    cout << "Total Peliculas = " << TotalPeliculas << endl;
}

void Polimorfismo::reporteSeries(){
    int TotalSeries;
    bool Total = false;

    TotalSeries = 0;
    

    for (int index = 0; index < cantidad; index++){
        //Verificar si tiene el id de Series
        //Apuntador se usa ->
        if(typeid(*arrPtrVideos[index]) == typeid(Serie)){
            cout << arrPtrVideos[index] -> str() << endl;
            TotalSeries++;
            Total = true;
        }
    }
    //Fuera del for
    if (Total == true)
    {
        cout << "Total Series = " << TotalSeries << endl;
    }
    else{
        cout << "No series" << endl;
    }

}
 
