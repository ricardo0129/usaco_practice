/*
ID: ruizr271
TASK: transform
LANG: C++                 
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;

bool check(vector<string> A, vector<string> B){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(A[i][j]!=B[i][j]) return false;
    return true;
}

vector<string> rotate(vector<string> A){
    vector<string> B(n,string(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            B[i][j] = A[n-1-j][i];
        }
    }
    return B;
}
vector<string> flip(vector<string> A){
    vector<string> B = A;
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            swap(B[i][j],B[i][n-1-j]);
        }
    }
    return B;
}

int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");

    fin>>n;
    vector<string> A(n), B(n);
    for(int i=0;i<n;i++)
        fin>>A[i];
    for(int i=0;i<n;i++)
        fin>>B[i];

    int ans = 7;

    vector<string> C = rotate(A);

    if(check(C,B)){
        fout<<1<<endl;
        return 0;
    }
    C = rotate(C);
    if(check(C,B)){
        fout<<2<<endl;
        return 0;
    }
    C = rotate(C);
    if(check(C,B)){
        fout<<3<<endl;
        return 0;
    }
    C = flip(A);
    if(check(C,B)){
        fout<<4<<endl;
        return 0;
    }
    for(int i=0;i<3;i++){
        C = rotate(C);
        if(check(C,B)){
            fout<<5<<endl;
            return 0;
        }
    }
    if(check(A,B)){
        fout<<6<<endl;
        return 0;
    }
    fout<<7<<endl;



    return 0;
}