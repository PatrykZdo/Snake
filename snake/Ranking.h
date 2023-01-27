#ifndef Ranking_h
#define Ranking_h
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

template <class T>
class Ranking{
      T **ranking;
      int dlugosc;


public:
      Ranking();
      ~Ranking();
      friend void sortowanie(Ranking *ran);
      char z;

      void tworzenieTablic();
      void wczytaj();
      void wczytaj_int();
      void wypisz(int ile);
      void suma();

};
#endif
