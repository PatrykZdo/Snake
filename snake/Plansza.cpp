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

Plansza::Plansza(){szerokosc=10,wysokosc=10;};

Plansza::Plansza(int w, int h){
            szerokosc=w;
            wysokosc=h;
            };

Plansza::~Plansza(){};

void Plansza::terytorium(){
      this->teren=new int*[this->szerokosc];
            for (int i=0;i<this->szerokosc;i++){
                  this->teren[i]=new int[this->wysokosc];                                       //tworzenie tablicy dwuwymiarowej ktora odpowiadaæ planszy do gry
                  for(int j=0;j<this->wysokosc;j++){
                        this->teren[i][j]=0;
                  }
            }

}

void Plansza::rysuj_plansze(HANDLE hConsole){
      for(int i=0;i<this->szerokosc;i++){
                  for(int j=0;j<this->wysokosc;j++){
                        if(this->teren[i][j]==7){
                              SetConsoleTextAttribute(hConsole,10);
                              cout<<this->teren[i][j]<<" ";
                        }
                        else if(this->teren[i][j]==2){
                              SetConsoleTextAttribute(hConsole,12);
                              cout<<this->teren[i][j]<<" ";                                    //wypisywanie wszystkich elementow tablicy na ekran
                        }
                        else if (this->teren[i][j]==0){
                              SetConsoleTextAttribute(hConsole,8);
                              cout<<this->teren[i][j]<<" ";
                        }
                  }
            cout<<endl;
            }
      SetConsoleTextAttribute(hConsole,15);
}
