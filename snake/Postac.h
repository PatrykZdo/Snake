#ifndef Postac_h
#define Postac_h
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

class Postac{
public:
      virtual void poruszanie(Plansza &P)=0;
      virtual void jedzenie()=0;

};

#endif
