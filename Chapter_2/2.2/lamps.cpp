/*
ID: ruizr271
TASK: lamps
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
vi on,off;
int n,c;
void apply(vi& a, int opp){
    int sn = a.size();
    if(opp==1)
        FOR(i,sn) a[i] = a[i]^1;
    else if(opp==2)
        for(int i=0;i<sn;i+=2) a[i] = a[i]^1;
    else if(opp==3)
        for(int i=1;i<sn;i+=2) a[i] = a[i]^1;
    else 
        for(int i=0;i<sn;i+=3) a[i] = a[i]^1;
}
bool check(vi a){
    for(auto x: on){
        if(!a[x-1]) return false;
    }
    for(auto x: off){
        if(a[x-1]) return false;
    }
    return true;
}

int main()
{
    ofstream fout ("lamps.out");
    ifstream fin ("lamps.in");
    fin>>n;
    fin>>c;
    int x;
    while(true){
        fin>>x;
        if(x==-1) break;
        on.pb(x);
    }
    while(true){
        fin>>x;
        if(x==-1) break;
        off.pb(x);
    }
    bool has = false;
    vector<vi> ans;
    FOR(i,1<<4){
        vi x(n,1);
        int vals = c;
        int done = 0;
        FOR(j,4)
            if(i&(1<<j)){
                apply(x,j+1);
                vals--;
                done++;
            }
        if(done<=c && vals%2==0 && check(x)){
            ans.pb(x);
            has = true;
        }
    }
    sort(ans.begin(),ans.end());
    for(auto x: ans){
        for(auto y: x) fout<<y;
        fout<<endl;
    }
    if(!has) fout<<"IMPOSSIBLE\n";


    return 0;
}
