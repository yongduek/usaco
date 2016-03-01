/*
 ID: yongdue2
 PROG: namenum
 LANG: C++11
 */

//
//  namenum.cpp
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

using namespace std;

typedef std::pair<int,int> ii;

void print (vector<ii>& t) {
    for (int i=0; i<t.size(); i++)
        printf ("%d:  [%d  %d]\n", i, t[i].first, t[i].second);
    printf("---\n");
}


set<string> dict;
const char *keypad[10] = { "", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY" };

vector<string> founds;
string name;

void f (string s, int n)
{
    char ch=s[n];
    if (s.length()==n) // end of the string, name is completed.
        {
        //        cout << name << endl;
        if (dict.find(string(name)) != dict.end())
            founds.push_back(name),
            cout << "  found: " << name << endl;
        //        else
        //            cout << "  not found." << endl;
        return;
        }
    
    int num = ch - '0';
    const char *keys = keypad[num];
    for (int i=0; i<3; i++)
        {
        name.push_back(keys[i]);
        f (s, n+1);
        name.pop_back();
        }
}

int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream fdict ("dict.txt");
    
    string str;
    while (!fdict.eof())
        {
        fdict >> str;
        if (fdict.eof()) break;
        dict.insert(str);
        }
    
    fin >> str;
    
    f (str, 0);
    
    if (founds.size())
        for (int i=0; i<founds.size(); i++)
            fout << founds[i] << endl;
    else
        fout << "NONE" << endl;
    
    return 0;
}

