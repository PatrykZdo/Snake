#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>
#include "Jedzenie.h"
#include "Plansza.h"
#include "Postac.h"
#include "Snake.h"
#include "Ranking.h"
#include "Ranking.cpp"

using namespace std;

void zasady(HANDLE hConsole){
      system("cls");
      cout<<"\t\t\t\t \t\t\t ZASADY GRY\t\t"<<endl;
      cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
      cout<<"Sterowanie wezem odbywa sie za pomoca klawiszy 'W' 'S' 'A' 'D' "<<endl;
      SetConsoleTextAttribute(hConsole,14);
      cout<<"'W'-> gora"<<endl;
      cout<<"'S'-> dol"<<endl;
      cout<<"'A'-> lewo"<<endl;
      cout<<"'D'-> prawo"<<endl;
      cout<<endl;
      cout<<"Aby Waz ruszyl nalezy kliknac jeden z wyrzej wymienionych klawiszy"<<endl;
      SetConsoleTextAttribute(hConsole,15);
      cout<<"Waz na starcie ma rozmiar '0'. Z kazdym zjedzonym jabuszkiem jego rozmiar rosnie o '1'"<<endl;
      cout<<"Waz jest oznaczony cyfra '";
      SetConsoleTextAttribute(hConsole,10);                                                                                                           //zasady gry oraz zapoznanie uzytkownika z programem
      cout<<"7";
      SetConsoleTextAttribute(hConsole,15);
      cout<<"' natomiast jabuszko cyfra '";
      SetConsoleTextAttribute(hConsole,12);
      cout<<"2";
      SetConsoleTextAttribute(hConsole,15);
      cout<<"'"<<endl;
      cout<<"Koniec gry nastepuje gdy Waz zje samego siebie."<<endl;
      SetConsoleTextAttribute(hConsole,14);
      cout<<"WAZ MOZE PRZECHODZIC PRZEZ SCIANY!!!"<<endl;
      SetConsoleTextAttribute(hConsole,15);
      cout<<endl;
      cout<<"W karcie 'OPCJE' mozna zmienic poziom trudnosci oraz rozmiar planszy"<<endl;
      cout<<"Im wyzszy poziom trudnosci tym wiekszy mnoznik punktow"<<endl;
      cout<<endl;
      cout<<endl;
      cout<<endl;

      SetConsoleTextAttribute(hConsole,10);
      cout<<"\t\t\t\t\t ZAGRAJ I ZAPISZ SIE NA KARCIE REKORDOW!!!\t\t"<<endl;
      SetConsoleTextAttribute(hConsole,15);
      cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
  cout<<endl;  cout<<endl;  cout<<endl;



}

void menu(){
      cout<<"|-------------------------------------------------------------------------------|\n";
      cout<<"|\t                                                                  \t|\n";
      cout<<"|\t    ssssss    nnnnn   nnnnn    aaaaa    kkkkk    kkkkk  eeeeeeeeee\t|\n";
      cout<<"|\t   ssssssss   nnnnn   nnnnn    aaaaa    kkkkk   kkkkk   eeeeeeeeee\t|\n";
      cout<<"|\t   ssss       nnn nn  nnnnn   aaa aaa   kkkkk  kkkkk    eeee      \t|\n";
      cout<<"|\t    sssss     nnn  nn nnnnn  aaa   aaa  kkkkk kkkkk     eeeeeeeeee\t|\n";
      cout<<"|\t       sss    nnn   nnnnnnn  aaa   aaa  kkkkkkkkkk      eeeeeeeeee\t|\n";
      cout<<"|\t       ssss   nnn    nnnnnn  aaaaaaaaa  kkkkk kkkkk     eeee      \t|\n";
      cout<<"|\t   ssssssss   nnn     nnnnn  aaa   aaa  kkkkk  kkkkk    eeeeeeeeee\t|\n";
      cout<<"|\t    ssssss    nnn      nnnn  aaa   aaa  kkkkk   kkkkk   eeeeeeeeee\t|\n";
      cout<<"|\t                                                                  \t|\n";
      cout<<"|\t                                                                  \t|\n";
      cout<<"|\t                                                                  \t|\n";
      cout<<"|\t                          1.Graj                                  \t|\n";                                     //Panel glowny programu
      cout<<"|\t                          2.Opcje                                 \t|\n";
      cout<<"|\t                          3.Ranking                               \t|\n";
      cout<<"|\t                          4.Koniec                                \t|\n";
      cout<<"|\t                                                                  \t|\n";
      cout<<"|\t                                                                  \t|\n";
      cout<<"|\t                                                                  \t|\n";
      cout<<"|\t                                                                  \t|\n";
      cout<<"|\t                                                                  \t|\n";
      cout<<"|-------------------------------------------------------------------------------|";



      }

int Snake::trudnosc;
int Snake::rozmiar;


      void zapisywanie(int wynik,string nazwa,int szerokosc,int wysokosc){
            fstream plik;
            plik.open("ranking.txt",ios::in|ios::out|ios::app);
            if(plik.good()==true){
                  plik<<nazwa<<"\t"<<wynik<<"\t"<<szerokosc<<"X"<<wysokosc<<"\t\n";                   //funckja odpowiadaj¹ca za zaspisywanie wyniku gracza do pliku z rankingiem graczy
                  plik.close();
            }
            else{
                  cout<<"ERROR";
            }

      }

      void sortowanie (Ranking<string> *ran){
            for (int i=0;i<ran->dlugosc-1 ;i++){
                  for (int j=i;j<ran->dlugosc-1;j++){
                        if(stoi(ran->ranking[i][1])<stoi(ran->ranking[j][1])){
                              string pom;
                              pom=ran->ranking[i][1];
                              ran->ranking[i][1]=ran->ranking[j][1];
                              ran->ranking[j][1]=pom;                                                 //sortowanie rankingu od najwiekszego wyniku do najmniejszego

                              pom=ran->ranking[i][0];
                              ran->ranking[i][0]=ran->ranking[j][0];
                              ran->ranking[j][0]=pom;

                              pom=ran->ranking[i][2];
                              ran->ranking[i][2]=ran->ranking[j][2];
                              ran->ranking[j][2]=pom;
                        }
                  }
            }
      }



int main()
{
      srand(time(nullptr));
      HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      bool run=true;
      char wskaz;
      int szerokosc=10,wysokosc=10;
      Snake::trudnosc=400;
      Postac *wsk;



      zasady(hConsole);
      system("pause");
      system("cls");
      while(run){
            menu();
            if(_kbhit()){
                  wskaz=_getch();
            }


            if(wskaz=='1'){
                  bool game_over=true;                                        //Graj snake
                  wskaz=NULL;
                  Plansza * p1=new Plansza(szerokosc,wysokosc);
                  Jedzenie *J=new Jedzenie(*p1);
                  Snake *s=new Snake(*p1);
                  wsk=&*s;
                  p1->terytorium();
                  while(game_over){
                        system("cls");
                        if(_kbhit()){
                              s->znak=_getch();
                        }
                        wsk->poruszanie(*p1);
                        if(s->czyZjedzone(*J)){                               //Jedzenie Jablka
                              wsk->jedzenie();
                              J->jablko(*p1);
                        }
                        game_over=s->gameOver(*p1);
                        s->inicjalizacja(*p1,*J);
                        p1->rysuj_plansze(hConsole);
                        cout<<"SCORE: "<<s->wynik();
                        Sleep(Snake::trudnosc);

                  }
                  s->znak='c';
                  system("cls");
                  cout<<"GAME OVER!!!";
                  Sleep(500);


                  char *zapis=new char;
                  system("cls");
                  cout<<"Czy chcesz zapisac swoj wynik?          WYNIK: "<<s->wynik()<<endl;
                  cout<<"------------------------------------------------------"<<endl;
                  cout<<"1. Tak"<<endl;
                  cout<<"2. Nie"<<endl;
                  cin>>zapis;
                  if(*zapis=='1'){
                        string nazwa;

                        system("cls");
                        cout<<"1. Podaj nazwe: "<<endl;
                        cin>>nazwa;
                        zapisywanie(s->wynik(),nazwa,szerokosc,wysokosc);
                  }
                  else{
                        system("cls");
                        continue;
                  }
                  delete zapis,p1,s,J;

            }



            else if(wskaz=='2'){                                                          //Opcje
                  wskaz=NULL;
                  char *z=new char;
                  bool opcje=true;

                  while(opcje){
                        system("cls");
                        cout<<"OPCJE"<<endl;
                        cout<<"-------------------"<<endl;
                        cout<<"1. Zmien Wysokosc\t\t";
                        SetConsoleTextAttribute(hConsole,10);
                        cout<<szerokosc<<endl;                                            // menu opcji
                        SetConsoleTextAttribute(hConsole,15);
                        cout<<"2. Zmien Szerokosc\t\t";
                        SetConsoleTextAttribute(hConsole,10);
                        cout<<wysokosc<<endl;
                        SetConsoleTextAttribute(hConsole,15);
                        cout<<"3. Zmien Poziom Trudnosci\t";
                        if(Snake::trudnosc==400){
                              SetConsoleTextAttribute(hConsole,10);
                              cout<<"Latwy"<<endl;
                        }
                        else if(Snake::trudnosc==200){
                              SetConsoleTextAttribute(hConsole,14);
                              cout<<"Sredni"<<endl;
                        }
                        else if(Snake::trudnosc==100){
                              SetConsoleTextAttribute(hConsole,12);
                              cout<<"Trudny"<<endl;
                        }

                        SetConsoleTextAttribute(hConsole,15);
                        cout<<"4. Wyjdz"<<endl;

                        if(_kbhit()){
                              *z=_getch();
                              if(*z=='1'){
                                    system("cls");
                                    cout<<"Podaj Wysokosc: ";                             //Zmiana wysokosci
                                    cin>>szerokosc;
                              }
                              else if(*z=='2'){
                                    system("cls");
                                    cout<<"Podaj Szerokosc: ";                           //Zmiana szerokosci
                                    cin>>wysokosc;
                              }
                              else if(*z=='3'){
                                    while(true){
                                          system ("cls");
                                          cout<<"Poziom Trudnosci"<<endl;
                                          cout<<"----------------"<<endl;
                                          cout<<"1.";
                                          SetConsoleTextAttribute(hConsole,10);
                                          cout<<"Latwy"<<endl;
                                          SetConsoleTextAttribute(hConsole,15);
                                          cout<<"2.";
                                          SetConsoleTextAttribute(hConsole,14);
                                          cout<<"Sredni"<<endl;
                                          SetConsoleTextAttribute(hConsole,15);
                                          cout<<"3.";
                                          SetConsoleTextAttribute(hConsole,12);
                                          cout<<"Trudny"<<endl;
                                          if(_kbhit()){
                                                *z=_getch();
                                                if(*z=='1'){
                                                      Snake::trudnosc=400;
                                                      break;
                                                }
                                                else if(*z=='2'){
                                                      Snake::trudnosc=200;
                                                      break;                                //Zmiana trudności
                                                }
                                                else if(*z=='3'){
                                                      Snake::trudnosc=100;
                                                      break;
                                                }
                                          }
                                          Sleep(200);
                                    SetConsoleTextAttribute(hConsole,15);
                                    }
                                    SetConsoleTextAttribute(hConsole,15);

                              }
                              else if(*z=='4'){
                                    opcje=false;
                              }
                        }
                        Sleep(200);
                        system("cls");
                  }
                  delete z;
            }



            else if(wskaz=='3'){
                  wskaz=NULL;
                  char *z=new char;
                  bool ranking=true;


                  system("cls");


                  while(ranking){

                        cout<<"Ile pozycji chcesz zobaczyc?"<<endl;
                        cout<<"----------------------------"<<endl;
                        cout<<"1. TOP 3"<<endl;
                        cout<<"2. TOP 10"<<endl;
                        cout<<"3. WSZYSTKIE"<<endl;
                        cout<<"4. SUMA WSZYSTKICH WYNIKOW"<<endl;
                        cout<<"5. WYJDZ"<<endl;
                        if(_kbhit()){
                              Ranking<string>*R=new Ranking<string>();
                              *z=_getch();
                              if(*z=='1'){
                                    R->z='s';
                                    R->tworzenieTablic();
                                    R->wczytaj();
                                    sortowanie(R);
                                    system("cls");
                                    R->wypisz(3);
                                    cout<<endl;
                                    cout<<endl;
                                    system("pause");
                              }
                              else if(*z=='2'){
                                    R->z='s';
                                    R->tworzenieTablic();
                                    R->wczytaj();
                                    sortowanie(R);
                                    system("cls");
                                    R->wypisz(10);
                                    cout<<endl;
                                    cout<<endl;
                                    system("pause");
                              }
                              else if(*z=='3'){
                                    R->z='s';
                                    R->tworzenieTablic();
                                    R->wczytaj();
                                    sortowanie(R);
                                    system("cls");
                                    R->wypisz(-1);
                                    cout<<endl;
                                    cout<<endl;
                                    system("pause");
                              }
                              else if(*z=='4'){
                                    delete R;
                                    Ranking<int>*R=new Ranking<int>();
                                    R->z='i';
                                    R->tworzenieTablic();
                                    R->wczytaj_int();
                                    system("cls");
                                    R->suma();
                                    cout<<endl;
                                    cout<<endl;
                                    system("pause");
                                    delete R;
                              }

                              else if(*z=='5'){
                                    ranking=false;
                              }

                        }
                        Sleep(50);
                        system("cls");


                  }
                  delete z;

            }



            else if(wskaz=='4'){
                  run=false;
            }
            Sleep(500);
            system("cls");
            }

      return 0;
}
