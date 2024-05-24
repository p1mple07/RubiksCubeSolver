#include "Moves/Rotates.h"
#include "Moves/FrontMoves.h"
#include "Moves/BackMoves.h"
#include "Moves/RightMoves.h"
#include "Moves/LeftMoves.h"
#include "Moves/UpMoves.h"
#include "Moves/DownMoves.h"
#include <bits/stdc++.h>
using namespace std;

set<int> cube::findEdge(unsigned int face,int color){
    set<int>ans;
    for (int i = 0; i < 8; i+=2)
    {
        int temp = bitSelect(face,4*(i+1)-1,4*i);
        temp = temp>>(4*i);
        if(temp==color){
            ans.insert(i);
        }
    }
    return ans;
}    
bool cube::check(vector<unsigned int>&visi){
    for (int i = 0; i < 6; i++)
    {
        if(faces[i]!=0){
            if(((~visi[i])&faces[i])==faces[i]){
                return true;
            }
            else return false;
        }
    }
    
}
void cube::mark(vector<unsigned int>&visited,int move){
    for (int i = 0; i < 6; i++)
    {
        if(faces[i]!=0){
            for (int j = 0; j < 8; j+=2)
            {
                if(bitSelect(faces[i],(j+1)*4-1,j*4)){
                    visited[i]|=(move<<(4*j));
                    return;
                }
            }
        }
    }
}
unsigned int move(vector<unsigned int>visi,int face,int edge){
    return (bitSelect(visi[face],4*(edge+1)-1,4*edge))>>(4*edge);
}
pair<int,int> cube::positionEdge(){
    for (int i = 0; i < 6; i++)
    {
        if(faces[i]){
            for (int j = 0; j < 8; j+=2)
            {
                if(bitSelect(faces[i],4*(j+1)-1,4*j)){
                    return {i,j};
                }
            }
        }
    }
}

void cube::yellowCross(){
    while (true)
    {
        set<int>whiteonY = findEdge(faces[1],0);
        cout<<whiteonY.size()<<" ";
        if(whiteonY.size()==4)return;
        int moveMask = (1<<12) - 1;
        // moveMask = bitSelect(moveMask,5,4)^moveMask;// U moves removed
        if(whiteonY.find(0)!=whiteonY.end())moveMask = bitSelect(moveMask,3,2)^moveMask;// L moves removed
        if(whiteonY.find(2)!=whiteonY.end())moveMask = bitSelect(moveMask,9,8)^moveMask;// F moves removed
        if(whiteonY.find(4)!=whiteonY.end())moveMask = bitSelect(moveMask,1,0)^moveMask;// R moves removed
        if(whiteonY.find(6)!=whiteonY.end())moveMask = bitSelect(moveMask,11,10)^moveMask;// B moves removed
        pair<int,int>currwhite;
        for (int i = 0; i < 6; i++)
        {
            set<int>temp;
            if(i!=1){
                temp = findEdge(faces[i],0);
                if(temp.size()){
                    currwhite = {i,*temp.begin()};
                    break;
                }
            }
        }
        vector<unsigned int>visited(6,0);
        vector<unsigned int>temp(6,0);
        temp[currwhite.first]|=(1<<((currwhite.second+1)*4)) - (1<<((currwhite.second)*4));
        visited[currwhite.first]|=(1<<((currwhite.second+1)*4)) - (1<<((currwhite.second)*4));
        cube tempCube(temp);
        queue<pair<cube,int>>q;
        q.push({tempCube,moveMask});
        while(!q.empty()){
            cube curr = q.front().first;
            moveMask = q.front().second;q.pop();
            for (int i = 0; i < 12; i++)
            {
                if((moveMask>>i)&1){
                    cube pushCube = curr;
                    switch (i)
                    {
                    case 0:
                        pushCube.R();
                        if(pushCube.check(visited)){
                            q.push({pushCube,moveMask});
                            pushCube.mark(visited,1);
                        }
                        break;
                    case 1:
                        pushCube.R_prime();
                        if(pushCube.check(visited)){
                            q.push({pushCube,moveMask});
                            pushCube.mark(visited,2);
                        }
                        break;
                    case 2:
                        pushCube.L();
                        if(pushCube.check(visited)){
                            q.push({pushCube,moveMask});
                            pushCube.mark(visited,3);
                        }
                        break;
                    case 3:
                        pushCube.L_prime();
                        if(pushCube.check(visited)){
                            q.push({pushCube,moveMask});
                            pushCube.mark(visited,4);
                        }
                        break;
                    case 4:
                        pushCube.U();
                        // if(pushCube.check(visited)){
                            int tempMask = (1<<12) -1;
                            if(bitSelect(moveMask,3,2)==0){
                                tempMask = bitSelect(tempMask,11,10)^tempMask;// B moves removed
                            }
                            if(bitSelect(moveMask,9,8)==0){
                                tempMask = bitSelect(tempMask,3,2)^tempMask;// L moves removed
                            }
                            if(bitSelect(moveMask,1,0)==0){
                                tempMask = bitSelect(tempMask,9,8)^tempMask;// F moves removed
                            }
                            if(bitSelect(moveMask,11,10)==0){
                                tempMask = bitSelect(tempMask,1,0)^tempMask;// R moves removed
                            }
                            q.push({pushCube,tempMask});
                            pushCube.mark(visited,5);
                        // }
                        break;
                    case 5:
                        pushCube.U_prime();
                        // if(pushCube.check(visited)){
                            int tempMask = (1<<12) -1;
                            if(bitSelect(moveMask,3,2)==0){
                                tempMask = bitSelect(tempMask,9,8)^tempMask;// F moves removed
                            }
                            if(bitSelect(moveMask,9,8)==0){
                                tempMask = bitSelect(tempMask,1,0)^tempMask;// R moves removed
                            }
                            if(bitSelect(moveMask,1,0)==0){
                                tempMask = bitSelect(tempMask,11,10)^tempMask;// B moves removed
                            }
                            if(bitSelect(moveMask,11,10)==0){
                                tempMask = bitSelect(tempMask,3,2)^tempMask;// L moves removed
                            }
                            q.push({pushCube,tempMask});
                            pushCube.mark(visited,5);
                        // }
                        break;
                    case 6:
                        pushCube.D();
                        if(pushCube.check(visited)){
                            q.push({pushCube,moveMask});
                            pushCube.mark(visited,7);
                        }
                        break;
                    case 7:
                        pushCube.D_prime();
                        if(pushCube.check(visited)){
                            q.push({pushCube,moveMask});
                            pushCube.mark(visited,8);
                        }
                        break;
                    case 8:
                        pushCube.F();
                        if(pushCube.check(visited)){
                            q.push({pushCube,moveMask});
                            pushCube.mark(visited,9);
                        }
                        break;
                    case 9:
                        pushCube.F_prime();
                        if(pushCube.check(visited)){
                            q.push({pushCube,moveMask});
                            pushCube.mark(visited,10);
                        }
                        break;
                    case 10:
                        pushCube.B();
                        if(pushCube.check(visited)){
                            q.push({pushCube,moveMask});
                            pushCube.mark(visited,11);
                        }
                        break;
                    case 11:
                        pushCube.B_prime();
                        if(pushCube.check(visited)){
                            q.push({pushCube,moveMask});
                            pushCube.mark(visited,12);
                        }
                        break;
                    }
                }
            }
            if(visited[1])break;
        }
        if(visited[1]){
            vector<unsigned int>temp(6,0);
            for (int i = 0; i < 8; i+=2)
            {
                if(bitSelect(visited[1],(i+1)*4-1,4*i)){
                    temp[1] =(1<<((i+1)*4))- (1<<(4*i));
                    break;
                }
            }            
            cube revCube(temp);
            vector<int>revMoveOrder;
            while (true)
            {
                pair<int,int>edgePos = revCube.positionEdge();
                int currMove = move(visited,edgePos.first,edgePos.second); 
                if(currMove==15)break;
                revMoveOrder.push_back(currMove);
                switch (currMove)
                {
                case 1:
                    revCube.R_prime();
                    break;
                case 2:
                    revCube.R();
                    break;
                case 3:
                    revCube.L_prime();
                    break;
                case 4:
                    revCube.L();
                    break;
                case 5:
                    revCube.U_prime();
                    break;
                case 6:
                    revCube.U();
                    break;
                case 7:
                    revCube.D_prime();
                    break;
                case 8:
                    revCube.D();
                    break;
                case 9:
                    revCube.F_prime();
                    break;
                case 10:
                    revCube.F();
                    break;
                case 11:
                    revCube.B_prime();
                    break;
                case 12:
                    revCube.B();
                    break;
                }
            }
            reverse(revMoveOrder.begin(),revMoveOrder.end());
            cout<<endl;
            for(auto u:revMoveOrder){
                cout<<u<<" - ";
                switch (u)
                {
                case 1:R();
                    break;
                case 2:R_prime();
                    break;
                case 3:L();
                    break;
                case 4:L_prime();
                    break;
                case 5:U();
                    break;
                case 6:U_prime();
                    break;
                case 7:D();
                    break;
                case 8:D_prime();
                    break;
                case 9:F();
                    break;
                case 10:F_prime();
                    break;
                case 11:B();
                    break;
                case 12:B_prime();
                    break;
                }
            }
            
        }
        else{
            cout<<"up";
            U();
        }
    }
}

