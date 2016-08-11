#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    int m;
    cin >> n >> m;
    
    if(n > m)
    {
        cout<<n - m<<endl;
    }
    else
    {
        if(m % n == 0)
            cout<< 0 <<endl;
        else
            cout<<n - m % n<<endl;
    }

    return 0;
}
