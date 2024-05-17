#include "CubeClass.h"
#include "RightMoves.h"
#include "LeftMoves.h"
#include "UpMoves.h"
#include "DownMoves.h"
#include "Visualize.h"
#include "Rotates.h"
#include "FrontMoves.h"
#include "BackMoves.h"
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