/*
ID: louislu1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getNumber(char c)
{
    return c - 'A' + 1;
}

int getFinalNumber(string s)
{
    int result = 1;
    for(int i = 0; i < s.size(); i++)
    {
        char c = s.at(i);
        result = result * getNumber(c);
    }
    return result % 47;
}

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a, b;
    fin>>a>>b;
    if(getFinalNumber(a) == getFinalNumber(b))
    {
        fout<<"GO"<<std::endl;;
    }else
    {
        fout<<"STAY"<<std::endl;
    }
    return 0;
}
