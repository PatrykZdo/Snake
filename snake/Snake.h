#ifndef Snake_h
#define Snake_h
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
#include "Jedzenie.h"
#include "Postac.h"

using namespace std;

class Snake:public Postac{
      char poprzedniZnak;
      static int rozmiar;
      vector<pair<int,int>> pozycja;

public:
      static int trudnosc;
      char znak;

      Snake();
      Snake(Plansza &P);
      ~Snake();

      void inicjalizacja(Plansza &P,Jedzenie &J);
      void zamien(int pozx,int pozy);
      virtual void poruszanie(Plansza &P);
      bool czyZjedzone(Jedzenie &J);
      virtual void jedzenie();
      bool gameOver(Plansza &P);
      static int wynik();
};
#endif
