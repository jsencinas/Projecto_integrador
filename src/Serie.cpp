#include "Serie.h"

using namespace std;

Serie::Serie(string id, string nombre, int duracion, string genero, string capitulo, int temporada) : 
        Video(id, nombre, duracion, genero), capitulo(capitulo), temporada(temporada){

}