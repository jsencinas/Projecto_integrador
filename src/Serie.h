#pragma once
#include <string>
#include "Video.h"

using namespace std;

class Serie : public Video{
    private:
        string capitulo;
        int temporada;

    public:
        Serie(string id, string nombre, int duracion, string genero, string capitulo, int temporada);
};