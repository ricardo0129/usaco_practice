/*
ID: ruizr271
TASK: milk2
LANG: C++                 
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");

    int n;
    fin>>n;
    vector<pii> A;
    int x,y;
    for(int i=0;i<n;i++){
        fin>>x>>y;
        A.push_back({x,y});
    }
    sort(A.begin(),A.end());
    int ans = 0;
    int ans2 = 0;
    int l = 0, r = 0;
    l = A[0].first; r = A[0].second;
    ans = r-l;
    for(int i=1;i<n;i++){
        if(A[i].first<=r){
            r = max(r,A[i].second);
        }
        else{
            ans2 = max(ans2,A[i].first-r);
            l = A[i].first; r = A[i].second;
        }
        ans = max(ans,r-l);
    }
    fout<<ans<<" "<<ans2<<endl;
    return 0;
}