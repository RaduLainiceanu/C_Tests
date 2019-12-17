/*  Autor: Lainiceanu Radu-Constantin
    Data: 17.12.2019
    Realizat in CLion, 
        S-au folosit CMake, pentru crearea in Eclipse CDT sau alte IDE
    este necesara link-uirea libSDL2.a (libSDL2.dll in Win) cu libSDL2main.a.
        Trebuie instalat SDL2 si adaugate librariile in IDE.
    Infografie: John Purcell, C++ programming for begginers @ Udemy
*/

#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

//afisarea unei ferestre simple
int main() {
    //Verificare initializare SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        cout << "SDL INIT ERROR: "<< SDL_GetError() << endl;
        //cod 1 este eroare SDL: Eroare initializare SDL
        return 1;
    }

    //Constante dimensiune fereastra
    const int LATIME_FER = 800;
    const int INALTIME_FER = 640;

    //parametrii fereastra
    SDL_Window *pointer_window = SDL_CreateWindow("WINDOW TITLE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, LATIME_FER, INALTIME_FER, SDL_WINDOW_SHOWN);

    //verificare pointer_window
    if(pointer_window == NULL){
        cout << "SDL pointer_window == NULL: "<< SDL_GetError() << endl;
        SDL_Quit();
        //cod 2 este eroare SDL: pointer_window == NULL
        return 2;
    }

    //bucla joc - Game Loop
    //  Aceasta bucla ruleaza cat timp programul ruleaza
    //  Se afiseaza obiectele, se actualizeaza obiectele,
    //se verifica aparitia evenimentelor(events, modificari structuri de date, etc)
    bool fereastra_merge = true;
    //este folosit in bucla interioara pentru ascultare evenimente
    SDL_Event event;
    while(fereastra_merge){
        //verificare evenimente prin SDL
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){//SDL_QUIT apare atunci cand folosesti orice declaratie inchide fereastra
                //cand dai click pe X se inchide fereastra
                fereastra_merge = false;
            }
        }
    }

    //eliberare memorie
    SDL_DestroyWindow(pointer_window);
    SDL_Quit();
    //returnare cod 0. Fara eroare
    return 0;
}
