#include<bits/stdc++.h>
using namespace std;

int N = 86028121;
int Sieve[86028122];
vector<int> ds;
void createSieve(){
    for(int i=2;i<=N;i++){
        Sieve[i] = true;
    }

    for(int i=2;i*i<=N;i++){
        if(Sieve[i] == true){
            for(int j=i*i;j<=N;j+=i){
                if(Sieve[j]== true){
                    Sieve[j] = false;
                }
            }
        }
    }

    int size = 0;
    int cnt = 0;
    int limit = 5000000;
    for(int i=2;;i++){
        if(Sieve[i]==true){
            cnt++;
        }

        if(cnt==limit){
            size = i;
            break;
        }
    }

    for(int i=2;i<=N;i++){
        if(Sieve[i]==true){
            ds.push_back(i);
        }
    }
}


int main(){
    createSieve();

    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        cout << ds[k-1] << endl;
    }
}