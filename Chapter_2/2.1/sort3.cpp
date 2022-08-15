/*
ID: ruizr271
TASK: sort3 
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

int occ[3];
int main() {
    ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");
    int n;
    fin>>n;
    vi A(n);

    FOR(i,n){
        fin>>A[i];
        A[i]--;
        occ[A[i]]++;
    }
    queue<int> q;
    FOR(i,n){
        if(A[i]==0 && i>=occ[0]){
            q.push(i);
        }
    }
    int ans = 0;
    //replace fix ones 
    for(int r=1;r<=2;r++){
        FOR(i,occ[0]){
            if(A[i]==r){
                swap(A[i],A[q.front()]);
                q.pop();
                ans++;
            }
        }
    }
    FOR(i,n){
        if(A[i]==1 && i>=occ[0]+occ[1]){
            ans++;
        }
    }
    fout<<ans<<endl;
    return 0;
}
