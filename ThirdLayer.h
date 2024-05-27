#include <bits/stdc++.h>
using namespace std;


void cube::move1(){
    F(); R(); U(); R_prime(); U_prime(); F_prime();
}

void cube::move2(){
    F(); U(); R(); U_prime(); R_prime(); F_prime();
}


void cube::thirdLayer(){
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