/*
ID: ruizr271
TASK: frac1
LANG: C++                 
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define vll vector<ll>
#define vi vector<int>
#define pii pair<int,int>
#define FOR(i,n) for(int i=0;i<n;i++)
#define f first
#define s second
#define pb push_back

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main() {
    ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");

    set<pii> fracts;
    int n;
    fin>>n;
    fracts.insert({0,1});
    fracts.insert({1,1});
    for(int denum = 2;denum<=n;denum++){
        for(int numen = 1;numen<=denum;numen++){
            int k = gcd(denum,numen);
            fracts.insert({numen/k,denum/k});
        }
    }
    vector<pair<double,pii>> all;
    for(auto x: fracts){
        all.pb({x.f/(double)x.s,x});
    }
    sort(all.begin(),all.end());
    for(auto x: all) fout<<x.s.f<<"/"<<x.s.s<<endl;


    return 0;
}
