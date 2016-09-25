/*
ID: louislu1
PROG: combo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

class Combination
{
    private:
        int combination[3];
    public:
        Combination(int a, int b, int c)
        {
            combination[0] = a;
            combination[1] = b;
            combination[2] = c;
        }

        ~Combination(){};

        int *getCombination(){return combination;}
        const int get(int index) const{return combination[index];}//this is evil
        
        int &operator[](int i)
        {
            return combination[i];
        }

        bool isContainZero()
        {
            for(int i = 0; i < 3; i++)
            {
                if(combination[i] == 0)
                {
                    return true;
                }
            }
            return false;
        }

        int getZeroIndex()
        {
            for(int i=0; i < 3; i++)
            {
                if(combination[i] == 0)
                    return i;
            }
            return -1;
        }
 
        bool operator< (const Combination& c) const
        {
            for(int i = 0; i < 3; i++)
            {
                if(combination[i] != c.get(i))
                {
                    return combination[i] < c.get(i); 
                }
            }
            return false;
        }

};

void getPossibleNumber(const int N, int number, int* array)
{
    for(int i = 0; i < 5; i++)
    {
        array[i] = number - 2 + i;
    }
    if(!(number + 2 <= N && number - 2 >= 1))
    {
        for(int i = 0; i < 5; i++)
        {
            if(array[i] <= 0)
                array[i] += N;
            else if(array[i] >N)
                array[i] -= N;
            if(array[i] <=0 || array[i] > N)
                array[i] = number;
        }
        
    }
}

void helper(const int N, const Combination c, set<Combination> &combos, Combination& newCombo)
{
    if(!newCombo.isContainZero())
    {
        combos.insert(newCombo);
        return;
    }
    int index = newCombo.getZeroIndex();
    int number = c.get(index);
    int array[5];
    getPossibleNumber(N, number, array);
    for(int i = 0; i < 5; i++)
    {
        newCombo[index] = array[i];
        helper(N, c, combos, newCombo);
        for(int j = index; j < 3; j++)
            newCombo[j] = 0;
    }
}

void generateCombos(const int N, const Combination c, set<Combination> &combos)
{
    Combination newCombo(0,0,0);
    helper(N, c, combos, newCombo);
}

int main() {
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");
    set<Combination> combos;
    int N;
    fin>>N;
    int a,b,c;
    fin>>a>>b>>c;
    Combination c1(a,b,c);
    fin>>a>>b>>c;
    Combination c2(a,b,c);
    generateCombos(N, c1, combos);
    generateCombos(N, c2, combos);
    fout<<combos.size()<<endl;
    return 0;
}
