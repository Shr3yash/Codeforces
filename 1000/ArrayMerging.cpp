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
int parity(ll x) {return x%2 == 0 ? 1:0;}
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


void solvee() {
    // cout<<"natural selection."<<'\n';
    int n, streak = 1;
    cin>>n;

    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0; i<n; ++i){
        cin>>a[i]>>b[i];
    }

    int localStreakA = 0, localStreakB = 0;
    for(int i = 0; i<n-1; ++i){
        if(a[i] ==  b[i+1]){
            localStreakA++;
        }
        if(a[i+1] ==  b[i]){
            localStreakB++;
        }
        streak = max(streak, localStreakA);
        streak = max(streak, localStreakB);
        if(a[i+1] !=  b[i])localStreakB = 1;
        if(a[i] !=  b[i+1])localStreakA = 1;
    }
    cout<<streak<<newline;  
}

void solve(){
long n;
        std::cin >> n;
        std::map<long, long> a, b;
        long prev = -1, cur = 0;

        // Process the first array
        for (long p = 0; p < n; ++p) {
            long x;
            std::cin >> x;
            if (x != prev) {
                if (prev > 0 && (!a.count(prev) || a[prev] < cur)) {
                    a[prev] = cur;
                }
                cur = 0;
            }
            ++cur;
            prev = x;
        }
        if (!a.count(prev) || a[prev] < cur) {
            a[prev] = cur;
        }

        // Process the second array
        prev = -1, cur = 0;
        for (long p = 0; p < n; ++p) {
            long x;
            std::cin >> x;
            if (x != prev) {
                if (prev > 0 && (!b.count(prev) || b[prev] < cur)) {
                    b[prev] = cur;
                }
                cur = 0;
            }
            ++cur;
            prev = x;
        }
        if (!b.count(prev) || b[prev] < cur) {
            b[prev] = cur;
        }

        // Calculate the maximum length
        long mx = 0;
        for (const auto& [key, val] : a) {
            long total = val;
            if (key > 0 && b.count(key)) {
                total += b[key];
            }
            mx = std::max(mx, total);
        }
        for (const auto& [key, val] : b) {
            long total = val;
            if (key > 0 && a.count(key)) {
                total += a[key];
            }
            mx = std::max(mx, total);
        }

        std::cout << mx << '\n';
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
