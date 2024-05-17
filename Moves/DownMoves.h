#include <bits/stdc++.h>
using namespace std;

// 0 white
// 1 yellow
// 2 blue
// 3 green 
// 4 red
// 5 orange

void cube::D(){

    unsigned int temp = faces[0];
    faces[0] = faces[0]>>8;
    temp = temp<<24;
    faces[0] = temp|faces[0];// yellow center rotated

    unsigned int downMask = ((1<<16)- (1<<4));
    unsigned int Dblue = faces[2]&downMask;
    faces[2] &= (~downMask);
    unsigned int Dorange = faces[5]&downMask;
    faces[2] |= Dorange; // blue face done

    faces[5] &= (~downMask);
    unsigned int Dgreen = faces[3]&downMask;
    faces[5] |= Dgreen; // red face done

    faces[3] &= (~downMask);
    unsigned int Dred = faces[4]&downMask;
    faces[3] |= Dred;

    faces[4] &= (~downMask);
    faces[4] |= Dblue;
}

void cube::D_prime(){

    unsigned int temp = faces[0];
    faces[0] = faces[0]<<8;
    temp = temp>>24;
    faces[0] = temp|faces[0];// white center rotated

    unsigned int downMask = ((1<<16)- (1<<4));
    unsigned int Dblue = faces[2]&downMask;
    faces[2] &= (~downMask);
    unsigned int Dred = faces[4]&downMask;
    faces[2] |= Dred; // blue face done

    faces[4] &= (~downMask);
    unsigned int Dgreen = faces[3]&downMask;
    faces[4] |= Dgreen; // red face done

    faces[3] &= (~downMask);
    unsigned int Dorange = faces[5]&downMask;
    faces[3] |= Dorange;

    faces[5] &= (~downMask);
    faces[5] |= Dblue;
}

void cube::D2(){
    cube::D();
    cube::D();
}
