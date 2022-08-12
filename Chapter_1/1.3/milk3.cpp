/*
ID: ruizr271
TASK: milk3 
LANG: C++                 
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long 
#define vi vector<int>
#define FOR(i,n) for(int i=0;i<n;i++)
#define f first
#define s second
#define pb push_back

vi G[800];
bool vist[800];
int cap[3];
vector<vi> all;
set<int> ans;

void dfs(int u){
        vist[u] = true;
        if(all[u][0]==0)
        ans.insert(all[u][2]);
        for(int v:G[u]){
                if(!vist[v]) dfs(v);
        }
}
bool equal(vi a, vi b){
        FOR(i,3) if(a[i]!=b[i]) return false;
        return true;
}
bool can(vi a, vi b){
        //can you go from state a to state b
        FOR(i,3){
                FOR(j,3){
                        if(i==j) continue;
                        vi c = a; 
                        int to = cap[j]-a[j];
                        int from  = a[i];
                        int x = min(to,from);
                        c[i]-=x;
                        c[j]+=x;
                        if(equal(c,b)) return true;
                }

        } 
        return false;
}
int main() {
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");
    FOR(i,3) fin>>cap[i];
    int a = cap[0];
    int b = cap[1];
    int c = cap[2];
    FOR(i,c+1){
            FOR(j,c+1){
                    FOR(k,c+1){
                            if(i+j+k==c && i<=a && j<=b && k<=c){
                                    all.pb({i,j,k});
                            }
                    }
            }
    }
    FOR(i,all.size()){
            FOR(j,all.size()){
                    if(i==j) continue;
                    //can you go from i->j
                    if(can(all[i],all[j])){
                            G[i].pb(j);
                    }
                    
            }
    }
    vi nit = {0,0,cap[2]};
    int start = 0;
    FOR(i,all.size()){
            if(equal(nit,all[i])) start = i;
    }
    dfs(start);
    int i = 0;
    for(int x: ans){
            if(i!=0) fout<<" ";
            fout<<x;
            i++;
    }
    fout<<endl;
        



    return 0;
}
