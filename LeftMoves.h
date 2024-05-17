#include <bits/stdc++.h>
using namespace std;


void cube::L(){
    unsigned int leftMask = ((1<<8)-1 - (1<<28));
    unsigned int temp = faces[5];

    faces[5] = faces[5]>>8;
    temp = temp<<24;
    faces[5] = temp|faces[5];// orange center rotated

    unsigned int Lblue = faces[2]&leftMask;
    faces[2]&= (~leftMask);
    unsigned int Lyellow = faces[1]&leftMask;
    faces[2]|=Lyellow; // blue face done

    temp = 0|((bitSelect(faces[3],15,12))<<16);
    temp|= (bitSelect(faces[3],23,16)>>16);
    faces[1]&=(~leftMask);
    faces[1]|=temp;// yellow face done

    temp = 0|((bitSelect(faces[0],31,28))>>16);
    temp|= (bitSelect(faces[0],7,0)<<16);
    unsigned int greenmask = (1<<24) - (1<<12);
    faces[3]&=(~greenmask);
    faces[3]|=temp;// green face done

    faces[0]&=(~leftMask);
    faces[0]|=Lblue;// white face done
}

void cube::L_prime(){
    unsigned int leftMask = ((1<<8)-1 - (1<<28));
    unsigned int temp = faces[5];

    faces[5] = faces[5]<<8;
    temp = temp>>24;
    faces[5] = temp|faces[5];// orange center rotated

    unsigned int Lblue = faces[2]&leftMask;
    faces[2]&= (~leftMask);
    unsigned int Lwhite = faces[0]&leftMask;
    faces[2]|=Lwhite; // blue face done

    temp = 0|((bitSelect(faces[3],15,12))<<16);
    temp|= (bitSelect(faces[3],23,16)>>16);
    faces[0]&=(~leftMask);
    faces[0]|=temp;// white face done

    temp = 0|((bitSelect(faces[1],31,28))>>16);
    temp|= (bitSelect(faces[1],7,0)<<16);
    unsigned int greenmask = (1<<24) - (1<<12);
    faces[3]&=(~greenmask);
    faces[3]|=temp;// green face done

    faces[1]&=(~leftMask);
    faces[1]|=Lblue;// yellow face done
}

void cube::L2(){
    cube::L();
    cube::L();
}
