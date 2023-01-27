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

using namespace std;

Jedzenie::Jedzenie(){pozJedzenia=make_pair(5,5);};

Jedzenie::Jedzenie(Plansza &P){
      pozJedzenia=make_pair(rand()%P.szerokosc,rand()%P.wysokosc);
};

Jedzenie::~Jedzenie(){};
void Jedzenie::jablko(Plansza &P){

      P.teren[this->pozJedzenia.first][this->pozJedzenia.second]=7;           //Funkcja odpowiada za generowanie miejsca jab³ka("2")  na planszy
      this->pozJedzenia.first=rand()%P.szerokosc;
      this->pozJedzenia.second=rand()%P.wysokosc;
      if(P.teren[this->pozJedzenia.first][this->pozJedzenia.second]==7){
            jablko(P);
      }
}
