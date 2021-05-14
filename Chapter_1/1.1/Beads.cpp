/*
ID: ruizr271
TASK: beads
LANG: C++                 
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int n;
    fin>>n;
    string necklace;
    fin>>necklace;
    int ans = 0 ;
    for(int s=0;s<n;s++){
        int r1 = (((s-1)%n)+n)%n;
        char s1 = necklace[r1];
        int r2 = (s)%n;
        char s2 = necklace[r2];
        int count = 2;
        while(count<n){
            int x = (((r1-1)%n)+n)%n;
            if(necklace[x]==s1 || necklace[x]=='w' || s1=='w'){
                if(s1=='w') s1 = necklace[x];
                r1 = x;
                count++;
            }
            else break;
        }
        while(count<n){
            int x = (r2+1)%n;
            if(necklace[x]==s2 || necklace[x]=='w' || s2=='w'){
                if(s2=='w') s2 = necklace[x];
                r2 = x;
                count++;
            }
            else break;
        }
        ans = max(ans,count);
    }
    fout<<ans<<endl;
    return 0;
}