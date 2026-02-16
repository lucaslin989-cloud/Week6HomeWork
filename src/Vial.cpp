#include "Vial.h"
#include <iostream>
using namespace std;

Vial::Vial() {
    for (int i = 0; i < 4; i++) contents[i] = ' ';
    filled = 0;
    label = 0;
}

bool Vial::add(char content){
    if(filled>=4){
        return false;
    }
    contents[filled]=content;
    filled++;
    return true;
}

void Vial::display(){
    cout<<"("
    <<contents[0]
    <<contents[1]
    <<contents[2]
    <<contents[3]
    <<"|";
}

bool Vial::isComplete(){
    if (contents[0] == contents[1] &&
        contents[1] == contents[2] &&
        contents[2] == contents[3]){
        return true;
    }else{
        return false;
    }
}

void Vial::setLabel(int label){
    this->label=label;
}

bool Vial::transfer(Vial& destination){
    if (filled==0){
        cout<<"Source vial is empty. "<<endl;
        return false;
    }
    if(destination.filled==4){
        cout<<"Destination vial is filled. "<<endl;
        return false;
    }
    char sourceTop=contents[filled-1];
    if (destination.filled>0){
        char destTop=destination.contents[destination.filled-1];
        if (sourceTop!=destTop){
            cout<<"Content do not match. \n";
            return false;
        }
    }
    destination.contents[destination.filled]=sourceTop;
    contents[filled-1]=' ';
    filled-=1;
    destination.filled+=1;
    
    return true;
}
