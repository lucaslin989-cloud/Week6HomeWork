#include <iostream>
#include "Vial.h"
#include <string>
#include <cstdlib>
#include <ctime>

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
    
    while(true){
        bool allComplete={vial[0].isComplete()&&vial[1].isComplete()&&vial[2].isComplete()&&vial[3].isComplete()&&vial[4].isComplete()};
        if (allComplete) break;
        cout<<"Source, Destination: ";
        cin>>source;cin>>destination;
        if (source<1 || source>5 ||destination<1||destination>5){
            cout<<"Enter number 1-5 \n";continue;
        }else if (source==destination){
            cout<<"Source and Continue couldn't be same.\n";continue;
        }
        if (vial[source-1].transfer(vial[destination-1]))moves++;
        cout<<"Moves taken: "<<moves<<endl;
        for (int i = 0; i < 5; i++) {
            cout << (i+1) << " ";
            vial[i].display();
            cout << endl;
        }
    }
    cout<<"You win";
    return 0;
}