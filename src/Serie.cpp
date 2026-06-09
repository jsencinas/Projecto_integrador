#include "Serie.h"

using namespace std;

Serie::Serie(string id, string nombre, int duracion, string genero, string nombreCapitulo, int temporada) : 
    Video(id, nombre, duracion, genero), nombreCapitulo(nombreCapitulo), temporada(temporada){
        
}

string Serie::getInfo(TypeInfo type){
    switch (type){
    case generalInfo: {
        string info = id + "|" + nombre + "|" + nombreCapitulo + "," + "T" + to_string(temporada) + 
                    "|" + to_string(duracion) + "|" + genero + "|" + getCalificacionStr();
        return info;
        break;
    }
    case calificacionInfo: {
        string info = id + "|" + nombreCapitulo + "|" + getCalificacionStr();
        return info;
        break;
    }
    case generoInfo: {
        string info = id + "|" + nombreCapitulo + "|" + genero + "|" + getCalificacionStr(); 
        return info;
        break;
    } 
    default:
        return "";
    }  
}