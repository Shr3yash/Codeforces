#include <bits/stdc++.h>
using namespace std;

// Typedefs for convenience
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

// Constants
const int MOD = 1e9 + 7;       // Modulo for modular arithmetic
const ll INF = 1e18;           // Large value for infinity
const int INF_INT = 1e9;       // Large value for integer infinity
const double EPS = 1e-9;       // Precision for floating point comparisons
const double PI = acos(-1);    // Value of π

// Macros for looping
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)    // Loop from a to b-1
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)   // Loop from a to b in reverse
#define REP(i, n) FOR(i, 0, n)                         // Loop from 0 to n-1
#define ALL(v) (v).begin(), (v).end()                  // Shortcut for whole container
#define RALL(v) (v).rbegin(), (v).rend()               // Reverse container
#define SZ(v) ((int)(v).size())                        // Get size of container

// Input and output shortcuts
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

// Debugging tools
#define DEBUG(x) cerr << #x << " = " << x << endl;

// Bit manipulation
#define SETBIT(x, pos) (x |= (1LL << pos))             // Set bit at position pos
#define CLEARBIT(x, pos) (x &= ~(1LL << pos))          // Clear bit at position pos
#define TOGGLEBIT(x, pos) (x ^= (1LL << pos))          // Toggle bit at position pos
#define CHECKBIT(x, pos) ((x >> pos) & 1LL)            // Check bit at position pos

// Utility functions
template<typename T>
T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); } // GCD
template<typename T>
T lcm(T a, T b) { return (a / gcd(a, b)) * b; }        // LCM
template<typename T>
T mod_exp(T base, T exp, T mod) {                      // Modular exponentiation
    T res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}
template<typename T>
bool is_prime(T n) {                                   // Primality test
    if (n < 2) return false;
    for (T i = 2; i * i <= n; ++i) if (n % i == 0) return false;
    return true;
}

// Comparators
bool cmp_desc(int a, int b) { return a > b; }          // Descending order
bool cmp_pair_first_desc(pii a, pii b) { return a.first > b.first; } // Pair comparator

// Useful functions
ll mod_add(ll a, ll b, ll m = MOD) { return (a + b) % m; }
ll mod_sub(ll a, ll b, ll m = MOD) { return (a - b + m) % m; }
ll mod_mul(ll a, ll b, ll m = MOD) { return (a * b) % m; }

// BFS and DFS templates
void bfs(int start, vector<vi>& adj, vi& dist) {
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
}

void dfs(int node, vector<vi>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

// Lower and Upper bounds (binary search helpers)
int lower_bound_idx(vi& v, int x) {
    return lower_bound(ALL(v), x) - v.begin();
}
int upper_bound_idx(vi& v, int x) {
    return upper_bound(ALL(v), x) - v.begin();
}

void solve(){
    int n;
cin>>n;
string s;
cin>>s;
int empt = 0;
bool f = true;

for(int i=0; i<n; i++){
    if(s[i] == '.')empt++;
    if(i > 0 && i<n-1)
        if(s[i-1] == '.' && s[i] == '.' && s[i+1] == '.') {
        cout<<2<<'\n';
        f = false;
    }
}
if(f)
    cout<<empt<<'\n';
}

void solve1() {
    //unlimited water if you have 3 consecutive dots, very funny
    //cases- 3 consec dots, 2 consec dots at max, 1 max
    int n, maxConsecutiveDots=0, totalDots=0;
    cin>>n;
    int soln=-10;
    char input;
    REP(i, n){
        cin>>input;
        if(input='.'){
            maxConsecutiveDots++;
            soln =  max(maxConsecutiveDots, soln);
            totalDots++;
        }else if(input='#'){
            maxConsecutiveDots=0;
        }
    }
    if(soln>=3)
        cout<<2<<'\n';
    else if(soln<=2)
        cout<<totalDots<<'\n';
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int t;
    cin >> t; 
    while (t--) {
        solve(); 
    }

    return 0;
}