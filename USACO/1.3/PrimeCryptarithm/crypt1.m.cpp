/*
ID: louislu1
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <cmath>

using namespace std;
ofstream fout ("crypt1.out");
bool getNextNumber(int &nextNumber, const int number, set<int> &potentialNumbers);

bool validateNumbers(set<int> &potentialNumbers, int number, int size)
{
    int length;
    if((number / pow(10,size)) >= 1) return false;
    while(number > 0)
    {
        int num = number % 10;
        number = number / 10;
        set<int>::iterator iter = potentialNumbers.find(num);
        if(iter == potentialNumbers.end())
        {
            return false;
        }
    }
    return true;
}

bool validateNumbers(set<int> &potentialNumbers, int *numbers)
{
    int number1 = numbers[0]*100 + numbers[1]*10 + numbers[2];
    
    int line1 = number1 * numbers[4];
    int line2 = number1 * numbers[3];
    int finalNumber = line1 + line2 * 10;
    return validateNumbers(potentialNumbers, line1, 3) &&
           validateNumbers(potentialNumbers, line2, 3) &&
           validateNumbers(potentialNumbers, finalNumber, 4);
}

void DFSNumbersAndVarified(set<int> &potentialNumbers,int &count, int *numbers, int position)
{
    if(position >= 5)
    {
        if(validateNumbers(potentialNumbers, numbers))
        {
            for(int i = 0; i < 5; i++)
                cout<<numbers[i];
            cout<<endl;
            count++;
        }
        return;
    }
    set<int>::iterator iter;
    for(iter = potentialNumbers.begin(); iter != potentialNumbers.end(); iter++)
    {
        numbers[position] = *iter;
        DFSNumbersAndVarified(potentialNumbers,count, numbers, position + 1);
    }
}

void DFSNumbersAndVarified(set<int> &potentialNumbers)
{
    int count = 0;
    int numbers[5];
    DFSNumbersAndVarified(potentialNumbers,count, numbers, 0);
    fout<<count<<endl;
}

int main() {
    ifstream fin ("crypt1.in");
    int N;
    fin >> N;
    set<int> potentialNumbers;
    for(int i = 0; i < N; i++)
    {
        int number;
        fin >> number;
        potentialNumbers.insert(number);
    }
    DFSNumbersAndVarified(potentialNumbers);
    return 0;
}


bool getNextNumber(int &nextNumber, const int number, set<int> &potentialNumbers)
{
    set<int>::iterator iter = potentialNumbers.find(number);
    iter++;
    if(iter != potentialNumbers.end())
    {
        nextNumber = *iter;
        return true;
    }
    else
        return false;
}
