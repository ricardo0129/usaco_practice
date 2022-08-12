/*
ID: ruizr271
TASK: ariprog
LANG: C++                 
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long 
#define vi vector<int>
#define FOR(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define f first
#define s second

bool vist[20000];
int A[200000];
int pos[200000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");
    memset(A,0,sizeof A);
    int n,m;
    //length
    fin>>n;
    fin>>m;

    set<int> mp;
    FOR(i,m+1){
            FOR(j,m+1){
                    mp.insert(i*i+j*j);
            }
    }
    vi all;
    for(auto x: mp){
            pos[x] = all.size();
            all.pb(x);
            A[x]=1;
    }
    int largest = all.back();
    int l = all.size();
    vector<pii> ans;
    int curr,k,x;
    for(int diff=1;diff<=min(5000,largest);diff++){
            memset(vist,false,sizeof vist);
            for(int i=0;i<l;i++){
                    if(vist[i]) continue;
                    curr = all[i];
                    k = 0;
                    while(curr<=largest && A[curr]==1){
                            k++;
                            curr+=diff;
                    }
                    x = all[i];
                    while(k){
                        vist[pos[x]] = true;
                        if(k>=n){
                                ans.pb({x,diff});
                        }
                        k--;
                        x+=diff;
                    }
            }
    }
    sort(ans.begin(),ans.end(),[](pii a, pii b){
        if(a.s==b.s) return a.f<b.f;
        return a.s<b.s;
                    });
    if(ans.size()==0) fout<<"NONE\n";
    for(auto x: ans){
            fout<<x.f<<" "<<x.s<<endl;
    }




    return 0;
}
