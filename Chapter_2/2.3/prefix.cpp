/*
ID: ruizr271
TASK: prefix
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

vector<string> pre;
string A;
bool dp[(int)2e5+1];
int main()
{
    ofstream fout ("prefix.out");
    ifstream fin ("prefix.in");
    while(true){
        string x;
        fin>>x;
        if(x==".") break;
        pre.pb(x);
    }
    string x;
    while(fin>>x){
        A+=x;
    }

    int n = A.size();
    int m = pre.size();
    int ans = 0;
    dp[0] = true;
    for(int i=1;i<=n;i++){
        FOR(j,m){
            int s = pre[j].size();
            if((i-s)<0) continue; 
            bool valid = true;
            for(int k = i-s+1;k<=i;k++){
                if(A[k-1]!=pre[j][k-(i-s+1)]) valid = false;
            }
            if(valid) dp[i] |= dp[i-s];
        }
        if(dp[i]) ans = i;
    }
    cout<<endl;

    cout<<ans<<endl;
    fout<<ans<<endl;
    

    return 0;
}
