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

        enum TypeInfo{
            generalInfo,
            calificacionInfo,
            generoInfo 
        };

        void calificar(int calificacion);
        string getCalificacionStr();
        string getGenero();
        string getID();
        virtual string getInfo(TypeInfo type);
};