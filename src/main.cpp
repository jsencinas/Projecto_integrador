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
    output << video.getInfo(Video::TypeInfo::generalInfo);
    return output;
}

int main(){
    ifstream file("videos.txt");    
    if(!file.is_open()) {
        cout << "FILE CAN'T BE OPENED." << endl;
    }
    string line;
    vector<Video*> catalogoVideos;
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
            catalogoVideos.push_back(pelicula);

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
            catalogoVideos.push_back(serie);

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
            for(Video* video : catalogoVideos){
                // Calls the overloaded << operator
                cout << *video << endl;
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

            if(ID.size() == 8 || ID.size() == 15){
                if(calInt >= 0 && calInt <= 5){
                    for(Video* video : catalogoVideos){
                        if(video->getID() == ID){
                            video->calificar(calInt);
                        }
                    }
                } else {
                    cout << "ERROR CRITICO CARNAL: La calificacion proporcionada no es valida, es invalida." << endl;
                }
            } else {
                cout << "ERROR CRITICO CARNAL: El id proporcionado es incorrecto, no existe" << endl;
            }
            cout << "###########################" << endl;
            break;
        
        // Mostrar peliculas o capitulos con una calificacion minima determinada
        case 3: {
            cout << "Que quieres ver como resultado?" << endl;
            cout << "1) Peliculas" << endl;
            cout << "2) Capitulos" << endl;
            cout << "3) Ambos" << endl;
            cout << "Seleccion: ";

            getline(cin, entrada);
            int subMenuOption = stoi(entrada);

            cout << "Ingresa tu calificacion minima (de 0 a 5): ";
            getline(cin, entrada);
            float calificacionMinima = stoi(entrada);

            // These are lambda functions (anonymous functions). Its like a disposable function.

            auto mostrarPeliculas = [&]() {
                for(Video* video : catalogoVideos){
                    if(video->getID().size() == 8 && 
                    video->getCalificacionStr() != "SC" && 
                    stof(video->getCalificacionStr()) >= calificacionMinima){
                        std::cout << video->getInfo(Video::TypeInfo::calificacionInfo) << endl;
                    }
                }
            };
            auto mostrarSeries = [&]() {
                for(Video* video : catalogoVideos){
                    if(video->getID().size() == 15 && 
                    video->getCalificacionStr() != "SC" && 
                    stof(video->getCalificacionStr()) >= calificacionMinima){
                        std::cout << video->getInfo(Video::TypeInfo::calificacionInfo) << endl;
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

        case 4: { 
            cout << "Que quieres ver como resultado?" << endl;
            cout << "1) Peliculas" << endl;
            cout << "2) Capitulos" << endl;
            cout << "3) Ambos" << endl;
            cout << "Seleccion: ";

            getline(cin, entrada);
            int subMenuOption = stoi(entrada);

            cout << "Ingresa el genero que deseas consultar: ";
            // Imprimir lista de generos pendiente
            getline(cin, entrada);
            string genero = entrada;

            // These are lambda functions (anonymous functions). Its like a disposable function.
            auto mostrarPeliculas = [&]() { 
                for(Video* video : catalogoVideos){
                    if(video->getID().size() == 8 && 
                    video->getGenero() == genero){
                        std::cout << video->getInfo(Video::TypeInfo::generoInfo) << endl;
                    }
                }
            };
            auto mostrarSeries = [&]() {
                for(Video* video : catalogoVideos){
                    if(video->getID().size() == 15 && 
                    video->getGenero() == genero){
                        std::cout << video->getInfo(Video::TypeInfo::generoInfo) << endl;
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
        case 9:
            cout << "Saliendo del programa brother, cool dia" << endl;
            break;

        default:
            cout << "Opcion no valida crack, intenta de nuevo" << endl;
            break;
        }
    } while (menuOption != 9);
   
    // Clean up the mess
    file.close();
    for(Video* video : catalogoVideos){
        delete video;
    }

    return 0;
}