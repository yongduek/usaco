/*
 ID: yongdue2
 PROG: dualpal
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

int main() {
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    
    int N, S;
    fin >> N >> S;
    printf ("N, S = %d, %d\n", N, S);
    
    for (int i=S+1; N>0; i++) {
        int count=0;
        for (int b=2; b<=10; b++)
            {
            string s;
            if (palindrom (s=convert (i, b)))
                {
                ++count;
                cout << count << " : " << i << '=' << s << " based " << b << endl;
                if (count>=2) {
                    --N;
                    fout << i << endl;
                    break;
                }
                }
            }
    }
    return 0;
}


