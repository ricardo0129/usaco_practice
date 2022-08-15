/*
ID: ruizr271
TASK: preface
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

int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
string toRoman(int number){
    int i=12;    
    string ans = "";
    while(number>0)
    {
      int div = number/num[i];
      number = number%num[i];
      while(div--)
      {
        ans+=sym[i];
      }
      i--;
    }
    return ans;
}


int main()
{
    ofstream fout ("preface.out");
    ifstream fin ("preface.in");
    int n;
    fin>>n;
    map<string,int> mp;
    for(int i=1;i<=n;i++){
        string s = toRoman(i);
        for(char c: s){
            mp[string(1,c)]++;
        }
    }
    FOR(k,13){
        if(mp.count(sym[k])>0) fout<<sym[k]<<" "<<mp[sym[k]]<<endl;
    }
    

    return 0;
}
