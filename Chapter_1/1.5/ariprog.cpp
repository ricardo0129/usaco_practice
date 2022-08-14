/*
ID: ruizr271
TASK: ariprog
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
int main()
{
    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");

    int n,m;
    //3 2
    fin>>n>>m;
    vector<pii> ans;
    set<int> x;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=m;j++){
            x.insert(i*i+j*j);
        }
    }
    vi v;
    for(auto y: x) v.pb(y);
    int n1 = v.size();
    set<int> used;
    for(int i=0;i<n1;i++) cout<<v[i]<<endl;
    for(int j=0;j<n1;j++){
        int start = v[j];
        queue<int> q;
        while(x.find(start)!=x.end()){
            q.push(start);
            used.insert(start);
            start = start+1;
        }
        while(!q.empty() && q.size()>=n){
            for(int i=1;i<20000;i++){
                if(q.size()>=i*(n-1)) ans.pb(make_pair(i,q.front()));
                else break;
            }
            q.pop();
        }
    }


    if(ans.size()==0) fout<<"NONE\n";
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++) fout<<ans[i].s<<" "<<ans[i].f<<endl;


    return 0;
}
