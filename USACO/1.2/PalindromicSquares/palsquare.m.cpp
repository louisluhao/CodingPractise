/*
ID: louislu1
PROG: palsquare 
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;


char getChar(int num)
{
    if(num < 10) 
        return num + '0';
    if(num >= 10)
        return num - 10 + 'A';
}

//conver a 10 base number to base X
string getNumInBase(int number, int base, bool checkpal)
{
    string result = "";
    string origin = "";
    while(number > 0)
    {
        int remainder = number % base;
        result += getChar(remainder);
        number /=  base;
    }
    origin = result;
    reverse(result.begin(), result.end());
    if(checkpal && origin != result)
    {result = "";}
    return result;
}

int main() {
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    int base;
    fin >> base;
    for(int n = 1; n <= 300; n++)
    {
        string result = getNumInBase(n*n, base, true);
        if(result.size() != 0)
        {
            fout<<getNumInBase(n, base, false)<<" "<<result<<endl;
        }
    }
    return 0;
}
