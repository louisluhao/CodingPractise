/*
ID: louislu1
PROG: wormhole
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Wormhole
{
private:
    int x;
    int y;
public:
    Wormhole(int x, int y):x(x),y(y){}
    Wormhole():x(-1),y(-1){}
    ~Wormhole(){}

    int getX(){return x;}
    int getY(){return y;}

    

};

int main() {
    ofstream fout ("wormhole.out");
    ifstream fin ("wormhole.in");

    return 0;
}
