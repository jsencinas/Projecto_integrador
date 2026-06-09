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
        vector<int> calificaciones;

    public:
        Video(string id, string nombre, int duracion, string genero);

        void calificar(int calificacion);
        string getCalificacionStr();
        string getGenero();
        string getID();
        virtual string getInfo() = 0;
        virtual string getLessInfo() = 0;
};