/*
 ID: yongdue2
 PROG: crypt1
 LANG: C++11
 */

//
//  crypt1.cpp
//  compro
//
//  Created by Yongduek Seo on 3/3/16.
//  Copyright © 2016 com.yndk. All rights reserved.
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

using namespace std;

typedef vector<vector<int> > vvi;
typedef std::pair<int,int> ii;

void print (vector<ii>& t) {
    for (int i=0; i<t.size(); i++)
        printf ("%d:  [%d  %d]\n", i, t[i].first, t[i].second);
    printf("---\n");
}


void print (const vvi& s) {
    int N = s.size();
    for (int i=0; i<N; i++)
        {
        for (int j=0; j<N; j++)
            {
            printf ("%c", s[i][j]);
            }
        printf ("\n");
        }
    printf("\n");
}


set<int> digits;
int scount = 0;

bool check (int x) {
    while (x>0)
        {
        if (digits.find(x%10) != digits.end())
            x /= 10;
        else
            return false;
        }
    return true;
}

void test(int a, int b)
{
//    printf("test> %d x %d = %d + %d = %d\n",
//           a, b, a*(b/10), a*(b%10), a*(b/10)+a*(b%10));

    int y = a * (b%10);
    if (y/100 > 9) return;
    if (!check (y)) return;
    
    int x = a * (b/10);
    if (x/100 > 9) return;
    if (!check (x)) return;

    x*=10;

    if (check (x+y))
        {
        scount++;
        printf("%d> %d x %d = %d(0) + %d = %d\n",
               scount,
               a, b, a*(b/10), a*(b%10), a*(b/10)*10+a*(b%10));
        }
}

void solve (int n, int a, int b)
{
    if (n==5) {
        test(a,b);
        return;
    }
    
    for (auto it = digits.begin(); it!=digits.end(); it++)
        {
        int aa=a, bb=b;
        if (n<3)
            aa = a*10 + *it;
        else
            bb = b*10 + *it;
        solve (n+1, aa, bb);
        }
}
int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");

    int N;
    fin >> N;
    while (N-->0)
        {
        int a;
        fin >> a;
        digits.insert(a);
        cout << a << ' ';
        }
    cout << endl;
    
    int first, second;
    solve (0, first=0, second=0);
    
    printf("num of solutions = %d\n", scount);
    fout << scount << endl;
    return 0;
}

// EOF //
