#include <bits/stdc++.h>
using namespace std;

bool cube::finalCheck(int face, int pos){
    if(bitSelect(faces[face], 4*(pos+1)-1, 4*pos)) return true;
    return false;
}

set<int> cube::adjcolor(int face, int pos){
    set<int> col;
    switch(face){
        case 0: R(); L_prime(); break;
        case 1: L(); R_prime(); break; 
        case 3: LeftRotate();LeftRotate();break;
        case 4: LeftRotate();break;
        case 5: RightRotate();break;
    }
    switch(pos){
        case 1: L_prime(); col.insert((bitSelect(faces[2], 31, 28)>>28)); L();
                D(); col.insert((bitSelect(faces[2], 15, 12)>>12)); D_prime(); break;
        case 3: R(); col.insert((bitSelect(faces[2], 23, 20)>>20)); R_prime();
                D_prime(); col.insert((bitSelect(faces[2], 7, 4)>>4)); D(); break;
        case 5: R_prime(); col.insert((bitSelect(faces[2], 15, 12)>>12)); R();
                U(); col.insert((bitSelect(faces[2], 31, 28)>>28)); U_prime(); break;
        case 7: L(); col.insert((bitSelect(faces[2], 7, 4)>>4)); L_prime();
                U_prime(); col.insert((bitSelect(faces[2], 23, 20)>>20)); U(); break;
    }
    switch(face){
        case 0: L(); R_prime(); break;
        case 1: R(); L_prime(); break;
        case 3: RightRotate();RightRotate();break;
        case 4: RightRotate();break;
        case 5: LeftRotate();break;
    }

    return col;

    
}

set<int> cube::findCorner(unsigned int face,int color, int f){
    set<int>ans;
    for (int i = 1; i < 8; i+=2)
    {
        int temp = bitSelect(face,4*(i+1)-1,4*i);
        temp = temp>>(4*i);
        bool flag = true;
        if(temp==color){
            if(f == 0){
                set<int> col = adjcolor(0, i);
                switch(i){
                    case 1: if(col.find(3)!=col.end() && col.find(5)!=col.end()) flag = false; break;
                    case 3: if(col.find(3)!=col.end() && col.find(4)!=col.end()) flag = false; break;
                    case 5: if(col.find(2)!=col.end() && col.find(4)!=col.end()) flag = false; break;
                    case 7: if(col.find(2)!=col.end() && col.find(5)!=col.end()) flag = false; break;
                }
            }
            if(flag) ans.insert(i);
        }
    }
    return ans;
}    

set<int> cube::whiteCheck(){
    set<int>ans;
    for (int i = 1; i < 8; i+=2)
    {
        int temp = bitSelect(faces[0],4*(i+1)-1,4*i);
        temp = temp>>(4*i);
        bool flag = false;
        if(temp==0){
            set<int> col = adjcolor(0, i);
            switch(i){
                case 1: if(col.find(3)!=col.end() && col.find(5)!=col.end()) flag = true; break;
                case 3: if(col.find(3)!=col.end() && col.find(4)!=col.end()) flag = true; break;
                case 5: if(col.find(2)!=col.end() && col.find(4)!=col.end()) flag = true; break;
                case 7: if(col.find(2)!=col.end() && col.find(5)!=col.end()) flag = true; break;
            }
            for(auto x: col){
                cout<<x<<" - ";
            }
            cout<<"  &  "<<endl;
            
            if(flag) ans.insert(i);
        }
    }
    return ans;
}

void cube::firstLayer(){
    while(true){
        set<int> whitesOnPos = whiteCheck();
        if(whitesOnPos.size() == 4) break;
        cout<<whitesOnPos.size()<<"  ..  ";
        
        int moveMask = (1<<12) - 1;
        moveMask = bitSelect(moveMask,7,6)^moveMask;// U moves removed
        if(whitesOnPos.find(1)!=whitesOnPos.end())moveMask ^= ((1<<2)+(1<<11)); // L and B' removed
        if(whitesOnPos.find(3)!=whitesOnPos.end())moveMask ^= ((1<<1)+(1<<10));// B and R' moves removed
        if(whitesOnPos.find(5)!=whitesOnPos.end())moveMask ^= ((1<<0)+(1<<9));// R and F' moves removed
        if(whitesOnPos.find(7)!=whitesOnPos.end())moveMask ^= ((1<<3)+(1<<8));// L' and F moves removed
        
        pair<int,int>currwhite;
        
        for (int i = 0; i < 6; i++)
        {
            set<int>temp;
            temp = findCorner(faces[i],0, i);
            if(temp.size()){
                currwhite = {i,*temp.begin()};
                break;
            }
            
            
        }

        set <int> adjcol = adjcolor(currwhite.first, currwhite.second);
        int finalWhitePos;
        for(auto x: adjcol){
                cout<<x<<" -- ";
            }
            cout<<"  %  ";
            
        if(adjcol.find(3)!=adjcol.end() && adjcol.find(5)!=adjcol.end()) finalWhitePos = 1;
        if(adjcol.find(3)!=adjcol.end() && adjcol.find(4)!=adjcol.end()) finalWhitePos = 3;
        if(adjcol.find(2)!=adjcol.end() && adjcol.find(4)!=adjcol.end()) finalWhitePos = 5;
        if(adjcol.find(2)!=adjcol.end() && adjcol.find(5)!=adjcol.end()) finalWhitePos = 7;

        cout<<currwhite.first<<" -- "<<currwhite.second<<" {} "<<finalWhitePos<<"// ";
        // vector<unsigned int>visited(6,0);
        vector<unsigned int>temp(6,0);
        temp[currwhite.first]|=(1<<((currwhite.second+1)*4)) - (1<<((currwhite.second)*4));
        // visited[currwhite.first]|=(1<<((currwhite.second+1)*4)) - (1<<((currwhite.second)*4));
        cube tempCube(temp);
        queue<tuple<cube,int, vector<int>>>q;
        vector<int> v;
        q.push({tempCube,moveMask,v});
        vector<int>MoveOrder;
        // 6th bit to check the move
        while(!q.empty()){
            // cout<<"in ";
            cube curr = get<0>(q.front());
            int currmoveMask = get<1>(q.front());
            vector<int> moves = get<2>(q.front());q.pop();
            for (int i = 0; i < 12; i++)
            {
                int tempMask = (1<<12) -1;
                if((currmoveMask>>i)&1){
                    cube pushCube = curr;
                    moves.push_back(i+1);
                    switch (i) {
                    case 0:
                        pushCube.R();
                        if(((currmoveMask>>6)&1) == 0) tempMask &= ((1<<1)+(1<<4)+(1<<5)+(1<<6));
                        else tempMask = moveMask;                 
                        q.push({pushCube,tempMask,moves});
                        break;
                    case 1:
                        pushCube.R_prime();
                        if(((currmoveMask>>6)&1) == 0) tempMask &= ((1)+(1<<4)+(1<<5)+(1<<6));
                        else tempMask = moveMask;                 
                        q.push({pushCube,tempMask,moves});
                        break;
                    case 2:
                        pushCube.L();
                        if(((currmoveMask>>6)&1) == 0) tempMask &= ((1<<3)+(1<<4)+(1<<5)+(1<<6));
                        else tempMask = moveMask;                 
                        q.push({pushCube,tempMask,moves});
                        break;
                    case 3:
                        pushCube.L_prime();
                        if(((currmoveMask>>6)&1) == 0) tempMask &= ((1<<2)+(1<<4)+(1<<5)+(1<<6));
                        else tempMask = moveMask;                 
                        q.push({pushCube,tempMask,moves});
                        break;
                    case 4:
                        pushCube.U();
                        q.push({pushCube,currmoveMask, moves});
                        break;
                    case 5:
                        pushCube.U_prime();
                        q.push({pushCube,currmoveMask, moves});
                        // pushCube.mark(visited,5);
                        break;
                    case 8:
                        pushCube.F();
                        if(((currmoveMask>>6)&1) == 0) tempMask &= ((1<<9)+(1<<4)+(1<<5)+(1<<6));
                        else tempMask = moveMask;                 
                        q.push({pushCube,tempMask,moves});
                        break;
                    case 9:
                        pushCube.F_prime();
                        if(((currmoveMask>>6)&1) == 0) tempMask &= ((1<<8)+(1<<4)+(1<<5)+(1<<6));
                        else tempMask = moveMask;                 
                        q.push({pushCube,tempMask,moves});
                        break;
                    case 10:
                        pushCube.B();
                        if(((currmoveMask>>6)&1) == 0) tempMask &= ((1<<11)+(1<<4)+(1<<5)+(1<<6));
                        else tempMask = moveMask;                 
                        q.push({pushCube,tempMask,moves});
                        break;
                    case 11:
                        pushCube.B_prime();
                        if(((currmoveMask>>6)&1) == 0) tempMask &= ((1<<10)+(1<<4)+(1<<5)+(1<<6));
                        else tempMask = moveMask;                 
                        q.push({pushCube,tempMask,moves});
                        break;
                    default: break;
                    }
                    if(pushCube.finalCheck(0, finalWhitePos) && ((tempMask>>6)&1) == 0){
                        MoveOrder = moves;
                        break;
                    }
                    moves.pop_back();
                }
            }
            if(MoveOrder.size()) break;
        }
        for(auto u:MoveOrder){
            cout<<u<<" +  ";
            switch (u)
            {
            case 1:R(); break;
            case 2:R_prime(); break;
            case 3:L(); break;
            case 4:L_prime(); break;
            case 5:U(); break;
            case 6:U_prime(); break;
            case 7:D(); break;
            case 8:D_prime(); break;
            case 9:F(); break;
            case 10:F_prime(); break;
            case 11:B(); break;
            case 12:B_prime(); break;
            }
        }
        cout<<endl;



    }
}