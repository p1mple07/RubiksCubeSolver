#include <bits/stdc++.h>
using namespace std;

void cube::scramble(){
    srand (time (0));  // to generate different random numbers at each execution step
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i = 0; i<100; i++){
        int x = rand()%12;
        switch(x){
            case 0: R(); break;
            case 1: R_prime(); break;
            case 2: L(); break;
            case 3: L_prime(); break;
            case 4: U(); break;
            case 5: U_prime(); break;
            case 6: D(); break;
            case 7: D_prime(); break;
            case 8: F(); break;
            case 9: F_prime(); break;
            case 10: B(); break;
            case 11: B_prime(); break;
            
        }
    }
}