#include <iostream>
#include "Video.h"

using namespace std;

void Video::calificar(double calificacion){
    calificaciones.push_back(calificacion);
}

double Video::getCalificacion(){
    double sumaCal, promedio;
    for(int cal : calificaciones){
        sumaCal += cal;
    }

    promedio = sumaCal / calificaciones.size();    
    return promedio;
}

string Video::getGenero(){
    return genero;
}

Video::Video(string id, string nombre, int duracion, string genero) : 
        id(id), nombre(nombre), duracion(duracion), genero(genero){
}