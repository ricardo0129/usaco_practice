/*
ID: ruizr271
TASK: wormhole
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
int rr[12];
int nn[12];
int n;
vector<pll> points;
bool cycle(){
    for(int s = 0;s<n;s++){
        int p = s;
        for(int j=0;j<n;j++){
            p = rr[nn[p]];
            if(p==-1) break;
        }
        if(p!=-1) return true;
    }
    return false;
}

int solve(){  
    int i;
    int total = 0;
    for(i=0;i<n;i++){
        if(nn[i]==-1) break;
    }
    if(i==n){
        return cycle();
    }

    for(int j=i+1;j<n;j++){
        if(nn[j]==-1){
           nn[j] = i;
           nn[i] = j;
           total+=solve();
           nn[i] = nn[j] = -1;
        }
    }
    return total;
}

int main()
{
    ofstream fout ("wormhole.out");
    ifstream fin ("wormhole.in");

    fin>>n;
    FOR(i,n){
        ll x,y;
        fin>>x>>y;
        points.pb(make_pair(y,x));
    }
    sort(points.begin(),points.end());
    memset(rr,-1,sizeof rr);
    FOR(i,n-1){
        if(points[i].f==points[i+1].f) rr[i] = i+1;
    }
    memset(nn,-1,sizeof nn);
    fout<<solve()<<endl;
    
    


    return 0;
}
