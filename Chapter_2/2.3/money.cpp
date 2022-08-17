/*
ID: ruizr271
TASK: money
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

ull dp[30][11000];
int main()
{
    ofstream fout ("money.out");
    ifstream fin ("money.in");
    int v,n;
    fin>>v>>n;
    vi A(v);
    FOR(i,v) fin>>A[i];
    FOR(i,v) dp[i][0] = 1;
    for(int j=1;j<=n;j++) if(j-A[0]>=0) dp[0][j]+=dp[0][j-A[0]];
    for(int i=1;i<v;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = dp[i-1][j];
            if(j-A[i]>=0) dp[i][j]+=dp[i][j-A[i]];
        }
    }
    fout<<dp[v-1][n]<<endl;


    return 0;
}
