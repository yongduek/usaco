/*
 ID: yongdue2
 PROG: barn1
 LANG: C++11
 */

//
//  barn1.cpp
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

int stall[202];

int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");

    int nboard, nstalls, ns, num[202];
    fin >> nboard >> nstalls >> ns;
    for (int i=0; i<ns; i++)
        {
        fin >> num[i];
        }

    std::sort (num, num+ns);
    int ss, ee;
    ss = num[0];
    ee = num[ns-1];
    for (int i=ss; i<=ee; i++)
        stall[i] = 1; // all connected
    
    vector<ii> dist;
    for (int i=0; i<ns-1; i++)
        {
        int diff = num[i+1] - num[i];
        dist.push_back(ii(diff, num[i]));
        }
    
    std::sort (dist.begin(), dist.end());
    for (int i=dist.size()-1, nb=1; i>=0 && nb<nboard; i--, nb++)
        {
        // 한번 실행하면 두 개로 갈라짐.
        int s = dist[i].second;
        int e = dist[i].second + dist[i].first;
        printf ("%d: no-block: %d == %d\n", nb, s, e);
        for (int k=s+1; k<e; k++)
            {
            stall[k] = 0;
            }
        }
    
    int count=0;
    for (int i=ss; i<=ee; i++)
        {
        printf ("%d : %d\n", i, stall[i]);
        count += stall[i];
        }
    printf ("total blocked = %d\n", count);
    fout << count << endl;
    return 0;
}

// EOF //