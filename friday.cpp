/*
 ID: yongdue2
 PROG: friday
 LANG: C++11
 */

//
//  friday.cpp
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
//              0   1    2   3   4   5    6    7    8    9    10    11   12
int mdays[] = {0, 31, 28, 31, 30, 31, 30,  31,  31,  30, 31,  30,  31};
int friday13[7]; // 0: monday ... 6: sunday

bool leapYear (int y) {
    bool leap=true;
    if (y%4 == 0) leap=true; else leap=false;
    if (y%100==0) {
        leap = false;
        if (y%400==0) leap=true;
    }
    return leap;
}

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    
    int N;
    fin >> N;
    
    int days=0;
    for (int y=1900; y<1900+N; y++)
        {
        mdays[2] = leapYear(y)? 29: 28;
        int m;
        for (m=0; m<12; m++)
            {
            days += mdays[m];
            // compute day
            int d = (days+13)%7;
            friday13[d] ++;
            }
        days += mdays[m];
//        days %= 7;
        }
    printf("%d %d", friday13[6], friday13[0]);
    fout << friday13[6] << ' ' << friday13[0];
    for (int i=1; i<=5; i++)
        {
        printf(" %d", friday13[i]);
        fout << ' ' << friday13[i];
        }
    fout << endl;
    printf("\n");
    
    return 0;
}
