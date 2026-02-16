#include <iostream>
#include "Vial.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <list>

using namespace std;

int main(){
     srand(time(0));
    int moves=0;
    int source=0;
    int destination=0;

    cout<<"Simple Sort Puzzle\n"<<endl;
    cout<<"Moves taken: "<<moves<<endl;

    int place=0;

    Vial vial[5];
    char value[16]={
    'a','a','a','a',
    'b','b','b','b',
    'c','c','c','c',
    'd','d','d','d'
    };
    while(place<16){
        int randomVial = rand() % 4;    
        int randomValue = rand() % 16;   
        if (value[randomValue]=='-') continue;
        if (!vial[randomVial].add(value[randomValue])) continue;
        value[randomValue] = '-';
        place++;
        
    }
for (int i = 0; i < 5; i++) {
    cout << (i+1) << " ";
    vial[i].display();
    cout << endl;
}

    return 0;
}