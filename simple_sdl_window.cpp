#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

int main() {
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        cout << "SDL INIT ERROR" << endl;
        return 1;
    }
    //afisarea unei ferestre simple


    return 0;
}
