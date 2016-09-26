/*
ID: louislu1
PROG: wormhole
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

class Wormhole
{
private:
    int x;
    int y;
    Wormhole& d_pair;

public:
    Wormhole(int x, int y):x(x),y(y){}
    Wormhole():x(-1),y(-1){}
    ~Wormhole(){}

    int getX(){return x;}
    int getY(){return y;}
    Wormhole& pair(){return d_pair;}

    
    bool operator< (const Wormhole& w) const
    {
        if(y < w.y) return true;
        if(x < w.x) return true;
        return false;
    }
};

int main() {
    ofstream fout ("wormhole.out");
    ifstream fin ("wormhole.in");
    list<Wormhole> wormholes;
    int N;
    fin>>N;
    for(int i = 0; i < N; i++)
    {
        int x,y;
        fin>>x>>y;
        Wormhole wormhole(x,y);
        wormholes.push_back(wormhole);
    }
    

    return 0;
}
