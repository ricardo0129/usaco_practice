/*
ID: ruizr271
TASK: ride 
LANG: C++                 
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a,b;
    fin >> a >> b;
    ll a_v = 1,b_v=1;
    for(int i=0;i<a.size();i++){
        a_v *= (a[i]-'A')+1;
    }
    for(int i=0;i<b.size();i++){
        b_v *= (b[i]-'A')+1;
    }
    a_v = a_v%47; b_v = b_v%47;
    if(a_v==b_v) fout<<"GO"<<endl;
    else fout<<"STAY"<<endl;
    return 0;
}