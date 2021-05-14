/*
ID: ruizr271
TASK: palsquare
LANG: C++                 
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
vector<string> A = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F","G","H","I","J"};

string to_base(ll x, int b){
    if(x==0) return "0";
    bool placed = false;
    string ans = "";
    for(int i=16;i>=0;i--){
        for(int j=b-1;j>=0;j--){
            if(j==0){
                if(placed) ans+="0";
            }
            else if(x-pow(b,i)*j>=0){
                placed = true;
                ans+=A[j];
                x-=pow(b,i)*j;
                break;
            }
        }
    }
    return ans;
}

bool palindromic(string A){
    int n = A.size();
    for(int i=0;i<n/2;i++){
        if(A[i]!=A[n-1-i]) return false;
    }
    return true;
}

int main() {
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    
    int B;
    fin>>B;
    //cout<<to_base(127,3)<<endl;
    for(int i=1;i<=300;i++){
        ll x = i*i;
        string S = to_base(x,B);
        if(palindromic(S)){
            fout<<to_base(i,B)<<" "<<S<<endl;
        }
    }

    return 0;
}