#include <bits/stdc++.h>
using namespace std;

unsigned int bitSelect(unsigned int face,int r,int l){
    unsigned int temp = face&((1<<(r+1)) - (1<<l));// error can happen
    return temp;
}

class cube
{
    vector<unsigned int>faces;
    private:
    void LeftRotate();
    void RightRotate();
    public:
    // 0 white
    // 1 yellow
    // 2 blue
    // 3 green 
    // 4 red
    // 5 orange
    cube(){
        faces.resize(6);
        faces[0] =  0;// white
        faces[1] =  stoi("00010001000100010001000100010001", nullptr, 2);// yellow
        faces[2] =  stoi("00100010001000100010001000100010", nullptr, 2);// blue this is towords observer
        faces[3] =  stoi("00110011001100110011001100110011", nullptr, 2);// green
        faces[4] =  stoi("01000100010001000100010001000100", nullptr, 2);// red
        faces[5] =  stoi("01010101010101010101010101010101", nullptr, 2);// orange
    }
    cube(vector<unsigned int>faces1){
        faces = faces1;
    }
    // R,R',R2,L,U,D,B,F,
    void R(); void R2(); void R_prime(); 
    void L(); void L2(); void L_prime(); 
    void U(); void U2(); void U_prime(); 
    void D(); void D2(); void D_prime(); 
    void F(); void F2(); void F_prime();
    void B(); void B2(); void B_prime();
    void visualize();

    bool checkWhiteCross();

    bool check(vector<unsigned int>&visited);
    void mark(vector<unsigned int>&visited,int move);
    set<int> findEdge(unsigned int face,int color);
    void yellowCross();
    void whiteCross();

    bool finalCheck(int face, int pos);
    set <int> adjcolor(int face, int pos);
    set <int> findCorner(unsigned int face, int color, int f); 
    set<int> whiteCheck();
    void firstLayer();

    set<int> secondLayerNotOnPos();
    void tempMove_R();
    void tempMove_L();
    void secondLayer();

    void move1();
    void move2();
    void move3();
    void move4();
    void move5();
    void thirdYellowCross();
    void thirdYellowCrossOnPos();
    void cornerOnPos();
    void makeCorners();
    void thirdLayer();

    
    void solve();
    void scramble();

    pair<int,int> positionEdge();
    void read_input(char *argc);
};
