#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> primefactor(n+1,0);
    for(int i=2;i<=n;i++){
        if(primefactor[i]==0){
            for(int j=i;j<=n;j+=i){
                primefactor[j]++;
            }
        }
    }
    int count=0;
    for(int i=2;i<=n;i++){
        if(primefactor[i]==2){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}