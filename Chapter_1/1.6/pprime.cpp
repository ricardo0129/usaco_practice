/*
ID: ruizr271
TASK: pprime 
LANG: C++                 
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
#define ll long long 
#define vi vector<int>
#define vll vector<ll>
#define pb push_back

vector<ll> all;
vector<string> curr;

void generate(string k){
       if(k[0]!=0 && k.size()<=9) curr.pb(k);
       if(k.size()>=9) return; 
       FOR(i,10){
               string new_val = to_string(i)+k+to_string(i);
               //if(i!=0) curr.pb(new_val); 
               generate(new_val);
       }
}

bool is_prime(ll x){
        for(int i=2;i*i<=x;i++){
                if(x%i==0) return false;        
        }
        return true;
}



int main() {
    ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");
    ll a,b;
    fin>>a>>b;
    generate("");
    FOR(i,10){
            generate(to_string(i));
    }
    vll primes;
    FOR(i,curr.size()){
            ll x = stoll(curr[i]);
            if(x>=a && x<=b && is_prime(x)) primes.pb(x);
    }
    vll ans;
    FOR(i,primes.size()){
            if(primes[i]>=a && primes[i]<=b) ans.pb(primes[i]);
    }
    sort(ans.begin(),ans.end());
    for(auto x: ans) fout<<x<<endl;
    return 0;
}
