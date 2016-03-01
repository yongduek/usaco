/*
 ID: yongdue2
 PROG: gift1
 LANG: C++11
 */

//
//  greedygiftgivers.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 3. 1..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    
    string s;
    int np;
    getline(fin, s);
    np = std::stoi (s);
    
    vector<string> gnames;
    map<string,int> givers;
    for (int i=0; i<np; i++) {
        getline(fin, s);
        givers[s] = 0;
        gnames.push_back(s);
    }

    for (int nf=0; nf<np; nf++)
        {
        string name;
        int money, num;
        getline(fin, name); // name
        getline(fin, s);
        std::istringstream sstrm (s);
        sstrm >> money >> num;

        if (num == 0) continue;
        
        int gift = money / num;
        
        cout << "$ [" << name << "] has money = " << money << ' ' << num << "  dist= " << gift << endl;

        givers[name] += ( - gift*num);
        for (int i=0; i<num; i++)
            {
            string fname;
            getline (fin, fname);
            givers[fname] += gift;
            }
        for (int i=0; i<np; i++)
            cout << gnames[i] << ' ' << givers[gnames[i]] << endl;
        cout << "----" << endl;
        }
    for (int i=0; i<np; i++)
        fout << gnames[i] << ' ' << givers[gnames[i]] << endl;
    
    return 0;
}
