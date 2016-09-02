/*
ID: louislu1
PROG: transform 
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Pattern
{
public:
    //should check size < 10 in init
    Pattern(int size, char **startPattern):d_size(size)
    {
        for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
        {
            d_pattern[i][j] = startPattern[i][j];
        }
    }

    Pattern(int size):d_size(size){};

    friend ostream& operator<<(ostream& os, const Pattern &p)
    {
        int size = p.d_size;
        for(int i = 0; i < size; i++)
        {
                for(int j = 0; j < size; j++)
                {
                    os << p.d_pattern[i][j];
                }
                os<<'\n';
            }
            return os;
    }

    friend istream& operator>>(istream& is, Pattern &p)
    {
        int size = p.d_size;
        for(int i = 0; i < size; i++)
        {
            string line;
            is >> line;
            for(int j = 0; j < size; j++)
            {
                p.d_pattern[i][j] = line[j];
            }
        }
        return is;
    }

    bool operator==(const Pattern &p2) const
    {
        const Pattern &p1 = *this;
        if(p1.d_size != p2.d_size) return false;
        int size = p1.d_size;
        for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
        {
            if(p1.d_pattern[i][j] != p2.d_pattern[i][j])
            {
                return false;
            }
        }
        return true;
    }

    Pattern rotationNinetyDegree()
    {
        Pattern after(this->d_size);

    
    }

    chat * charAt(int i, int j)
    {
        //should check i j
        return d_pattern[i][j];
    }



private:
    char d_pattern[10][10];
    int  d_size;

};

int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int n;
    fin>>n;
    Pattern start(n), end(n);
    fin>>start;
    fin>>end;
    cout<<start;
    cout<<endl;
    cout<<end;
    cout<<(start == end)<<endl;


    return 0;
}
