/*
ID: louislu1
PROG: dualpal
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
    return ' ';
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
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    int N, S;
    fin >> N >> S;
    int count = 0;
    int number = S + 1;
    while (count < N)
    {
        string result;
        int palCount = 0;
        for(int base = 2; base <=10; base++)
        {
           result = getNumInBase(number, base, true);
           if(result.size() > 0)
           {
               palCount++;
           }
           if(palCount >= 2)
           {
               break;
           }
        }
        if(palCount >= 2)
        {
            fout<<number<<endl;
            count++;
        }
        number++;
    }

    return 0;
}
