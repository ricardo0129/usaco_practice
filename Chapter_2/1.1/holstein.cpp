/*
ID: ruizr271
TASK: holstein 
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

int main() {
    ofstream fout ("holstein.out");
    ifstream fin ("holstein.in");
    int v;
    fin>>v;
    vi A(v);
    FOR(i,v) fin>>A[i];
    int g;
    fin>>g;
    vi ans(g+1);
    vector<vi> feeds(g,vi(v));
    FOR(i,g){
        FOR(j,v)
            fin>>feeds[i][j];
    }

    FOR(i,1<<g){
        vi vals(v);
        FOR(j,g){
            if(i&(1<<j)){
                FOR(k,v) vals[k]+=feeds[j][k];
            }
        }
        bool valid = true;
        FOR(k,v) if(vals[k]<A[k]) valid = false;
        if(valid){
            vi idx;
            FOR(j,g){
                if(i&(1<<j)){
                    idx.pb(j+1);
                }
            }
            if(idx.size()<ans.size()){
                ans = idx;
            }
            else if(idx.size()==ans.size()){
                ans = min(ans,idx);
            }

        }
    }
    fout<<ans.size();
    for(auto x: ans) fout<<" "<<x;
    fout<<endl;

    return 0;
}
