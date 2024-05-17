#include "CubeClass.h"
#include "Moves/RightMoves.h"
#include "Moves/LeftMoves.h"
#include "Moves/UpMoves.h"
#include "Moves/DownMoves.h"
#include "Visualize.h"
#include "Moves/Rotates.h"
#include "Moves/FrontMoves.h"
#include "Moves/BackMoves.h"
#include <bits/stdc++.h>
using namespace std;

int main(){
    cube C;
    C.R();
    C.visualize();
    C.D_prime();
    C.visualize();
    C.U();
    return 0;
}