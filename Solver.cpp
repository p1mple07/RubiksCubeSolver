#include "CubeClass.h"
#include "Visualize.h"
#include "Scramble.h"
#include "Solve.h"
#include <bits/stdc++.h>
using namespace std;

int main(){
    cube C;
    C.scramble();

    // C.L_prime();
    // C.U();
    // C.L();
    // C.B();
    // C.U();
    // C.B_prime();
    // C.B_prime();
    // C.U_prime();
    // C.B();
    // C.R();
    // C.U();
    // C.R_prime();
    // C.U_prime();
    // C.R();
    // C.U();
    // C.R_prime(); 
    
    C.visualize();
    C.solve();
    // C.yellowCross();
    // C.visualize();
    // C.whiteCross();
    C.visualize();
    return 0;
}