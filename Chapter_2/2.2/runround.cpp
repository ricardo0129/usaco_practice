/*
ID: ruizr271
TASK: runround
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define FOR(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define f first
#define s second

const int MOD = (int)1e9+7;

unsigned long long int m;
bool vist[9];
int s[9];
bool round(ull x){
    int n = 0;
    while(x){
        s[n++] = x%10;
        x/=10;
    }
    FOR(k,n/2) swap(s[k],s[n-1-k]);
    memset(vist,false,sizeof vist);
    int u = 0;
    int got = 0;
    while(!vist[u]){
        u = (u+s[u])%n;
        vist[u] = true;
        got++;
    }
    return got==n;
}
int main()
{
    ofstream fout ("runround.out");
    ifstream fin ("runround.in");
    fin>>m;
    int dig = 0;
    ull y = m;
    while(y){
        dig++;
        y/=10;
    }
    ull  ans = 999999999; 
    int tot = 0;
    FOR(i,1<<9){
        vi numb;
        FOR(j,9){
            if(i&(1<<j)) numb.pb(j+1);
        }
        if(numb.size()==0 || numb.size()<dig) continue;
        do{
            ull x=0;
            FOR(j,numb.size()){
                x+=(ull)pow(10,j)*numb[j];
            }
            if(round(x) && x>m){
                ans = min(ans,x);
                tot++;
            }

        }while(next_permutation(numb.begin(),numb.end()));
    }
    cout<<tot<<endl;
    fout<<ans<<endl;
    return 0;
}


