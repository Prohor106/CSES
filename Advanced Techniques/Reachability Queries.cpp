#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
#define bug(a) cout << #a << " : " << a << endl;
#pragma GCC target("popcnt")
 
const int M = 5e4+5;
vector<int> g[M], gT[M], ne[M];
bitset<M> bs[M];
int vis[M], parrent[M];
stack<int> st;
vector<int> v;
 
void dfs1(int node) {
    vis[node] = true;
    for(auto u:g[node])
        if(!vis[u]) dfs1(u);
    st.push(node);
}
 
void dfs2(int node, int par) {
    vis[node] = true;
    parrent[node] = par;
    for(auto u:gT[node])
        if(!vis[u]) dfs2(u, par);
}
 
void dfs3(int node) {
    vis[node] = true;
    bs[node].set(node);
    for(auto u:ne[node]) {
        if(!vis[u]) dfs3(u);
        bs[node] |= bs[u];
    }
}
 
void solve(int cs) {
    int n, m, q, x, y;
    cin >> n >> m >> q;
    for(int i=0; i<m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        gT[y].push_back(x);
    }
 
    for(int i=1; i<=n; i++) if(!vis[i]) dfs1(i);
 
    memset(vis, 0, sizeof(vis));
    while(!st.empty()) {
        int node=st.top();
        st.pop();
        if(!vis[node]) {
            v.push_back(node);
            dfs2(node, node);
        }
    }
 
    for(int i=1; i<=n; i++)
        for(auto u:g[i])
            if(parrent[u]!=parrent[i])
                ne[parrent[i]].push_back(parrent[u]);
 
    memset(vis, 0, sizeof(vis));
    for(auto u:v) if(!vis[u]) dfs3(u);
 
 
    while(q--) {
        cin >> x >> y;
        if(bs[parrent[x]][parrent[y]]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
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
