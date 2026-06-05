#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Pelicula.h"
#include "Serie.h"

using namespace std;

// Sobrecarga de operadores - Igual que con un metodo, podemos sobrecargar operadores
// En este caso, sobrecargamos el operador <<
ostream& operator<<(ostream& output, Video& video){
    output << "ID: ";
    return output;
}

int main(){
    ifstream file("videos.txt");    
    if(!file.is_open()) {
        cout << "FILE CAN'T BE OPENED." << endl;
    }
    string line;
    vector<Video*> catalogo;
    while(getline(file,line)) {
        string videoTypeStr, idStr, nombreStr, duracionStr, generoStr, nombreCapituloStr, temporadaStr;
        int duracionInt, temporadaInt;
        stringstream stream(line);
        getline(stream, videoTypeStr, ',');

        if(videoTypeStr == "p"){
            getline(stream, idStr, ',');
            getline(stream, nombreStr, ',');
            getline(stream, duracionStr, ',');
            getline(stream, generoStr, ',');

            duracionInt = stoi(duracionStr);
            Pelicula pelicula(idStr, nombreStr, duracionInt, generoStr);
            catalogo.push_back(&pelicula);
            cout << pelicula.getInfo() << endl;

        } else if(videoTypeStr == "c"){
            getline(stream, idStr, ',');
            getline(stream, nombreCapituloStr, ',');
            getline(stream, duracionStr, ',');
            getline(stream, generoStr, ',');
            getline(stream, nombreStr, ',');
            getline(stream, temporadaStr, ',');

            duracionInt = stoi(duracionStr);
            temporadaInt = stoi(temporadaStr);
            Serie serie(idStr, nombreStr, duracionInt, generoStr, nombreCapituloStr, temporadaInt);
            catalogo.push_back(&serie);
            cout << serie.getInfo() << endl;

        } else{
            cout << "Error en el archivo, mal formato" << endl;
            file.close();
            cout << "Archivo cerrado con exito" << endl;
            exit;
        }
    }

    int menuOption; 
    do{
        cout << "1. Mostrar todo el catalogo con calificaciones" << endl;
        cout << "2. Calificar un video" << endl;
        cout << "3. Mostrar peliculas o capitulos con una calificacion minima determinada" << endl;
        cout << "4. Mostrar peliculas o capitulos de un cierto genero" << endl;
        cout << "9. Salir" << endl;
        
        string entrada;
        getline(cin, entrada);
        menuOption = stoi(entrada);
        
        switch (menuOption)
        {
        case 1:
            cout << "hola" << endl;
            break;
        case 2:
            break;
        
        case 3:
            break;
        
        case 4:
            break;
        
        case 9:
            cout << "Saliendo del programa brother, cool dia" << endl;
            break;

        default:
            cout << "Opcion no valida crack, intenta de nuevo" << endl;
            break;
        }
    } while (menuOption != 9);
   
    file.close();
    cout << "Archivo cerrado con exito" << endl;
    return 0;
}