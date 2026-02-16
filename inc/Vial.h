#pragma once

#include<string>
using namespace std;

class Vial{
    private:
        char contents[4];
        int filled;
        int label;
    public:
        Vial();
        Vial(char contents[], int size, int filled);
        Vial(char c1, char c2, char c3, char c4);
        bool add(char content);
        void display();
        bool isComplete();
        void setLabel(int label);
        bool transfer(Vial& destination);
};