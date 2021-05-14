/*
ID: ruizr271
TASK: friday
LANG: C++                 
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");

    int N;
    fin>>N;
    vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};
    int count[7]; memset(count,0,sizeof count);
    int counter = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<days.size();j++){
            int d = days[j];
            if(j==1){
                int year = 1900+i;
                if( (year%100==0 && year%400==0) || (year%100!=0 && year%4==0) ){
                    d = 29;
                }
            }
            count[(counter+12)%7]++;
            counter+=d;
        }
    }
    for(int i=0;i<7;i++){
        fout<<count[(i+5)%7];
        if(i!=6) fout<<" ";
    }
    fout<<endl;
    return 0;
}