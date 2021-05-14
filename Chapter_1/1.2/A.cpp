#include <bits/stdc++.h>
using namespace std;


int main()
{
    int count = 0;
    for(int i=2;i<=10;i++){
        int x = round(log(1<<30)/log(i));
        count+=pow(i+1,x/2);
    }
    cout<<count<<endl;
    return 0;
}