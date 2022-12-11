#include<bits/stdc++.h>
using namespace std;

// Time complexity -> O(N)
void checkPrimeM1(int n){
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(n%i==0) cnt++;
    }

    if(cnt==2) cout << "YES\n";
    else cout << "NO\n"; 
}


// Time complexity -> O(sqrt(N))

void checkPrimeM2(int n){
    int cnt = 0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cnt++;
            if(n/i!=i){
                cnt++;
            }
        }
    }
    if(cnt==2) cout << "Yes\n";
    else cout << "NO\n";
}

// NOTE -> All factors of a given number can be found in sqrt(n)

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        checkPrimeM1(n);
        checkPrimeM2(n);
    }
}