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
        void calificar(double calificacion);
        double getCalificacion();
        string getGenero();

        virtual void mostrar() = 0;
        Video(string id, string nombre, int duracion, string genero);
};