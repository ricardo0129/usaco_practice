/*
ID: ruizr271
TASK: barn1
LANG: C++                 
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long 
#define vi vector<int>


int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");

    int m,s,c;
    fin>>m>>s>>c;
    vector<int> stalls(c);
    for(int i=0;i<c;i++){
        fin>>stalls[i];
    }
    sort(stalls.begin(),stalls.end());
    vector<pii> boards = {{0,c-1}};
    int ans = stalls[c-1]-stalls[0]+1;
    for(int i=1;i<min(c,m);i++){
        int minimum = INT_MAX, pos = -1, d = -1;
        for(int j=0;j<boards.size();j++){
            int l = boards[j].first, r = boards[j].second;
            for(int k = l;k<r;k++){
                int dist = ans - (stalls[r]-stalls[l]+1) + stalls[r]-stalls[k+1]+1 + stalls[k]-stalls[l]+1;
                if(dist<minimum){
                    minimum = dist;
                    pos = j; 
                    d = k;
                }
            }
        }
        if(minimum<ans){
            ans = minimum;
            int l = boards[pos].first, r = boards[pos].second;
            boards.erase(boards.begin()+pos);
            boards.push_back({d+1,r});
            boards.push_back({l,d});
        }
        else break;
    }
    fout<<ans<<endl;

    return 0;
}