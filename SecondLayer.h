#include <bits/stdc++.h>
using namespace std;

set<int> cube::secondLayerNotOnPos(){
    int c = 0;
    set<int> s;
    for (int i = 0; i < 4; i++)
    {
        if((bitSelect(faces[2], 19, 16)>>16) == (bitSelect(faces[2], 15, 12)>>12)
         && (bitSelect(faces[4], 3, 0)) == (bitSelect(faces[4], 7, 4)>>4)){
            c = 0; // not needed
         }
        else{
            s.insert(i);
        }
        LeftRotate();
    }
    return s;
    
}

void cube::tempMove_R(){
    U(); R(); U(); R_prime(); U_prime(); F_prime(); U_prime(); F();
    vector<int> v = {5, 1, 5, 2, 6, 10, 6, 9};
    for(auto x: v) moves.push_back(x);
}

void cube::tempMove_L(){
    U_prime(); L_prime(); U_prime(); L(); U(); F(); U(); F_prime();
    vector<int> v = {6, 4, 6, 3, 5, 9, 5, 10};
    for(auto x: v) moves.push_back(x);
}


void cube::secondLayer(){
    while(true){
        bool flag = false;
        int col1, col2;
        for (int m = 0; m < 4; m++)
        {
            col1 = (bitSelect(faces[2], 27, 24)>>24);
            col2 = (bitSelect(faces[1], 11, 8)>>8);
            if(col1 != 1 && col2 != 1){
                flag = true;
                break;
            }
            moves.push_back(5);
            U();
        }

        if(!flag){
            set<int> SLNotOnPos = secondLayerNotOnPos();
            if(SLNotOnPos.size() == 0) break;
            int numOfLR = *(SLNotOnPos.begin());
            for (int i = 0; i < numOfLR; i++)
            {
                LeftRotate();
                moves.push_back(13);
            }
            tempMove_R();
            for (int i = 0; i < numOfLR; i++)
            {
                RightRotate();
                moves.push_back(14);
            }
            
        }
        else{
            switch(col1){
                case 2: if(col2 == 4) tempMove_R();
                        else if(col2 == 5) tempMove_L();
                        break;
                case 3: LeftRotate(); LeftRotate(); U(); U();
                        moves.insert(moves.end(), {13, 13, 5, 5});
                        if(col2 == 5) tempMove_R();
                        else if(col2 == 4) tempMove_L();
                        LeftRotate(); LeftRotate();
                        moves.insert(moves.end(), {13, 13});
                        break;
                case 4: LeftRotate(); U_prime();
                        moves.insert(moves.end(), {13, 6});
                        if(col2 == 3) tempMove_R();
                        else if(col2 == 2) tempMove_L();
                        moves.push_back(14);
                        RightRotate();
                        break;
                case 5: RightRotate(); U();
                        moves.insert(moves.end(), {14, 5});
                        if(col2 == 2) tempMove_R();
                        else if(col2 == 3) tempMove_L();
                        moves.push_back(13);
                        LeftRotate();
                        break;
            }
        }



        

    }
}


