/*
 ID: yongdue2
 PROG: beads
 LANG: C++11
 */

//
//  beads.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 3. 1..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;


int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    
    string s;
    int N;
    getline (fin, s);
    N = std::stoi(s);
    getline (fin, s); // beads
//    for (int i=0; i<N; i++) {
//        printf ("%d: [%c]\n", i, s[i]);
//    }
    vector<int> counts;
    int maxcnt = 0;
    
    for (int i=0; i<N; i++) // i is the breaking point {... s[i-1]}, {s[i], s[i+1] ...}
        {
        if (i==1) {
            int a=0;
        }
        int rsum = 1;
        char ch = s[i];
        int j=(i+1)%N;
        int jend;
        for (; j!=i; j = (j+1)%N)
            {
            if (s[j]=='w' || ch == s[j])
                rsum ++;
            else if (ch!=s[j] && ch=='w')
                {
                ch = s[j];
                rsum++;
                }
            else
                {
                jend = --j;
                break;
                }
            }
        
        int lsum = 0;
        if (j!=i)
            {
            int j=(i-1+N)%N;
            ch = s[j];
            lsum ++;
            for (j=(j-1+N)%N;  j!=i && j!=jend; j = (j-1+N)%N)
                {
                if (s[j]=='w' || ch == s[j])
                    lsum ++;
                else if (ch!=s[j] && ch=='w')
                    {
                    ch = s[j];
                    lsum++;
                    }
                else
                    break;
                }
            }
        int cnt = rsum + lsum;
        counts.push_back(cnt);
        maxcnt = std::max (maxcnt, cnt);
        }
    for (auto it = counts.begin(); it!=counts.end(); ++it)
        {
        printf ("%d ", *it);
        }
    printf("\n");
    printf("max = %d\n", maxcnt);
    fout << maxcnt << endl;
    /****
    vector<pair<char,int> > count, mc;
    
    // initial skip
    int i=1;
    while (s[i-1] == s[i])
        {
        i = (i+1)%N;
        if (i==1) break;
        }
    
    if (i==1) // all the beads are of the same color
        {
        fout << s.length() << endl;
        return 0;
        }
    
    int start = i;

    printf("starting from %d\n", start);
    
    while (1)
        {
        char ch = s[i];
        int c=0;
        while (s[i] == ch)
            {
            c++, i=(i+1)%N;
            if (i==start) break;
            }
        count.push_back(pair<char,int>(ch,c));
        if (i==start) break;
        }
    
    for (int i=0; i<count.size(); i++)
        printf ("(%c, %d)", count[i].first, count[i].second);
    printf("\n");
    
    
    for (int i=0; i<count.size(); i++) // white beads are merged to the next beads
        {
        if (count[i].first=='w')
            continue;
        
        if (count[(i-1)%N].first=='w')
            {
            count[i].second += count[(i-1)%N].second;
//            count[(i-1)%N].second = 0;
            }
        mc.push_back(count[i]);
        }

    for (int i=0; i<mc.size(); i++)
        printf ("(%c, %d)", mc[i].first, mc[i].second);
    printf("\n");
    
    count = mc;
    mc.clear();
    { // merge same colors
        // find start
        i=0;
        while (count[(i-1)%N].first==count[i].first)
            i++;
        int end = i;
        
        do
            {
            pair<char,int> nb = count[i];
            ++i;
            while (nb.first==count[i].first && i!=end)
                {
                nb.second += count[i].second;
                i = (i+1)%N;
                }
            mc.push_back(nb);
            }
        while (i!=end);
        
        for (int i=0; i<mc.size(); i++)
            printf ("(%c, %d)", mc[i].first, mc[i].second);
        printf("\n");
        
    }
    ****/
    
    return 0;
}

