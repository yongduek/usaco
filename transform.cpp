/*
 ID: yongdue2
 PROG: transform
 LANG: C++11
 */

//
//  transform.cpp
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

vvi t90 (const vvi& s)
{
    vvi d = s;
    int N = s.size();
    for (int i=0; i<N; i++)
        {
        for (int j=0; j<N; j++)
            {
            int ii = j;
            int jj = N - 1 - i;
            d[ii][jj] = s[i][j];
            }
        }
    return d;
}

vvi th (const vvi& s)
{
    vvi d=s;
    int N=s.size();
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            {
            int jj = N-1-j;
            d[i][jj] = s[i][j];
            }
    return d;
}

void read (ifstream& fin, vvi& s)
{
    int N = s.size();

    for (int i=0; i<N; i++)
        {
        string str;
        getline (fin, str);
        s[i] = vector<int>(N);
        for (int j=0; j<N; j++)
            {
            s[i][j] = str[j];
            }
        }
}

bool compare (const vvi& a, const vvi& b)
{
    size_t N = a.size();
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            if (a[i][j] != b[i][j]) return false;
    return true;
}

int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");

    int N;
    string str;
    getline (fin, str);
    N = std::stoi (str);
    vvi s(N), d(N);
    read (fin, s);
    read (fin, d);
    
    vvi ss[10], s90, s180, s270, s4, s4_90, s4_180, s4_270;
    ss[9] = s;
    ss[1] = s90 = t90(s);
    ss[2] = s180 = t90 (s90);
    ss[3] = s270 = t90 (s180);
    ss[4] = s4 = th (s);
    ss[5] = s4_90 = t90 (s4);
    ss[6] = s4_180 = t90 (s4_90);
    ss[7] = s4_270 = t90 (s4_180);
    
    int n;
    for (n = 1; n<=9; n++)
        if (compare (ss[n], d))
            break;
    
    if (n==0) n = 9;
    
    switch (n)
    {
        case 9:
        fout << 6 << endl;
        cout << '6' << endl; break;
        case 1:
        case 2:
        case 3:
        case 4:
        fout << n << endl;
        cout << n << endl; break;
        case 5:
        case 6:
        case 7:
        fout << 5 << endl;
        cout << '5' << endl; break;
        case 8:
        fout << 7 << endl;
        cout << '7' << endl; break;
    }
    return 0;
}

// EOF //