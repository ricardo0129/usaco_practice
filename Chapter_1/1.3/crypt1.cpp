/*
ID: ruizr271
TASK: crypt1
LANG: C++                 
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long 
#define vi vector<int>

int n;
vi A;
set<int> all;
int used[5];
int ans;

bool checks(int x,int digits){
    string d = to_string(x);

    if(d.size()!=digits) return false;
    for(int i=0;i<d.size();i++){
        if(all.find((d[i]-'0'))==all.end()) return false;
    }
    return true;
}
int cc = 0;
void solve(int i){
    if(i==5){
        int p1 = (used[0]+used[1]*10+used[2]*100)*used[3];
        int p2 = (used[0]+used[1]*10+used[2]*100)*used[4];
        int sum = p2*10+p1;
        if(checks(p1,3) && checks(p2,3) && checks(sum,4)) ans++;
        return;
    }
    for(int j=0;j<n;j++){
        used[i] = A[j];
        solve(i+1);
    }
}
int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");

    fin>>n;
    A.resize(n);
    for(int i=0;i<n;i++){
        fin>>A[i];
        all.insert(A[i]);
    }
    ans = 0;
    solve(0);
    fout<<ans<<endl;

    return 0;
}