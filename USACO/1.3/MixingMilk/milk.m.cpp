/*
ID: louislu1
PROG: milk 
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    int totalMilk;
    map<int,int> farms;
    fin >> totalMilk;
    int n;
    fin >> n;
    for(int i = 0; i < n; i++)
    {
        int price, amount;
        fin>>price>>amount;
        if(farms.find(price) == farms.end())
        {
            farms.insert(pair<int, int>(price, amount));
        }
        else
        {
            farms[price] += amount;
        }
    }

    long totalCost = 0;
    //run greedy
    map<int,int>::iterator iter = farms.begin();
    //never check end cause The total milk produced per day by 
    //the farmers will always be sufficient to meet the demands 
    //of the Merry Milk Makers even if the prices are high.
    while(totalMilk > 0)
    {
        int price, amount;
        price = iter->first;
        amount = iter->second;

        if(amount >= totalMilk)
        {
            totalCost += price * totalMilk;
            totalMilk = 0;
            break;
        }

        totalCost += price * amount;
        totalMilk -= amount;
        iter++;
    } 

    fout<<totalCost<<endl;

    return 0;
}
