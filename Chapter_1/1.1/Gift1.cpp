/*
ID: ruizr271
TASK: gift1
LANG: C++                 
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    int n;
    fin>>n;
    map<string,int> account;
    vector<string> allNames;
    for(int i=0;i<n;i++){
        string name; 
        fin>>name;
        allNames.push_back(name);
        account[name] = 0;
    }
    string from;
    while(fin>>from){
        int money, p;
        fin>>money>>p;
        if(p==0) continue;
        int giving = (int)(money/p);
        int took = (giving*p);
        string to; 
        account[from] -= took;
        for(int i=0;i<p;i++){
            fin>>to;
            account[to]+=giving;
        }
    }
    for(string x: allNames){
        fout<<x<<" "<<account[x]<<endl;
    }
    return 0;
}