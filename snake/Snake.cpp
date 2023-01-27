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
#include "Snake.h"

using namespace std;

Snake::Snake(){pozycja.push_back(make_pair(0,0)),rozmiar=1,poprzedniZnak='c';};
Snake::Snake(Plansza &P){
           pozycja.push_back(make_pair(rand()%P.szerokosc,rand()%P.wysokosc));
           rozmiar=1;
           poprzedniZnak='c';
      };
Snake::~Snake(){};

void Snake::inicjalizacja(Plansza &P,Jedzenie &J){
            for(int i=0;i<P.szerokosc;i++){
                  for(int j=0;j<P.wysokosc;j++){
                              P.teren[i][j]=0;                          //ustawienie "0" na wszystkich miejscach tablicy dwuwymiarowej pochodz¹cej z klasy "Plansza"
                  }
            }
            for(int i=0;i<this->rozmiar;i++){
                  P.teren[this->pozycja[i].first][this->pozycja[i].second]=7;            //ustawienie "7"(weza) w tablicy z klasy "Plansza" na okreslonym miejscu
            }
            P.teren[J.pozJedzenia.first][J.pozJedzenia.second]=2;                  //ustawienie "2"(Jablka) w tablicy z klasy "Plansza" na okreslonym miejscu
      }

void Snake::zamien(int pozx,int pozy){
            this->pozycja.insert(this->pozycja.begin(),make_pair(pozx,pozy));       //funkcja jest wykorzystywana w funkcij "poruszanie" i pozwala na przenikanie wezowi przez "sciany"
            this->pozycja.pop_back();
      }

void Snake::poruszanie(Plansza &P){
            if((this->znak=='A'||this->znak=='a')&&(this->poprzedniZnak=='D'||this->poprzedniZnak=='d')){
                  this->znak='D';
            }
            else if((this->znak=='D'||this->znak=='d')&&(this->poprzedniZnak=='A'||this->poprzedniZnak=='a')){
                  this->znak='A';                                                                                       //zapobieganie zeby waz nie mogl zawrocic w przeciwny kierunek. jezeli idzie do gory to nie mozna zmienic kiurunku w dol
            }
            else if((this->znak=='w'||this->znak=='W')&&(this->poprzedniZnak=='S'||this->poprzedniZnak=='s')){
                  this->znak='S';
            }
            else if((this->znak=='S'||this->znak=='s')&&(this->poprzedniZnak=='W'||this->poprzedniZnak=='w')){
                  this->znak='W';
            }


            if ((this->znak=='A'||this->znak=='a')){
                  this->pozycja[0].second=pozycja[0].second-1;          //przesuniecie "glowy weza" o jedno miejsce w lewo na planszy
                  if(this->pozycja[0].second<0){
                        this->pozycja[0].second=pozycja[0].second+1;
                        zamien(this->pozycja[0].first,P.wysokosc-1);
                       this->pozycja[0].second=P.wysokosc-1;
                  }
                  this->poprzedniZnak='a';
            }
            else if ((this->znak=='D'||this->znak=='d')){
                  this->pozycja[0].second=pozycja[0].second+1;
                  if(this->pozycja[0].second>=P.wysokosc){
                        this->pozycja[0].second=pozycja[0].second-1;
                        zamien(this->pozycja[0].first,0);
                        this->pozycja[0].second=0;

                  }
                  this->poprzedniZnak='d';
            }
            else if ((this->znak=='W'||this->znak=='w')){

                  this->pozycja[0].first=pozycja[0].first-1;
                  if(this->pozycja[0].first<0){
                        this->pozycja[0].first++;
                        zamien(P.szerokosc-1,this->pozycja[0].second);
                        this->pozycja[0].first=P.szerokosc-1;

                  }
                  this->poprzedniZnak='w';
            }
            else if ((this->znak=='S'||this->znak=='s')){
                  this->pozycja[0].first++;
                  if(this->pozycja[0].first>=P.szerokosc){
                        this->pozycja[0].first--;
                        zamien(0,this->pozycja[0].second);
                        this->pozycja[0].first=0;

                  }
                  this->poprzedniZnak='s';
            }

            else{
                  this->znak=this->poprzedniZnak;
            }

            for (int i=this->pozycja.size();i>0;i--){
                  this->pozycja[i]=this->pozycja[i-1];      //przekopowianie n-tego elementu na n-1 miejsce
            }
      }

bool Snake::czyZjedzone(Jedzenie &J){
            if(this->pozycja[0].first==J.pozJedzenia.first && this->pozycja[0].second==J.pozJedzenia.second)            //funkcja sprawdza czy waz zjadl jablko
                  return true;
      }

void Snake::jedzenie(){
            this->pozycja.push_back(make_pair(this->pozycja[this->rozmiar-1].first,this->pozycja[this->rozmiar-1].second));         //dodanie na koniec wektora kolejnych wspolrzednych weza
            this->rozmiar++;
      }

bool Snake::gameOver(Plansza &P){
            for (int i=3;i<this->pozycja.size();i++){
                  if(this->pozycja[0].first==this->pozycja[i].first && this->pozycja[0].second==this->pozycja[i].second){     //sprawdzenie czy waz zjadl samego siebie i czy nastapil koniec gry
                        return false;
                  }
            }
            return true;
      }

int Snake::wynik(){
            if(trudnosc==400)return (rozmiar-1)*100;
            else if(trudnosc==200)return (rozmiar-1)*150;         // w zaleznosci od trudnosci gry zastosowany jest odpowiedni mnoznik
            else if(trudnosc==100)return (rozmiar-1)*200;
      }

