#include<bits/stdc++.h>
using namespace std;

void divisors(int n){
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cout << i << ' ';
            if(n/i!=i){
                cout <<  n/i << ' ';
            }
        }
    }
    cout << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        divisors(n);
    }
}