#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mod 1000000007
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vli vector<long long int>
#define vpi vector<pair<int,int>>
#define vpl vector<pair<long long, long long>
#define vpil vector<pair<int,long long>>
#define vpli vector<pair<long long,int>>
#define vs vector<string>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define mi map<int,int>
#define ml map<long long ,long long>
#define mci map<char,int>
#define msi map<string,int>
#define mic map<int,char>
#define mis map<int,string
#define PI 3.141592653589793238462
#define all(x) (x).begin(), (x).end()
#define take(x) for(auto &y:x) cin >> y;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define max3(a,b,c) max(max((a),(b)),(c))
#define max4(a,b,c,d) max(max((a),(b)),max((c),(d)))
#define min3(a,b,c) min(min((a),(b)),(c))
#define min4(a,b,c,d) min(min((a),(b)),min((c),(d)))
#define fio(a,b) for(int i=a;i<b;i++)
// debugging Starts
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// debugging Ends


int main(){
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif

    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        bool flag = false;
        int a,b,c;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                int val = n/i;
                for(int j=i+1;j*j<=val;j++){
                    if(val%j==0 && val/j > j){
                        cout << "YES" << endl;
                        cout << i << ' ' << j << ' ' << val/j << endl;
                        flag = true;
                        break;
                    }
                }
            }
            if(flag) break;
        }

        if(!flag) cout << "NO" << endl;
    }
    return 0;
}