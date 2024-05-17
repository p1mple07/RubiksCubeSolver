#include <bits/stdc++.h>
using namespace std;

unsigned int bitSelect(unsigned int face,int r,int l){
    unsigned int temp = face&((1<<(r+1)) - (1<<l));// error can happen
    return temp;
}

class cube
{
    unsigned int faces[6];
    public:
    // 0 white
    // 1 yellow
    // 2 blue
    // 3 green 
    // 4 red
    // 5 orange
    cube(){
        faces[0] =  0;// white
        faces[1] =  stoi("00010001000100010001000100010001", nullptr, 2);// yellow
        faces[2] =  stoi("00100010001000100010001000100010", nullptr, 2);// blue this is towords observer
        faces[3] =  stoi("00110011001100110011001100110011", nullptr, 2);// green
        faces[4] =  stoi("01000100010001000100010001000100", nullptr, 2);// red
        faces[5] =  stoi("01010101010101010101010101010101", nullptr, 2);// orange
    }
    // R,R',R2,L,U,D,B,F,
    void R();
    void R_prime();
    void R2();
    void L();
    void L_prime();
    void L2();
    void U();
    void U_prime();
    void U2();
    void D();
    void D_prime();
    void D2();
    void visualize();
};
