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
        int size = this->d_size;
        Pattern after(size);
        int aj = size - 1;
        for(int si = 0; si < size; si++)
        {    
            for(int sj = 0; sj < size; sj++)
            {
                *after.charAt(sj, aj) = this->d_pattern[si][sj];
            } 
            aj--;
        }
        return after;
    }

    Pattern rotation180Degree()
    {
       return this->rotationNinetyDegree().rotationNinetyDegree();
    }

    Pattern rotation270Degree()
    {
       return this->rotation180Degree().rotationNinetyDegree();
    }

    Pattern reflection()
    {
        int size = this->d_size;
        Pattern after(size);
        int leftEnd, rightStart;
        int mid = size / 2;
        bool includeMid = (size % 2 == 0) ;

        if(includeMid) 
        {
            leftEnd = mid ;
            rightStart = mid + 1;
        } 
        else 
        {
            leftEnd = mid -1;
            rightStart = mid + 1;
        }

        for(int i = 0; i < size; i++)
        for(int j = 0; j <= leftEnd; j++)
        {
            *after.charAt(i,j) = this->d_pattern[i][j];
            *after.charAt(i, size - j - 1) = this->d_pattern[i][j];
        }

        if(!includeMid)
        {
            for(int i = 0; i < size; i++)
            {
                *after.charAt(i, mid) = this->d_pattern[i][mid];
            }
        
        }
        return after; 
    }

    char* charAt(int i, int j)
    {
        //should check i j
        return &d_pattern[i][j];
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
    cout<<start<<endl;
    cout<<endl;
    cout<<start.reflection()<<endl;
//    fin>>end;
//    cout<<start;
//    cout<<endl;
//    cout<<end;
//    cout<<*end.charAt(0,0);
//    cout<<(start == end)<<endl;


    return 0;
}
