#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
#define bug(a) cout << #a << " : " << a << endl;
#pragma GCC target("popcnt")

const int M = 5e4+5;
vector<int> g[M];
bitset<M> bs[M];
int vis[M];

void dfs(int n) {
    vis[n] = 1;
    for(auto u:g[n]){
        if(!vis[u]) dfs(u);
        bs[n] |= bs[u];
    }
}

void solve(int cs) {
    int n, m, x, y;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
    }

    for(int i=1; i<=n; i++) bs[i].set(i);
    for(int i=1; i<=n; i++) 
        if(!vis[i]) dfs(i);

    for(int i=1; i<=n; i++) cout << bs[i].count() << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t=1, cs=1;
    //cin>>t;
    while(t--) {
        solve(cs++);
    }
    return 0;
}
