/*
ID: louislu1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int daysInMonth[12] = {31,//January
					   28,//February
					   31,//March
					   30,//April
					   31,//May
					   30,//June
					   31,//July
					   31,//August
					   30,//September
					   31,//October
					   30,//November
					   31 //December
					     };

int getDaysInMonth(int monthIndex, bool isLeapYear)
{
	if(monthIndex !=  1)//not February
	{
		return daysInMonth[monthIndex];
	}else
	{
		if(isLeapYear)
		{
			return 29;
		}else
		{
			return 28;
		}
	}
}

bool isLeapYear(int year)
{
	if(year % 100 == 0)
	{
		if(year % 400 == 0)
		{
			return true;
		}
		return false;
	}

	if(year % 4 == 0)
		return true;

	return false;
}

void appendDays(int year, int days[], int &startWeekIndex)
{
	for(int month = 0; month < 12; month++)
	{
		//13th count
		int dayIndexOfThirteen = (startWeekIndex + 12) % 7;
		days[dayIndexOfThirteen]++;
		startWeekIndex = (startWeekIndex + getDaysInMonth(month, isLeapYear(year)) ) % 7;
	}
}

void computeDays(int N, int days[])
{
	/*
	 * January 1, 1900 to December 31, 1900+N-1
	 * */
	int startWeekIndex = 0;// Monday = 0;
	for(int year = 1900; year < 1900 + N; year++)
	{
		appendDays(year, days, startWeekIndex);
	}
}

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int numOfYear;
    fin >> numOfYear;
    int days[7]= {0};
    computeDays(numOfYear, days);
    fout<<days[5]<<' '
        <<days[6]<<' '
		<<days[0]<<' '
		<<days[1]<<' '
		<<days[2]<<' '
		<<days[3]<<' '
		<<days[4]<<std::endl;
    return 0;
}
