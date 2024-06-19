#include "CubeClass.h"
#include "Visualize.h"
#include "Scramble.h"
#include "Solve.h"
#include "readInput.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    cube C;

    // C.scramble();
    C.read_input(argv[1]);
    // C.visualize();

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
    
    // C.visualize();
    C.solve();
    // C.yellowCross();
    // C.visualize();
    // C.whiteCross();
    // C.visualize();

    map<int, string> m;
    m[1] = "R"; m[2] = "R\'"; m[3] = "L"; m[4] = "L\'"; m[5] = "U"; m[6] = "U\'"; 
    m[7] = "D"; m[8] = "D\'"; m[9] = "F"; m[10] = "F\'"; m[11] = "B"; m[12] = "B\'";
    m[13] = "LR"; m[14] = "RR";
    // cout<<C.moves.size()<<endl;
    for(auto x: C.moves){
        // cout<<x<<" - ";
        cout<<m[x]<<" ";
    }
    return 0;
}