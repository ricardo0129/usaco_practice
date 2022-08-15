/*
ID: ruizr271
TASK: castle 
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

int parent[2500],size[2500];
int r,c;
int atob(int i, int j){
    return i*c+j;
}
pii btoa(int k){
    return {k/c,k%c};
}
void make_set(int u){
    parent[u] = u;
    size[u] = 1;
}
int find_set(int u){
    if(parent[u]==u) return u;
    return parent[u] = find_set(parent[u]);
}
void merge_set(int u, int v){
    u = find_set(u); v = find_set(v);
    if(u!=v){
        if(size[u]<size[v]) swap(u,v);
        parent[v] = u;
        size[u]+=size[v];
    }
}
int maze[50][50];
vector<pii> dirs = { {0,-1}, {-1,0} , {0,1}, {1,0} };
char dd[4] = {'W','N','E','S'};
bool valid(int i, int j){
    return i>=0 && i<r && j>=0 && j<c;
}


int main() {
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");
    fin>>c>>r;
    FOR(i,r) FOR(j,c) make_set(atob(i,j));
    FOR(i,r){
        FOR(j,c){
            fin>>maze[i][j];
            FOR(k,4){
                if(!(maze[i][j]&(1<<k))){
                    int i2 = i+dirs[k].f, j2 = j+dirs[k].s;
                    merge_set(atob(i,j),atob(i2,j2));
                }
            }
        }
    }
    set<int> mp;
    int ans = 0;
    FOR(i,r){
        FOR(j,c){
            int u = find_set(atob(i,j));
            mp.insert(u);
            ans = max(ans,size[u]);
        }
    }
    fout<<mp.size()<<endl;
    fout<<ans<<endl;

    int ans2 = 0;
    vi last = {0,0};
    char di = 'A';
    //most west (smallest col) -> most south (largest row) -> N before E -> 

    for(int j = c-1;j>=0;j--){
        for(int i=0;i<r;i++){
            for(int k=2;k>=1;k--){
                if((maze[i][j]&(1<<k))){
                    int i2 = i+dirs[k].f, j2 = j+dirs[k].s;
                    if(valid(i2,j2)){
                        int u = find_set(atob(i,j));
                        int v = find_set(atob(i2,j2));
                        if(u!=v){
                            if(size[u]+size[v]>=ans2){
                                ans2 = size[u]+size[v];
                                last[0] = i+1;
                                last[1] = j+1;
                                di = dd[k];
                            }

                        }
                    }

                }
            }

        }
    }
    fout<<ans2<<endl;
    fout<<last[0]<<" "<<last[1]<<" "<<di<<endl;


    return 0;
}
