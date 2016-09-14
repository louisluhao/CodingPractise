/*
ID: louislu1
PROG: namenum 
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

char map[8][3] =
        {
            {'A','B','C'},
            {'D','E','F'},
            {'G','H','I'},
            {'J','K','L'},
            {'M','N','O'},
            {'P','R','S'},
            {'T','U','V'},
            {'W','X','Y'}
        };

void filterOutDict(list<string>& dict,int num, int spot)
{
    //number should start from 2 ~ 9
    if(num < 2 || num > 9)
    {
        dict.clear();
        return;
    }
    
    char * charArray = map[num - 2];


    list<string>::iterator iter;
    for(iter = dict.begin(); iter != dict.end();)
    {
        if((*iter).size() < spot)
        {
            iter++;
            continue;
        }
        char spotChar = (*iter)[spot];
        bool isValid = false;
        for(int i = 0; i < 3; i++)
        {
            if(spotChar == charArray[i])
                isValid = true;
        }
        if(!isValid)
        {
            iter = dict.erase(iter);
        }
        else
        {
            iter++;
        }
    }
}

int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream dictin("dict.txt");

    list<string> dict;
    while(dictin)
    {
        string s;
        dictin>>s;
        dict.push_back(s);
    }

//    list<string>::const_iterator iter;
//    for(iter = dict.begin(); iter != dict.end(); iter++)
//    {
//        cout<<*iter<<endl;
//    }

    string numString;
    fin >> numString;

    list<string>::iterator iter;
    for(iter = dict.begin(); iter != dict.end();)
    {
        if( (*iter).size() != numString.size())
        {
            iter = dict.erase(iter);
        }
        else
        {
            iter++;
        }
    }

    for(int i = 0; i < numString.size(); i++)
    {
        int num = numString[i] - '0';
        filterOutDict(dict,num, i);
    }


    for(iter = dict.begin(); iter != dict.end(); iter++)
    {
        fout<<*iter<<endl;
    }


    return 0;
}
