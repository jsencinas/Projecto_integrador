#include <iostream>
#include "Video.h"

using namespace std;

Video::Video(string id, string nombre, int duracion, string genero) : 
    id(id), nombre(nombre), duracion(duracion), genero(genero){
}

void Video::calificar(double calificacion){
    calificaciones.push_back(calificacion);
}

string Video::getCalificacionStr(){
    if(!calificaciones.empty()){
        double sumaCal, promedio;
        for(int cal : calificaciones){
            sumaCal += cal;
        }
        promedio = sumaCal / calificaciones.size();    
        return to_string(promedio);

    } else {
        return "SC";
    }
}

string Video::getGenero(){
    return genero;
}