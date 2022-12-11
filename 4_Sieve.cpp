#include<bits/stdc++.h>
using namespace std;

// Time complexity of sieve is -> O(nlog(logn)) which is as good as O(n)
int N = 100000;
bool sieve[1000001];

void createSieve() {
    for(int i=2;i<=N;i++){
        sieve[i] = true;
    }

    for(int i=2;i*i<=N;i++){
        if(sieve[i]==true){
            for(int j = i*i; j<=N; j+=i){
                sieve[j] = false;
            }
        }
    }
}

int main(){
    createSieve();
    int t;
    cin >> t;

    while(t--){
        int n; cin >> n;
        if(sieve[n]==true){
            cout << "Yes, It is Prime";
        }
        else{
            cout << "It is not Prime";
        }
    }
    return 0;
}


// For array declared inside main
// maximum size of array other than boolean array -> 10^6
                            // for boolean array -> 10^7

// For array declared outside main
// maximum size of array other than boolean array -> 10^7
                            // for boolean array -> 10^8
