/*
 ID: yongdue2
 PROG: milk2
 LANG: C++11
 */

//
//  milk2.cpp
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

typedef std::pair<int,int> ii;

void print (vector<ii>& t) {
    for (int i=0; i<t.size(); i++)
        printf ("%d:  [%d  %d]\n", i, t[i].first, t[i].second);
    printf("---\n");
}

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    
    vector<ii> t; // time intervals
    int N;
    fin >> N;
    while (N-->0)
        {
        int a, b;
        fin >> a >> b;
        t.push_back(ii(a,b));
        }
    
    print (t);
    sort (t.begin(), t.end());
    print (t);

    vector<ii> r;
    int i;
    
    i=0;
    do
        {
        ii s=t[i];
        for (i++; i<t.size(); i++)
            {
            if (s.second < t[i].first)
                break;
            else
                {
                s.second = std::max (s.second, t[i].second);
                }
            }
        r.push_back(s);
        }
    while (i<t.size());
    print (r);
    
    t = r;
    int maxj=0;
    for (int j=0; j<t.size(); j++)
        maxj = std::max (maxj, t[j].second-t[j].first);
    
    int maxi=0;
    for (int i=1; i<t.size(); i++)
        maxi = std::max (maxi, t[i].first - t[i-1].second);
    printf("maxj= %d  maxi= %d\n", maxj, maxi);
    
    fout << maxj << ' ' << maxi << endl;
    return 0;
}

