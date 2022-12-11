#include<bits/stdc++.h>
using namespace std;

// Range of Numbers [1,1e6]
int N = 1000000;
bool sieve[1000001];
void createSieve() {
    for(int i=2;i<=N;i++){
        sieve[i] = 1;
    }

    for(int i=2;i*i<=N;i++){
        if(sieve[i]==1){
            for(int j = i*i; j<=N; j+=i){
                // sieve[j] = false;
                if(sieve[j]!=0){
                    sieve[j] = 0;
                    sieve[i]++;
                }
            }
        }
    }
}


int main() {
    createSieve(); // O(nloglogn)

    int q;
    cin >> q;

    while(q--){
        int n;
        cin >> n;
        cout << sieve[n] << endl; //O(1)
    }
}
