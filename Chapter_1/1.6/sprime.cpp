/*
ID: ruizr271
TASK: sprime
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
#define pb push_back
#define f first
#define s second

bool prime(int x){
    if(x==1) return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}
int n;
vi ans;
void solve(int i,int pp){
    if(!prime(i)) return;
    if(pp==n){
        ans.pb(i);
        return;
    }
    for(int j=1;j<=9;j++){
        solve(i*10+j,pp+1);
    }
}


int main() {
    ofstream fout ("sprime.out");
    ifstream fin ("sprime.in");
    fin>>n;
    for(int i=1;i<=9;i++){
        solve(i,1);
    }
    for(auto x: ans) fout<<x<<endl;




    return 0;
}
