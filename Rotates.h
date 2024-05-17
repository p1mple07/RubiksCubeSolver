#include <bits/stdc++.h>
using namespace std;

void cube::LeftRotate(){
    unsigned int temp = faces[2];
    faces[2] = faces[4];
    faces[4] = faces[3];
    faces[3] = faces[5];
    faces[5] = temp;

    temp = faces[1];
    faces[1] = faces[1]>>8;
    temp = temp<<24;
    faces[1] = temp|faces[1];// yellow center rotated

    temp = faces[0];
    faces[0] = faces[0]<<8;
    temp = temp>>24;
    faces[0] = temp|faces[0];// white center rotated
}

void cube::RightRotate(){
    unsigned int temp = faces[2];
    faces[2] = faces[5];
    faces[5] = faces[3];
    faces[3] = faces[4];
    faces[4] = temp;

    temp = faces[0];
    faces[0] = faces[0]>>8;
    temp = temp<<24;
    faces[0] = temp|faces[0];// white center rotated

    temp = faces[1];
    faces[1] = faces[1]<<8;
    temp = temp>>24;
    faces[1] = temp|faces[1];// yellow center rotated
}