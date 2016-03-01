

/*
 ID: yongdue2
 PROG: palsquare
 LANG: C++11
 */

//
//  palsquare.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 3. 1..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <stack>

using namespace std;

typedef std::pair<int,int> ii;

void print (vector<ii>& t) {
    for (int i=0; i<t.size(); i++)
        printf ("%d:  [%d  %d]\n", i, t[i].first, t[i].second);
    printf("---\n");
}

char nch[] = "0123456789ABCDEFGHIJKLMNOPQ";

string convert (int n, int b) {
    if (n==0) return "";
    int r = n % b;
    n /= b;
    string a = convert (n, b);
    string s = a + nch[r];
    return s;
}

bool palindrom (const string& s) {
    for (int i=0; i<s.length()/2; i++)
        if (s[i]!=s[s.length()-1-i])
            return false;
    return true;
}

int b = 10;
int main() {
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    
    fin >> b;
    printf ("Base = %d\n", b);
    
    for (int i=1; i<= 300; i++) {
        int i2 = i*i;
        string s = convert (i2, b);
//        printf ("%d: %d - %s\n", i, i2, s.c_str());
        if (palindrom (s))
            {
            cout << convert (i, b) << ' ' << s << endl;
            fout << convert (i, b) << ' ' << s << endl;
            }
    }
    return 0;
}


