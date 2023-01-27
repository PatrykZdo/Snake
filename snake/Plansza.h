#ifndef Plansza_h
#define Plansza_h
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>

using namespace std;

class Plansza{
      int szerokosc;
      int wysokosc;
      int **teren;

      friend class Snake;
      friend class Jedzenie;

public:
      Plansza();
      Plansza(int w, int h);
      ~Plansza();
      void terytorium();
      void rysuj_plansze(HANDLE hConsole);

};
#endif
