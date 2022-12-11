#include<bits/stdc++.h>
using namespace std;

// Segmented Sieve

// Given -> Test cases T <= 10 i.e. some small number
// A range [L,R], Queries will be given in this range
// 1 <= (L,R) <= 1e12
// R-L <= 1e6

// Now, eg -> 10,20 valid test case
//            1e6,1e6+6 valid
//            1e11,1e11+5 valid
// But if we use normal sieve, we can not build this much size array

// That is why, we need segmented sieve
// For any number we require, primes less than or equal to root n, because primes that come after root n are responsible for marking numbers greater than n

// Steps -> Generate Primes till root r. This will be done by using sieve
// Create a dummy array of size R-L+1 and marks them with 1
// The 0th index will represent L
// The last index will represent R
// Since we have all the primes that may be responsible for marking the numbers in this range
// Marks all multiples of primes in (L-R) in dummy arrray

int N = 1000000;
bool sieve[1000001];

void createSieve() {
    for(int i=2;i<=N;i++){
        sieve[i] = true;
    }

    for(int i=2;i*i<=N;i++){
        if(sieve[i] == true){
            for(int j= i*i; j<=N; j+=i){
                sieve[j] = false;
            }
        }
    }
}

vector<int> generatePrimes(int N){
    vector<int> ds;
    for(int i=2;i<=N;i++){
        if(sieve[i] == true){
            ds.push_back(i);
        }
    }
    return ds;
}

int main(){
    createSieve();

    int t;
    cin >> t;
    while(t--){
        int l,r; 
        cin >> l >> r;
        // step 1: generate all primes till sqrt(r)
        vector<int> primes = generatePrimes(sqrt(r));

        // step 2: 
        // create a dummy array of size r-l+1 and make everyone as 1
        int dummy[r-l+1];
        for(int i=0;i<r-l+1;i++){
            dummy[i] = 1;
        }


        // step3, for all prime number
        // mark its multiples as false
        for(auto pr:primes){
            int firstMultiple = (l/pr)*pr;
            if(firstMultiple < l) firstMultiple += pr;
            for(int j = max(firstMultiple,pr*pr); j<=r; j+=pr){
                dummy[j-l] = 0;
            }

        }

        // step4: get all the primes
        for(int i=l;i<=r;i++){
            if(dummy[i-l] == 1){
                cout << i << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}


// Time complexity -> O(1e6) + O(T * (1e6 + 1e6 + 1e4*some value)) <= 1e7