/*
ID: ruizr271
TASK: skidesign 
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
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");
    int n;
    fin>>n;
    vi A(n);
    FOR(i,n) fin>>A[i];
    ll ans = INT_MAX;
    for(int i=0;i<=100;i++){
        for(int j=i;j<=i+17;j++){
            ll tot = 0;
            FOR(k,n){
               if(i<=A[k] && A[k]<=j) continue;
               else if(A[k]<i) tot+=(i-A[k])*(i-A[k]);
               else if(A[k]>j) tot+=(A[k]-j)*(A[k]-j);
            }
            cout<<tot<<" "<<i<<" "<<j<<endl;
            ans = min(ans,tot);
        }
    }
    fout<<ans<<endl;
    return 0;
}
