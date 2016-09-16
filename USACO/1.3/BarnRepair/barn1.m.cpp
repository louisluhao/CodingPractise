/*
ID: louislu1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool reverseSort (int i,int j) { return (i>j); }

int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    int maxOfBoard, totalStalls, numOfCows;
    fin >> maxOfBoard >> totalStalls >> numOfCows;
    vector<int> stallNumber;
    vector<int> spaces;
    for(int i = 0 ; i < numOfCows; i++)
    {
        int number;
        fin>>number;
        stallNumber.push_back(number);
    }
    sort(stallNumber.begin(),stallNumber.end());

    int preStall = stallNumber[0];
    for(int i = 1; i < numOfCows; i++)
    {
        int stall = stallNumber[i];
        if(preStall + 1 != stall)
        {
            spaces.push_back(stall - preStall - 1);
        }
        preStall = stall;
    }
    sort(spaces.begin(), spaces.end(), reverseSort);
    int countStall = numOfCows;
    while(spaces.size() > maxOfBoard -1)
    {
        countStall += spaces.back();
        spaces.pop_back();
    }
    fout<<countStall<<endl; 
    return 0;
}
