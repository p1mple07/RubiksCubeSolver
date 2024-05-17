#include <bits/stdc++.h>
using namespace std;
void cube::B(){
    LeftRotate();
    R();
    RightRotate();
}
void cube::B_prime(){
    LeftRotate();
    R_prime();
    RightRotate();
}
void cube::B2(){
    cube::B();
    cube::B();
}
