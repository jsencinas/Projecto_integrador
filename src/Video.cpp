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

        cout << "***************" << endl;
        for(int cal : calificaciones){
            sumaCal += cal;
        }
        cout << sumaCal << endl;
        promedio = (sumaCal / calificaciones.size());
        cout << promedio << endl;
        return to_string(promedio);

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