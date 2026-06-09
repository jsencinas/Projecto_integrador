#include "Serie.h"

using namespace std;

Serie::Serie(string id, string nombre, int duracion, string genero, string nombreCapitulo, int temporada) : 
    Video(id, nombre, duracion, genero), nombreCapitulo(nombreCapitulo), temporada(temporada){
        
}

string Serie::getInfo(){
    string info = id + "|" + nombre + "|" + nombreCapitulo + "," + "T" + to_string(temporada) + 
                  "|" + to_string(duracion) + "|" + genero + "|" + getCalificacionStr();
    return info;
}

string Serie::getLessInfo(){
    string info = id + "|" + nombreCapitulo + "|" + getCalificacionStr();
    return info;
}