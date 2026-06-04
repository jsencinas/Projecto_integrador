#pragma once
#include <string>

using namespace std;

class Video{
    protected:
        enum Categoria {p, c};
        string id;
        string nombre;
        int duracion;
        string genero;
        double calificacion;

    public:
        void calificar();
        Video();
};