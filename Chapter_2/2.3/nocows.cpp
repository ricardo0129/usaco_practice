/*
ID: ruizr271
TASK: nocows
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

const int MOD = 9901;
int n,k;
int dp2[300][300];

int nchosek(int n, int k){
    if(k>n) return 0;
    if(k==0 || n==k) return 1;
    if(dp2[n][k]!=-1) return dp2[n][k]%MOD;
    return dp2[n][k] = (nchosek(n-1,k)%MOD+nchosek(n-1,k-1)%MOD)%MOD;
}
int dp[101][101][201];

int solve(int level, int previous, int r){
    if(level==k){
        if(r<=0 || r%2!=0) return 0;
        if(r>previous*2) return 0;
        return nchosek(previous,r/2)%MOD;
    }
    if(dp[level][previous][r]!=-1) return dp[level][previous][r]%MOD;
    int ans = 0;
    for(int i=2;i<=min(previous*2,r);i+=2){
        int x = (nchosek(previous,i/2)%MOD*solve(level+1,i,r-i)%MOD)%MOD;
        ans = (ans+x)%MOD;
    }
    return dp[level][previous][r] = ans%MOD;
}
int main()
{
    ofstream fout ("nocows.out");
    ifstream fin ("nocows.in");
    fin>>n>>k;
    memset(dp,-1,sizeof dp);
    memset(dp2,-1,sizeof dp2);
    int x = solve(2,1,n-1);
    cout<<x<<endl;
    fout<<x<<endl;

    return 0;
}
