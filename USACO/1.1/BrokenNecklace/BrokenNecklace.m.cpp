/*
ID: louislu1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isMatchColor(char &color1, char color2)
{
    if(color2 == 'w')
        return true;
    if(color1 == color2)
        return true;
    if(color1 == 'w')
    {
        color1 = color2;
        return true;
    }
    return false;
}

int countSameBeadsNumber(string necklace, int start, int step)
{
    char color = necklace[start];
    int nextIndex = start + step;
    int count = 1;
    while(true)
    {
        if(nextIndex < 0)
            nextIndex = necklace.size() - 1;
        if(nextIndex >= necklace.size())
            nextIndex = 0;
        if(nextIndex == start)
            return count;
        if(isMatchColor(color, necklace[nextIndex]))
        {
            count++;
            nextIndex = nextIndex + step;
        }
        else
        {
            return count;
        }
    }
}

int countBeads(string necklace)
{
    int maxCount = 0;
    for(int i = 0; i < necklace.size(); i++)
    {
        int backStart = i - 1;
        if(i == 0)
            backStart = necklace.size() -1;
        int frontCount = countSameBeadsNumber(necklace, i, 1);
        int backCount = countSameBeadsNumber(necklace, backStart, -1);
        int count = frontCount + backCount;
 
        if(count > maxCount)
        {
            if(count <= necklace.size())
            {
                maxCount = count;
            }
            else
            {
                if(frontCount > backCount)
                {
                    maxCount = frontCount;
                }else
                {
                    maxCount = backCount;
                }
            }
        }
    }
    return maxCount;
}

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int n;
    string necklace;
    fin >> n >> necklace;
    fout << countBeads(necklace)<<endl; 
    return 0;
}
