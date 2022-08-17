/*
ID: ruizr271
TASK: zerosum
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
char ans[30];
char opp[] = {'+','-',' '};
int n;
    ofstream fout ("zerosum.out");
    ifstream fin ("zerosum.in");
//1 3 5
void solve(int digit,int curr, int sign,int sum){
    if(digit==n+1){
        sum+=curr*sign;
        if(sum!=0) return;
        FOR(i,2*n-1)
            fout<<ans[i];
        fout<<endl;
        return;
    }
    int pos = (digit-1)*2-1;
    ans[pos+1] = digit+'0';
    ans[pos] = opp[2];
    solve(digit+1,curr*10+digit,sign,sum);
    ans[pos] = opp[0];
    solve(digit+1,digit,1,sum+sign*curr);
    ans[pos] = opp[1];
    solve(digit+1,digit,-1,sum+sign*curr);
}

int main()
{
    fin>>n;
    ans[0] = '1';
    solve(2,1,1,0);

    return 0;
}
