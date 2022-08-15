/*
ID: ruizr271
TASK: hamming
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

int n,b,d;
int ans[64];
int distance(int a, int b){
    int c = a^b;
    int cc = 0;
    while(c){
        if(c&1) cc++;
        c/=2;
    }
    return cc;
}
bool solved = false;
    ofstream fout ("hamming.out");
    ifstream fin ("hamming.in");
void print(){
    FOR(i,n){
        fout<<ans[i];
        if(i==n-1 || (i+1)%10==0) fout<<endl;
        else fout<<" ";
    }
}

void solve(int i,int last){
    if(solved) return;
    if(i==n){
        solved = true;
        print();
    }
    for(int j=last;j<(1<<b);j++){
        bool valid = true;
        FOR(k,i){
            if(distance(ans[k],j)<d) valid = false;
        }
        if(valid){
            ans[i] = j;
            solve(i+1,j+1);
        }
    }
}

int main() {
    fin>>n>>b>>d;
    solve(0,0);
    

    return 0;
}
