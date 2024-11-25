void solve() {
  int t; 
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    vi inarr(n);
    for(int i=0; i<n; i++)
    cin>>inarr[i];
    if(k == 1 && !is_sorted(inarr.begin(), inarr.end()))
    cout<<"No"<<nl;
    else
    cout<<"Yes"<<nl;
  }
}

// https://codeforces.com/problemset/problem/1903/A
