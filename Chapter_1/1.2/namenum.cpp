/*
ID: ruizr271
TASK: namenum
LANG: C++                 
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string cow;
vector<string> possible;
set<string> names;
char s[12];
vector<vector<char>> B = {{'A','B','C'},{'D','E','F'},{'G','H','I'},{'J','K','L'},{'M','N','O'},{'P','R','S'},{'T','U','V'},{'W','X','Y'}};
int n;
void solve(int i){
    if(i==n){
        string P;
        for(int j=0;j<n;j++){
            P+=s[j];
        }
        if(names.find(P)!=names.end())
            possible.push_back(P);
        return;
    }
    int k = cow[i]-'0';
    for(int j=0;j<3;j++){
        s[i] = B[k-2][j];
        solve(i+1);
    }
}

int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream dic("dict.txt");
    string x;
    while(dic>>x){
        names.insert(x);
    }


    fin>>cow;
    n = cow.size();
    solve(0);
    if(possible.size()==0){
        fout<<"NONE"<<endl;
    }
    else{
        sort(possible.begin(),possible.end());
        for(string y: possible){
            fout<<y<<endl;
        }
    }
    
    return 0;
}