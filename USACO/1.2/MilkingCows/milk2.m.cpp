/*
ID: louislu1
PROG: milk2 
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


#define TIMESIZE 1000001

class Times
{
public:
    void addMilkingTime(int startTime, int endTime)
    {
        for(int i = startTime; i <endTime; i++)
        {
            times[i] = true;
        }
        if(endTime > longestTime)
        {
            longestTime = endTime;
        } 

        if(startTime < beginingTime)
        {
            beginingTime = startTime;
        }
    }

    int printMilkeTime()
    {
        int start = beginingTime;
        bool preflag = times[beginingTime];
        int maxtime = 0;
        for(int i = beginingTime; i <= longestTime + 1; i++)
        {
            if(!preflag && times[i] && i != longestTime + 1)
            {
                start = i;
            }

            if(preflag && (!times[i] || i  == longestTime + 1))
            {
                if(i - 1 - start > maxtime)
                {
                    maxtime = i  - start;
                }
            }
            preflag = times[i];
        }
        return maxtime;
    }
    
    int printNonMilkeTime()
    {
        int start = beginingTime;
        bool preflag = times[beginingTime];
        int maxtime = 0;
        for(int i = beginingTime; i <= longestTime ; i++)
        {
            if(preflag && !times[i] && i != longestTime )
            {
                start = i;
            }

            if(!preflag && (times[i] || i == longestTime ))
            {
                if(i - start > maxtime)
                {
                    maxtime = i  - start;
                }
            }
            preflag = times[i];
        }
        return maxtime;
    }

    Times() :longestTime(0), beginingTime(TIMESIZE){
    }
private:
    bool times[TIMESIZE] ;
    int  longestTime ;
    int  beginingTime ;
};

int main() 
{
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    
    Times times;
    int number;
    fin>> number;
    int start,end;
    for(int i = 0; i < number; i++)
    {
        fin>>start>>end;
        times.addMilkingTime(start,end);
    }
    fout<<times.printMilkeTime()<< " " << times.printNonMilkeTime()<<endl;
    return 0;
}
