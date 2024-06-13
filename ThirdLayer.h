#include <bits/stdc++.h>
using namespace std;


void cube::move1(){
    F(); R(); U(); R_prime(); U_prime(); F_prime();
}

void cube::move2(){
    F(); U(); R(); U_prime(); R_prime(); F_prime();
}

void cube::move3(){
    R(); U2(); R_prime(); U_prime(); R(); U_prime(); R_prime();
}

void cube::move4(){
    L_prime(); U(); R(); U_prime(); L(); U(); R_prime(); U_prime();
}

void cube::move5(){
    move3();
    L_prime(); U2(); L(); U(); L_prime(); U(); L();
}

void cube::thirdYellowCross(){
    while(true){
        set<int> yellowOnPos = findEdge(faces[1], 1);
        if(yellowOnPos.size() == 4) break;
        else if(yellowOnPos.size() == 0){
            move1();
        }
        else if(yellowOnPos.size() == 2){
            auto it = yellowOnPos.begin();
            int pos1 = *it;
            it++;
            int pos2 = *it;
            
            if(pos1==0 && pos2==4) move1();
            else if(pos1==2 && pos2==6){
                U();
                move1();
            }
            else{
                if(pos1==0 && pos2==2){
                    U();
                }
                else if(pos1 == 2 && pos2 == 4){
                    U2();
                }
                else if(pos1==4 && pos2 == 6){
                    U_prime();
                }
                move2();
            }
            

        }

    }
}



void cube:: thirdYellowCrossOnPos(){
    while(true){
        vector<int> centerOnPos;
        for (int i = 2; i < 6; i++)
        {
            if(((bitSelect(faces[i], 27, 24))>>24) == i) {
                centerOnPos.push_back(i);
            }
        }
        if(centerOnPos.size()==4) break;

        if(centerOnPos.size() <= 1){
            U();
            continue;
        }
        // 2 3, 2 4, 2 5, 3 4, 3 5, 4 5
        if(centerOnPos[0]==2 && centerOnPos[1] == 3){U(); move3();}
        if(centerOnPos[0]==2 && centerOnPos[1] == 4){U(); U(); move3();}
        if(centerOnPos[0]==2 && centerOnPos[1] == 5){U(); move3();}
        if(centerOnPos[0]==3 && centerOnPos[1] == 4){U_prime(); move3();}
        if(centerOnPos[0]==3 && centerOnPos[1] == 5){move3();}
        if(centerOnPos[0]==4 && centerOnPos[1] == 5){move3();}
        
    }
}

void cube::cornerOnPos(){
    while(true){
        vector<int> rightCorners;
        for(int i = 0; i<4; i++){
            set<int> tmp;
            tmp.insert((bitSelect(faces[2], 19, 16))>>16);
            tmp.insert(bitSelect(faces[4], 3, 0));
            tmp.insert(1);

            int a = bitSelect(faces[2], 23, 20)>>20;
            int b = bitSelect(faces[4], 31, 28)>>28;
            int c = bitSelect(faces[1], 15, 12)>>12;

            if(tmp.find(a)!=tmp.end() && tmp.find(b)!=tmp.end()&&tmp.find(c)!=tmp.end()){
                rightCorners.push_back(i);
            }
            LeftRotate();
        }
        if(rightCorners.size() == 4) break;
        if(rightCorners.size() == 0){
            move4();
            continue;
        }
        for(int i = 0; i<rightCorners[0]; i++){
            LeftRotate();
        }
        move4();
        for(int i = 0; i<rightCorners[0]; i++){
            RightRotate();
        }

    }
}

void cube::makeCorners(){
    for (int i = 0; i < 4; i++)
    {
        while(((bitSelect(faces[2], 23, 20))>>20) != bitSelect(faces[2], 3, 0)){
            move5();
        }
        LeftRotate();
    }
    
}


void cube::thirdLayer(){

    thirdYellowCross();
    thirdYellowCrossOnPos();
    visualize();
    cornerOnPos();
    makeCorners();
}