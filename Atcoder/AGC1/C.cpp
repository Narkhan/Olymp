#include <bits/stdc++.h>
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll long long
#define forn(i, a, b) for(int i = (a); i <= (b); ++i)
#define forev(i, b, a) for(int i = (b); i >= (a); --i)
#define VAR(v, i) __typeof( i) v=(i)
#define forit(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
 
using namespace std;
 
const int maxn = (int)1e5 + 100;
const int mod = (int)1e9 + 7;
const int P = (int) 1e6 + 7; 
const double pi = acos(-1.0);
 
#define inf mod
 
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;   
typedef vector<ll> Vll;               
typedef vector<pair<int, int> > vpii;
typedef vector<pair<ll, ll> > vpll;                        


int n, dp[maxn], a[maxn];
void solve(){
	scanf("%d", &n);
	forn(i, 1, n) scanf("%d", &a[i]);
	forn(i, 1, n){
		forn(j, i, n){
			if(a[j] > a[i]) dp[j] = max(dp[j], dp[i] + 1);
			j += i - 1;
		}
	}
	printf("%d\n", *max_element(dp + 1, dp + n + 1));
}
int main () {
	int t = 1;
	scanf("%d", &t);
	while(t--)
		solve(); 
}
