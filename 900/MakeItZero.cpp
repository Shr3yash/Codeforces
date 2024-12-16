#include <bits/stdc++.h>
#include <cmath>
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
#define FOZ(i, n) FOR(i, 0, n)                         // Loop from 0 to n-1
#define ALL(v) (v).begin(), (v).end()                  // Shortcut for whole container
#define RALL(v) (v).rbegin(), (v).rend()               // Reverse container
#define SZ(v) ((int)(v).size())                        // Get size of container

// Input and output shortcuts
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define newline '\n'
#define space " "

// Debugging tools
#define DEBUG(x) cerr << #x << " = " << x << endl;
// make one for square
// Bit manipulation
#define SETBIT(x, pos) (x |= (1LL << pos))             // Set bit at position pos
#define CLEARBIT(x, pos) (x &= ~(1LL << pos))          // Clear bit at position pos
#define TOGGLEBIT(x, pos) (x ^= (1LL << pos))          // Toggle bit at position pos
#define CHECKBIT(x, pos) ((x >> pos) & 1LL)            // Check bit at position pos

// Utility functions
int countDigits(int inpNum) {
    return inpNum == 0 ? 1 : static_cast<int>(log10(abs(inpNum)) + 1);
}

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


void solve() {
    int n;
    cin>>n;
    vi ary(n);

    FOZ(i, n) cin>>ary[i];

    //need to move pointers first at 0, second at 1 and third at n-1.
    //does S of second and third equal first? if no
    //we will still have first at 0 & second at 1 but, third at n-2.
    // like this till 0 to 0 and 1 to 2 and 3 to n-1(for later)
    //first for 0 to 1 this time
    //like this

    
    //it is so silly. if its even choose whole ary and replace to its xor then its zero in the next total xor step anyway
    //for odd, leave last one. replace whole ary with its xor then
    // take last zero and last elem, perform op on them make them same to whatever xor they make and
    // again perform same op so that it becomes zero.

    if(n%2 == 0){
        cout<<2<<newline;
        cout<<1<<space<<n<<newline; //makes same
        cout<<1<<space<<n<<newline; //makes zero
    }else{
        cout<<4<<newline;
        cout<<1<<space<<n-1<<newline; //makes same
        cout<<1<<space<<n-1<<newline; //makes zero

        //second last and last
        cout<<n-1<<space<<n<<newline;
        cout<<n-1<<space<<n<<newline;
    }


}

int main() {
    ios::sync_with_stdio(false); 
    //makes cin, cout faster and desynced with scanf, printf 
    
    //cin by default flushes out cout buffer to ensure prompts are immediately displayed
    //this costs time, if you have a lot of cins and couts
    //Decoupling by
    cin.tie(nullptr);
    //prevents auto-flush
    //you can still flush cout buff if you want to manually by <<endl or <<flsuh
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t; 
    while (t--) {
        solve(); 
    }

    return 0;
}
