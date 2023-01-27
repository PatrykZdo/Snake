#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>
#include "Ranking.h"

using namespace std;


template<typename T>
Ranking<T>::Ranking(){dlugosc=0;};

template<typename T>
Ranking<T>::~Ranking(){};

template<typename T>
void Ranking<T>::tworzenieTablic(){

            fstream p;
            p.open("ranking.txt",ios::in|ios::out);
            string linia;
            while(!p.eof()){
                  getline(p,linia);
                  this->dlugosc++;                          //funkcja tworzy tablice i w zaleznosci od jej przeznaczenia jest tablica string badz tez tablica int
            }
            p.close();
            this->ranking=new T*[this->dlugosc];
            for (int i=0;i<this->dlugosc;i++){
                  if (this->z=='s'){
                        this->ranking[i]=new T[3];
                  }
                  else if(this->z=='i'){
                        this->ranking[i]=new T[1];
                  }
            }
      }

template<typename T>
void Ranking<T>::wczytaj(){
            fstream p;
            p.open("ranking.txt",ios::in);
            string pom;
            int i=0;
            while(!p.eof()){
                  getline(p,pom,'\t');
                  this->ranking[i][0]=pom;                       //wczytywanie wartosci z pliku ranking do tablicy string
                  getline(p,pom,'\t');
                  this->ranking[i][1]=pom;
                  getline(p,pom,'\t');
                  this->ranking[i][2]=pom;
                  getline(p,pom,'\n');
                  i++;
            }


            p.close();
      }

template<typename T>
void Ranking<T>::wczytaj_int(){
            fstream p;
            p.open("ranking.txt",ios::in);
            string pom;
            int i=0;
            while(i<this->dlugosc-1){
                  getline(p,pom,'\t');
                  getline(p,pom,'\t');                            //wczytywanie wartosci z pliku ranking do tablicy int
                  this->ranking[i][0]=stoi(pom);
                  getline(p,pom,'\t');
                  getline(p,pom,'\n');
                  i++;
            }
            p.close();
      }

template<typename T>
void Ranking<T>::wypisz(int ile){
            if(ile<=this->dlugosc-1 && ile >=0){
                  cout<<"TOP "<<ile<<endl;
                  cout<<"-------------------------------"<<endl;
                  for(int i=0;i<ile;i++){
                        cout<<i+1<<". "<<this->ranking[i][0]<<"\t"<<this->ranking[i][1]<<"\t"<<this->ranking[i][2]<<endl;
                  }
                  cout<<"-------------------------------"<<endl;
            }
            else if (ile < 0){
                  cout<<"WSZYSTKIE"<<endl;
                  cout<<"-------------------------------"<<endl;
                  for(int i=0;i<this->dlugosc-1;i++){
                        cout<<i+1<<". "<<this->ranking[i][0]<<"\t"<<this->ranking[i][1]<<"\t"<<this->ranking[i][2]<<endl;                 //wypisywanie zawartosci tablicy stringow
                  }
                  cout<<"-------------------------------"<<endl;
            }
            else{
                  cout<<"TOP "<<ile<<endl;
                  cout<<"-------------------------------"<<endl;
                  for(int i=0;i<this->dlugosc-1;i++){
                        cout<<i+1<<". "<<this->ranking[i][0]<<"\t"<<this->ranking[i][1]<<"\t"<<this->ranking[i][2]<<endl;
                  }
                  cout<<"-------------------------------"<<endl;
                  cout<<"NIE MA WIECEJ WYNIKOW"<<endl;
            }
      }

template<typename T>
void Ranking<T>::suma(){
            int sum=0;
            for (int i=0;i<this->dlugosc-1;i++){
                  sum=sum+this->ranking[i][0];
            }
            cout<<"SUMA WSZYSTKICH WYNIKOW"<<endl;
            cout<<"------------------------"<<endl<<sum;
      }
