#include<bits/stdc++.h>
using namespace std;


// Time complexity -> O(N) if n is prime and less if it is not prime
void primeFactorsM1(int n){
    for(int i=2;i<=n;i++){
        while(n%i==0){
            cout << i << ' ';
            n/=i;
        }
    }
}


// Optimizing it
// For any numbers factors can be find in squareRoot n
// Now, if run loop from 2 to squareRoot n, we can find all primes except the number itself
// Time Complexity -> O(squareRoot(n))
// This is the best time complexity we can acheive for finding the prime factors of a single number
void primeFactorsM2(int n){
    for(int i=0;i*i<=n;i++){
        while(n%i==0){
            cout << i << ' ';
            n/=i;
        }
    }
    if(n>1) cout << n << ' ';
}


// Handling multiple queries
// Test cases -> T <= 1e6
// n<= 1e6
// If we use above approach, time complexity -> O(T*sqrt(n)) = 1e9
// We have to look for something else

// Concept -> No. of prime factors can atmax be logn with base 2.
// We will make the spf array i.e. smallest prime factor array using the same concept of seive
// For example -> we want to find the prime factors of 24
// spf array has smallest prime factor of 24 i.e. 2
// 24 -> 24/2 = 12
// 12's smallest prime factor -> 2
// 12 -> 12/2 = 6
// 6's smallest prime factor -> 2
// 6 -> 6/2 = 3
// 3's smallest prime factor -> 3
// 3 -> 3/3 = 1
// the moment we reach 1, we have all the prime factors of the given number
// Since, the maximum prime factors can only be logn, we have to divide only logn times in worst case
// Time complexity O(logn) per query

// Precomputation time -> O(nloglogn)
// for t queries -> O(t*logn)

int N = 1000000;
int sieve[1000001];

void createSeive() {
    for(int i=1;i<=N;i++){
        sieve[i] = i;
    }

    for(int i=2; i*i<=N;i++){
        if(sieve[i]==i){
            for(int j=i*i;j<=N;j+=i){
                if(sieve[j]==j){
                    sieve[j] = i;
                }
            }
        }
    }
}

int main() {

    createSeive();
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        while(n!=1){
            cout << sieve[n] << ' ';
            n = n/sieve[n];
        }
        cout << endl;
    }
}









