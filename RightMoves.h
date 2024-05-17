#include <bits/stdc++.h>
using namespace std;

void cube::R(){
    unsigned int temp = faces[4];
    unsigned int rightMask = ((1<<24) - (1<<12));
    faces[4] = faces[4]>>8;
    temp = temp<<24;
    faces[4] = temp|faces[4];// red center rotated

    unsigned int Rblue = faces[2]&rightMask;
    faces[2]&= (~rightMask);
    unsigned int Rwhite = faces[0]&rightMask;
    faces[2]|=Rwhite; // blue face done

    temp = 0|((bitSelect(faces[3],3,0))<<16);
    temp|= (bitSelect(faces[3],7,4)<<16);
    temp|= (bitSelect(faces[3],31,28)>>16);
    faces[0]&=(~rightMask);
    faces[0]|=temp;// white face done

    temp = 0|((bitSelect(faces[1],23,16))>>16);
    temp|= (bitSelect(faces[1],15,12)<<16);
    unsigned int greenmask = (1<<8)-1 - (1<<28);
    faces[3]&=(~greenmask);
    faces[3]|=temp;// green face done

    faces[1]&=(~rightMask);
    faces[1]|=Rblue;// yellow face done
}

void cube::R_prime(){
    unsigned int temp = faces[4];
    unsigned int rightMask = ((1<<24) - (1<<12));
    faces[4] = faces[4]<<8;
    temp = temp>>24;
    faces[4] = temp|faces[4];// red center rotated

    unsigned int Rblue = faces[2]&rightMask;
    faces[2]&= (~rightMask);
    unsigned int Ryellow = faces[1]&rightMask;
    faces[2]|=Ryellow; // blue face done

    temp = 0|((bitSelect(faces[3],3,0))<<16);
    temp|= (bitSelect(faces[3],7,4)<<16);
    temp|= (bitSelect(faces[3],31,28)>>16);
    faces[1]&=(~rightMask);
    faces[1]|=temp;// yellow face done

    temp = 0|((bitSelect(faces[0],23,16))>>16);
    temp|= (bitSelect(faces[0],15,12)<<16);
    unsigned int greenmask = (1<<8)-1 - (1<<28);
    faces[3]&=(~greenmask);
    faces[3]|=temp;// green face done

    faces[0]&=(~rightMask);
    faces[0]|=Rblue;// white face done
}

void cube::R2(){
    cube::R();
    cube::R();
}
