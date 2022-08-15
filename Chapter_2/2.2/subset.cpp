/*
ID: ruizr271
TASK: subset
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

ll dp[40][800];
int main()
{
    ofstream fout ("subset.out");
    ifstream fin ("subset.in");
    int n;
    fin>>n;
    int sum = (n)*(n+1)/2; 
    memset(dp,0,sizeof dp);
    dp[1][1] = 1;
    for(int i=2;i<=n;i++){
        FOR(j,sum+1) dp[i][j] = dp[i-1][j];
        FOR(j,sum+1){
            if(j-i>=0) dp[i][j]+=dp[i-1][j-i];
        }
    }
    if(sum%2==1) fout<<0<<endl;
    else fout<<dp[n][sum/2]<<endl;

    return 0;
}
