#include <bits/stdc++.h>
#include <fstream>
using namespace std;

ifstream fin;
ofstream fout;


void cube::read_input(char* argv){
    fin.open(argv);
    string arr[6];
    for (int i = 0; i < 6; i++)
    {
        fin>>arr[i];
    }
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<endl;
    }
    
    map<char,unsigned int>color;
    color['w'] = 0;
    color['y'] = 1;
    color['b'] = 2;
    color['g'] = 3;
    color['r'] = 4;
    color['o'] = 5;
    for (int i = 0; i < 6; i++)
    {
        faces[i] = 0;
        for (int j = 0; j < arr[i].size(); j++)
        {
            switch (j)
            {
            case 0:  
                faces[i]|=(color[arr[i][j]]<<28);
                break;
            case 1:  
                faces[i]|=(color[arr[i][j]]<<24);
                break;
            case 2:  
                faces[i]|=(color[arr[i][j]]<<20);
                break;
            case 3:  
                faces[i]|=(color[arr[i][j]]<<0);
                break;
            case 5:  
                faces[i]|=(color[arr[i][j]]<<16);
                break;
            case 6:  
                faces[i]|=(color[arr[i][j]]<<4);
                break;
            case 7:  
                faces[i]|=(color[arr[i][j]]<<8);
                break;
            case 8:  
                faces[i]|=(color[arr[i][j]]<<12);
                break;
            case 4:  
                continue;
                break;
            }
        }
    }    
}