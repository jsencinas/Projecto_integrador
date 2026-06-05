#pragma once
#include <vector>
#include <string>

using namespace std;

class Video{
    protected:
        string id;
        string nombre;
        int duracion;
        string genero;
        vector<double> calificaciones;

    public:
        Video(string id, string nombre, int duracion, string genero);

        void calificar(double calificacion);
        string getCalificacionStr();
        string getGenero();
        virtual string getInfo() = 0;
};