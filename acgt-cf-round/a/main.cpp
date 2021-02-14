//#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector") 
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
 
#include <bits/stdc++.h>                                                               
//#include <ext/pb_ds/assoc_container.hpp> // Общий файл. 
//#include <ext/pb_ds/tree_policy.hpp> // Содержит класс tree_order_statistics_node_updat 
//#include <ext/pb_ds/detail/standard_policies.hpp>
#define int long long
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define repb(i, r, l) for (int i = r; i >= l; i--)
#define sz(a) (int)a.size()
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pb push_back  
#define mp(a, b) make_pair(a, b)
#define ret(a) {cout << a; exit(0);}
 
using namespace std;

mt19937 mrand(random_device{}()); 
const int mod = 998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;if(a==1)return 1; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
typedef pair < int , int > pii ;                                            
typedef pair < long long  , long long > pll ;
const int N = 2e6 + 123, shift = 1e5;                               
using namespace std;
int f[N];
int p[N];
int n, m, k;
int ar, ay, br , by;
main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);                
  

  cin >> n >> m >> k;
  cin>>ay>>ar>>by>>br;
  while(k--){
    int s;
    cin >> s;
    rep(x1, 0, min(ay,s)){
      int y1 = s-x1;
      int nby = by + x1, nbr = br + y1;
      rep(x2, 0, min(nby, s)){
        int y2 = s - x2;
        int nay = ay-x1+x2;
        int nar = ar-y1+y2;
        cout << abs(nay - (nbr - y2)) << " ";
      }
      cout << "\n";
    }
  }
  cout << abs(ay - br);
  
}
