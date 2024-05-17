#include <bits/stdc++.h>
using namespace std;
void cube::F(){
    LeftRotate();
    L();
    RightRotate();
}
void cube::F_prime(){
    LeftRotate();
    L_prime();
    RightRotate();
}
void cube::F2(){
    cube::F();
    cube::F();
}
