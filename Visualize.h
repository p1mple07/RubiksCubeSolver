#include <bits/stdc++.h>
using namespace std;

static char col(int x){
    switch(x){
        case 0: return 'W';
        case 1: return 'Y';
        case 2: return 'B';
        case 3: return 'G';
        case 4: return 'R';
        case 5: return 'O';
    }
}

void cube::visualize(){
    unsigned int tl[6], tt[6], tr[6], rr[6], br[6], bb[6], bl[6], ll[6], cc[6]; 
    for(int i = 0; i<6; i++){
        unsigned int face = faces[i];
        tl[i] = bitSelect(face, 31, 28)>>28;
        tt[i] = bitSelect(face, 27, 24)>>24;
        tr[i] = bitSelect(face, 23, 20)>>20;
        rr[i] = bitSelect(face, 19, 16)>>16;
        br[i] = bitSelect(face, 15, 12)>>12;
        bb[i] = bitSelect(face, 11, 8)>>8;
        bl[i] = bitSelect(face, 7, 4)>>4;
        ll[i] = bitSelect(face, 3, 0);
        cc[i] = i;
    }
    cout<<"       "<<col(tl[1])<<" "<<col(tt[1])<<" "<<col(tr[1])<<endl;
    cout<<"       "<<col(ll[1])<<" "<<col(cc[1])<<" "<<col(rr[1])<<endl;
    cout<<"       "<<col(bl[1])<<" "<<col(bb[1])<<" "<<col(br[1])<<endl; // yellow done

    for(int i = 0; i<4; i++){
        int c;
        switch(i){
            case 0: c = 5; break;
            case 1: c = 2; break;
            case 2: c = 4; break;
            case 3: c = 3; break;
        }
        cout<<col(tl[c])<<" "<<col(tt[c])<<" "<<col(tr[c])<<"  ";
    } // top row done
    cout<<endl;

    for(int i = 0; i<4; i++){
        int c;
        switch(i){
            case 0: c = 5; break;
            case 1: c = 2; break;
            case 2: c = 4; break;
            case 3: c = 3; break;
        }
        cout<<col(ll[c])<<" "<<col(cc[c])<<" "<<col(rr[c])<<"  ";
    } // middle row done
    cout<<endl;

    for(int i = 0; i<4; i++){
        int c;
        switch(i){
            case 0: c = 5; break;
            case 1: c = 2; break;
            case 2: c = 4; break;
            case 3: c = 3; break;
        }
        cout<<col(bl[c])<<" "<<col(bb[c])<<" "<<col(br[c])<<"  ";
    } // bottom row done
    cout<<endl;

    cout<<"       "<<col(tl[0])<<" "<<col(tt[0])<<" "<<col(tr[0])<<endl;
    cout<<"       "<<col(ll[0])<<" "<<col(cc[0])<<" "<<col(rr[0])<<endl;
    cout<<"       "<<col(bl[0])<<" "<<col(bb[0])<<" "<<col(br[0])<<endl; // white done
    cout<<endl;

    
}