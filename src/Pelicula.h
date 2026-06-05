#pragma once
#include "Video.h"

using namespace std;

class Pelicula : public Video {
    public:
        Pelicula(string id, string nombre, int duracion, string genero);
};