/*
ID: louislu1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    int numOfPerson;
    int accounts[10] = {0};
    string names[10];
    map<string, int> name2index;
    fin>>numOfPerson;

    for(int i = 0; i < numOfPerson; i++)
    {
        string tempName;
        fin>>tempName;
        name2index[tempName] = i;
        names[i] = tempName;
    }

    //2 round
    for(int i = 0; i < numOfPerson; i++)
    {
        string name;
        int money;
        int numOfReceivers;
        fin >>name>> money >> numOfReceivers;
        int eachRecieverGot = money != 0 ? money / numOfReceivers : 0;
        int leftMoney = money != 0 ? money % numOfReceivers : 0;
        accounts[name2index[name]] += leftMoney - money;
        for(int r = 0; r < numOfReceivers; r++)
        {
            string tempName;
            fin>>tempName;
            accounts[name2index[tempName]] += eachRecieverGot;
        }
    }

    for(int i = 0; i < numOfPerson; i++)
    {
        fout<<names[i]<<" "<<accounts[i]<<std::endl;
    }

    return 0;
}
