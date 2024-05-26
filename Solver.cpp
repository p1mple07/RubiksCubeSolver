#include "CubeClass.h"
#include "Visualize.h"
#include "WhiteCross.h"
#include "Scramble.h"
#include <bits/stdc++.h>
using namespace std;

int main(){
    cube C;
    C.scramble();
    C.visualize();
    C.yellowCross();
    C.visualize();
    C.whiteCross();
    C.visualize();
    return 0;
}