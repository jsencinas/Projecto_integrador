#include "Pelicula.h"

using namespace std;

Pelicula::Pelicula(string id, string nombre, int duracion, string genero) : 
            Video(id, nombre, duracion, genero){

};

string Pelicula::getInfo() {
    string info = id + "|" + nombre + "|" + to_string(duracion) + "|" + genero + "|" + getCalificacionStr();
    return info;
}