#include "CubeClass.h"
#include "Visualize.h"
#include "WhiteCross.h"
#include <bits/stdc++.h>
using namespace std;

int main(){
    cube C;
    C.R();
    C.L();
    C.U();
    C.D();
    C.B();
    C.F();
    C.U();
    C.D();
    C.U();
    C.D();
    C.L();
    C.U();
    C.D();
    C.B();
    C.visualize();
    C.yellowCross();
    C.visualize();
    return 0;
}