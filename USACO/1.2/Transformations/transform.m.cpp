/*
ID: louislu1
PROG: transform 
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bsl::string startPattern[100];
bsl::string endPattern[100];




int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int a, b;
    fin >> a >> b;
    fout << a+b << endl;
    return 0;
}
