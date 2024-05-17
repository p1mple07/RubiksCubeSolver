#include <bits/stdc++.h>
using namespace std;

void cube::U(){

    unsigned int temp = faces[1];
    faces[1] = faces[1]>>8;
    temp = temp<<24;
    faces[1] = temp|faces[1];// yellow center rotated

    unsigned int upMask = (0- (1<<20));
    unsigned int Ublue = faces[2]&upMask;
    faces[2] &= (~upMask);
    unsigned int Ured = faces[4]&upMask;
    faces[2] |=Ured; // blue face done

    faces[4] &= (~upMask);
    unsigned int Ugreen = faces[3]&upMask;
    faces[4] |= Ugreen; // red face done

    faces[3] &= (~upMask);
    unsigned int Uporange = faces[5]&upMask;
    faces[3] |= Uporange;

    faces[5] &= (~upMask);
    faces[5] |= Ublue;
}

void cube::U_prime(){

    unsigned int temp = faces[1];
    faces[1] = faces[1]<<8;
    temp = temp>>24;
    faces[1] = temp|faces[1];// yellow center rotated

    unsigned int upMask = (0 - (1<<20));
    unsigned int Ublue = faces[2]&upMask;
    faces[2] &= (~upMask);
    unsigned int Uorange = faces[5]&upMask;
    faces[2] |=Uorange; // blue face done

    faces[5] &= (~upMask);
    unsigned int Ugreen = faces[3]&upMask;
    faces[5] |= Ugreen; // red face done

    faces[3] &= (~upMask);
    unsigned int Ured = faces[4]&upMask;
    faces[3] |= Ured;

    faces[4] &= (~upMask);
    faces[4] |= Ublue;
}

void cube::U2(){
    cube::U();
    cube::U();
}
