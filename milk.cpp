/*
 ID: yongdue2
 PROG: milk
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


int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");

    int target, nfarmers;
    fin >> target >> nfarmers;
    
    vector<ii> farmers;
    for (int i=0; i<nfarmers; i++)
        {
        int price, amount;
        fin >> price >> amount;
        farmers.push_back(ii(price,amount));
        }
    std::sort (farmers.begin(), farmers.end());
    
    int cost=0;
    
    printf ("cost=%d target=%d\n", cost, target);
    
    for (int i=0; target > 0 && i<farmers.size(); i++)
        {
        printf ("$ unit price=%d, amount=%d\n", farmers[i].first, farmers[i].second);

        int am = farmers[i].second;
        if (am > target)
            am = target;
        
        target -= am, cost+= am*farmers[i].first;

        printf ("\tcost=%d target=%d\n", cost, target);
        
        }
    printf ("total cost = %d\n", cost);
    fout << cost << endl;
    return 0;
}

// EOF //