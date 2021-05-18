/*
ID: ruizr271
TASK: milk
LANG: C++                 
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long 
#define vi vector<int>


int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");

    int m, n;
    fin>>m>>n;
    vector<pii> farmers;
    int x,y;
    for(int i=0;i<n;i++){
        fin>>x>>y;
        farmers.push_back({x,y});
    }
    sort(farmers.begin(),farmers.end());
    int i=0;
    int cost = 0;
    while(m){
        int taking = min(m,farmers[i].second);
        cost+=taking*farmers[i].first;
        m-=taking;
        i++;
    }
    fout<<cost<<endl;
    return 0;
}