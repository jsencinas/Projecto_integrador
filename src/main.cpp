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
ostream& operator<<(ostream& output, Pelicula& pelicula){
    output << pelicula.getInfo();
    return output;
}
ostream& operator<<(ostream& output, Serie& serie){
    output << serie.getInfo();
    return output;
}

int main(){
    ifstream file("videos.txt");    
    if(!file.is_open()) {
        cout << "FILE CAN'T BE OPENED." << endl;
    }
    string line;
    vector<Pelicula*> catalogoPelicula;
    vector<Serie*> catalogoSerie;
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
            
            Pelicula* pelicula = new Pelicula(idStr, nombreStr, duracionInt, generoStr);
            catalogoPelicula.push_back(pelicula);

        } else if(videoTypeStr == "c"){
            getline(stream, idStr, ',');
            getline(stream, nombreCapituloStr, ',');
            getline(stream, duracionStr, ',');
            getline(stream, generoStr, ',');
            getline(stream, nombreStr, ',');
            getline(stream, temporadaStr, ',');

            duracionInt = stoi(duracionStr);
            temporadaInt = stoi(temporadaStr);
            Serie* serie = new Serie(idStr, nombreStr, duracionInt, generoStr, nombreCapituloStr, temporadaInt);
            catalogoSerie.push_back(serie);

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
        cout << "Escribe el numero deseado broski: "; 
        string entrada, ID, calStr;  
        int calInt;

        getline(cin, entrada);
        menuOption = stoi(entrada);

        cout << "###########################" << endl;
        
        switch (menuOption){
        // Mostrar todo el catalogo con calificaciones
        case 1:
            for(Pelicula* pelicula : catalogoPelicula){
                // Calls the overloaded << operator
                cout << *pelicula << endl;
            }
            for(Serie* serie : catalogoSerie){
                // Calls the overloaded << operator
                cout << *serie << endl;
            }
            cout << "###########################" << endl;
            break;
        // Calificar un video
        case 2:
            cout << "ID del video a calificar: " << endl;
            getline(cin, ID);
            cout << "Escriba la calificacion (entero entre 1 y 5): ";
            getline(cin, calStr);
            calInt = stoi(calStr);

            if(calInt >= 0 && calInt <= 5){
                if(ID.length() == 8){
                    for(Pelicula* pelicula : catalogoPelicula){
                        if(pelicula->getID() == ID){
                            pelicula->calificar(calInt);
                        }
                    }
                } else if(ID.length() == 15){
                    for(Serie* serie : catalogoSerie){
                        if(serie->getID() == ID){
                            serie->calificar(calInt);
                        }
                    }
                } else {
                    cout << "ERROR CRITICO CARNAL: El formato del ID proporcionado es incorrecto" << endl;
                }
            } else {
                cout << "ERROR CRITICO CARNAL: La calificacion proporcionada no es valida, es invalida." << endl;
            }
            cout << "###########################" << endl;
            break;
        
        case 3: {
            cout << "Que quieres ver como resultado?" << endl;
            cout << "1) Peliculas" << endl;
            cout << "2) Capitulos" << endl;
            cout << "3) Ambos" << endl;
            cout << "Seleccion: ";

            getline(cin, entrada);
            int subMenuOption = stoi(entrada);

            cout << "Ingresa tu calificacion minima (de 0 a 5):";
            getline(cin, entrada);
            float calificacionMinima = stoi(entrada);

            // These are lambda functions (anonymous functions). Its like a disposable function.
            auto mostrarPeliculas = [&]() { 
                for(Pelicula* pelicula : catalogoPelicula){
                    if(pelicula->getCalificacionStr() != "SC" && 
                    stoi(pelicula->getCalificacionStr()) > calificacionMinima){
                        std::cout << pelicula->getLessInfo() << endl;
                    }
                }
            };

            auto mostrarSeries = [&]() {
                for(Serie* serie : catalogoSerie){
                    if(serie->getCalificacionStr() != "SC" && 
                    stoi(serie->getCalificacionStr()) > calificacionMinima){
                        std::cout << serie->getLessInfo() << endl;
                    }
                }
            };
        
            switch (subMenuOption){
            case 1: 
                mostrarPeliculas();
                break;
            case 2:
                mostrarSeries(); 
                break;
            case 3:
                // Do case 1 and 2
                mostrarPeliculas();
                mostrarSeries();
                break;
            default:
                cout << "ERROR CRITICO CARNAL: La opcion que proporsionaste esta fuera de rango" << endl;
                break;
            }
            cout << "###########################" << endl;
            break;
        } 

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

    for(Pelicula* pelicula : catalogoPelicula){
        delete pelicula;
    }
    for(Serie* serie : catalogoSerie){
        delete serie;
    }

    return 0;
}