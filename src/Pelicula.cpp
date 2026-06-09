#include "Pelicula.h"

using namespace std;

Pelicula::Pelicula(string id, string nombre, int duracion, string genero) : 
            Video(id, nombre, duracion, genero){

};

string Pelicula::getInfo(TypeInfo type) {
    switch (type){
    case generalInfo: {
        string info = id + "|" + nombre + "|" + to_string(duracion) + "|" + genero + "|" + getCalificacionStr();
        return info;
        break;
    }
    case calificacionInfo: {
        string info = id + "|" + nombre + "|" + getCalificacionStr();
        return info;
        break;
    }
    case generoInfo: {
        string info = id + "|" + nombre + "|" + genero + "|" + getCalificacionStr(); 
        return info;
        break;
    } 
    default:
        return "";
        break;
    }  
}