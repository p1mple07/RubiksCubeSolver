#include "Moves/Rotates.h"
#include "Moves/FrontMoves.h"
#include "Moves/BackMoves.h"
#include "Moves/RightMoves.h"
#include "Moves/LeftMoves.h"
#include "Moves/UpMoves.h"
#include "Moves/DownMoves.h"
#include "WhiteCross.h"
#include "FirstLayer.h"
#include "SecondLayer.h"
#include "ThirdLayer.h"
#include <bits/stdc++.h>
using namespace std;

bool cube::checkWhiteCross(){
    int cnt = 0;
    for(int i = 0; i<8; i+=2){
        if((bitSelect(faces[0], 4*(i+1)-1, 4*i)>>(4*i)) == 0){
            switch(i){
                case 0: if((bitSelect(faces[5], 11, 8)>>8) == 5){cnt++;} break;
                case 2: if((bitSelect(faces[3], 11, 8)>>8) == 3){cnt++;} break;
                case 4: if((bitSelect(faces[4], 11, 8)>>8) == 4){cnt++;} break;
                case 6: if((bitSelect(faces[2], 11, 8)>>8) == 2){cnt++;} break;
            }
        }
    }
    if(cnt == 4) return true;
    else return false;
}

void cube::solve(){
    if(!checkWhiteCross()){
        yellowCross();
        whiteCross();
        cout<<"inside\n";
    } 
    firstLayer();
    // visualize();
    secondLayer();
    visualize();
    thirdLayer();
    visualize();
}