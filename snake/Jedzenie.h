#ifndef Jedzenie_h
#define Jedzenie_h
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>
#include "Plansza.h"

using namespace std;

class Jedzenie{
      pair<int,int> pozJedzenia;
      friend class Snake;
public:
      Jedzenie();
      Jedzenie(Plansza &P );
      ~Jedzenie();

      void jablko(Plansza &P);
};
#endif
