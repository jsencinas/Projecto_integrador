#include <iostream>
#include <cmath>
#include <format>
#include "Video.h"

using namespace std;

Video::Video(string id, string nombre, int duracion, string genero) : 
    id(id), nombre(nombre), duracion(duracion), genero(genero){
}

void Video::calificar(int calificacion){
    calificaciones.push_back(calificacion);
}

string Video::getCalificacionStr(){
    if(!calificaciones.empty()){
        float promedio, sumaCal = 0;
        for(int cal : calificaciones){
            sumaCal += cal;
        }
        promedio = sumaCal / calificaciones.size();
        string promedioStr = format("{0:.1f}", promedio);
        return promedioStr;

    } else {
        return "SC";
    }
}

string Video::getGenero(){
    return genero;
}

string Video::getID(){
    return id;
}