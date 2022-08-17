/*
ID: ruizr271
TASK: concom
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define FOR(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define f first
#define s second

const int MOD = (int)1e9+7;
const int N = 101;
vector<pii>  G[100];

int main()
{
    ofstream fout ("concom.out");
    ifstream fin ("concom.in");
    int n;
    fin>>n;
    set<int> comp;
    FOR(i,n){
        int u,v,p;
        fin>>u>>v>>p;
        comp.insert(u);
        G[u].pb({v,p});
    }
    vector<pii> ans;
    for(auto c: comp){
        queue<int> q;
        vi p(101,0);
        vector<bool> vist(101,false);
        q.push(c);
        vist[c] = true;
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u!=c) ans.pb({c,u});
            for(pii v:G[u]){
                p[v.f]+=v.s;
                if(p[v.f]>50 && !vist[v.f]){
                    q.push(v.f);
                    vist[v.f] = true;
                }
            }
        }
    }
    sort(ans.begin(),ans.end());
    for(auto x: ans) fout<<x.f<<" "<<x.s<<endl;


    return 0;
}
