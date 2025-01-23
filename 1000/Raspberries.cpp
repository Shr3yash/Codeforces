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

    void solve(){
        int n, k;
        cin >> n >> k;
        int md = 0, even = 0;
        bool div = false;
        
        for (int p = 0; p < n; p++) {
            int x;
            cin >> x;
            x %= k;
            
            if (x) {
                md = max(md, x);  // Using max function instead of manual comparison
            } else {
                div = true;
            }
            if (x == 2) {
                ++even;
            }
        }

        if (div) {
            cout << "0" << endl;
        } else if (k == 4) {
            if (even >= 2) {
                cout << "0" << endl;
            } else if (even >= 1 || md == 3) {
                cout << "1" << endl;
            } else {
                cout << "2" << endl;
            }
        } else {
            cout << (k - md) << endl;
        }
    }
    void solve1() {
        // cout<<"natural selection."<<'\n';
        int n, k, closestToK = INT_MAX, countEvens = 0;
        cin>>n>>k;

        vi arr(n);
        for(int i=0; i<n; i++)
            cin>>arr[i];
        int d = k-1;
        int e_cnt = 0;
        for(int i=0; i<n; i++){
            if((arr[i]%2) == 0)e_cnt++;
            if(arr[i]%k == 0)
                d = 0;
        else
            d = min(d, k-arr[i]%k);
        }

        if(k == 4){
            cout<<d<<newline;
        }else{
            if(e_cnt >= 2)
                cout<<0<<newline;
            else if(e_cnt == 1)
                cout<<min(d, 1)<<newline;
            else
                cout<<min (2, d)<<newline;
        }

        // return; 

        // vector<int> ar(n);
        // for(int i = 0; i < n; ++i){
        //     int buffer = 0;
        //     cin>>buffer;

        //     if(buffer%2 == 0) countEvens++;

        //     int diff  =  k - buffer%k;
        //     closestToK =  min(diff, closestToK);
        //     ar[i] =  buffer%k;
        //     if(buffer%k == 0){
        //         cout<<0<<newline;
        //         return;
        //     }

        //     switch (k)
        //     {
        //     case 2:
        //         cout<<closestToK<<newline;
        //         break;

        //     case 3:
        //         cout<<closestToK<<newline;
        //         break;
            
        //     case 4:
        //     if (countEvens >= 2) {
        //         puts("0");
        //     } else if (countEvens >= 1 || closestToK == 3) {
        //         puts("1");
        //     } else {
        //         puts("2");
        //     }
        //         break;
            
        //     case 5:
        //         cout<<closestToK<<newline;
        //         break;
            
        //     default:
        //         break;
        //     }
        // }
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
