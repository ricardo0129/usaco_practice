/*
ID: ruizr271
TASK: numtri
LANG: C++                 
*/
#include <iostream>
#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

int dp[1000][1000];
int vals[1000][1000];
int rows;
int main()
{
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
    fin>>rows;
    FOR(i,rows){
            FOR(j,i+1){
                    fin>>vals[i][j];
            }
    }

    dp[0][0] = vals[0][0];
    int ans = 0;
    for(int i=1;i<rows;i++){
            FOR(j,i+1){
                dp[i][j] = dp[i-1][j]+vals[i][j]; 
                if(j!=0) dp[i][j] = max(dp[i][j],dp[i-1][j-1]+vals[i][j]);
            }
    }
    FOR(i,rows){
        ans = max(ans,dp[rows-1][i]);
    }
    fout<<ans<<endl;



    return 0;
}
