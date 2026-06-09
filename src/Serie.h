#pragma once
#include <string>
#include "Video.h"

using namespace std;

class Serie : public Video{
    private:
        string nombreCapitulo;
        int temporada;

    public:
        Serie(string id, string nombre, int duracion, string genero, string nombreCapitulo, int temporada);
        string getInfo(TypeInfo type) override;
};