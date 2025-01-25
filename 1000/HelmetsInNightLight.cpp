#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()

void solve() {
    ll n, activationCost;
    cin >> n >> activationCost;
    vector<ll> a(n), b(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<pair<ll, ll>> residents;
    for (int i = 0; i < n; i++) {
        residents.push_back({b[i], a[i]});
    }
    
    sort(all(residents), [](pair<ll, ll> a, pair<ll, ll> b) {
        if (a.S == b.S) {
            return (float)a.F / a.S > (float)b.F / b.S;
        }
        return a.S < b.S;
    });
    
    if (activationCost <= residents[0].F) {
        cout << activationCost * n << endl;
        return;
    }
    
    ll totalCost = activationCost;
    ll notified = 1;

    for (auto& resident : residents) {
        ll shareCost = resident.F;
        ll maxShare = resident.S;

        if (notified >= n) break;

        ll peopleToNotify = min(maxShare, n - notified);  
        totalCost += peopleToNotify * shareCost;
        notified += peopleToNotify;
    }

    cout << totalCost << endl;
}

void solve1() {
    int n, activationCost, totalCost = 0;
    cin >> n >> activationCost;

    map<int, int> omp;
    vector<int> a(n), b(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    for (int i = 0; i < n; ++i) {
        omp[b[i]] = a[i];
    }

    totalCost = n * activationCost;

    if (activationCost <= omp.begin()->first) {
        cout << totalCost << endl;
        return;
    }

    int notified = 1;
    totalCost = activationCost;

    for (auto& [shareCost, maxShare] : omp) {
        if (notified >= n) break;

        int peopleToNotify = min(maxShare, n - notified);
        
        totalCost += peopleToNotify * shareCost;
        notified += peopleToNotify;
    }

    cout << totalCost << endl;
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
