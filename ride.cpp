/*
ID: yongdue2
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getnum(string& a) {
    printf("[%s]\n", a.c_str());
    int sum = 1;
    for (int i=0; i<a.length(); i++)
	sum *= (a[i]-'A'+1);
    printf("-- sum= %d\n", sum%47);

    return sum%47;
}
int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a, b;
    fin >> a >> b;

    int numa = getnum (a);
    int numb = getnum (b);

    if (numa == numb) fout << "GO" << endl;
    else fout << "STAY" << endl;

    return 0;
}

