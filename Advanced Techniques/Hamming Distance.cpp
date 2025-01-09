#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
#define bug(a) cout << #a << " : " << a << endl;

int string_to_int(string s){
    int ans=0;
    for(int i=s.size()-1, j=0; i>=0; i--, j++)
        if(s[i]=='1') ans += (1<<j);

    return ans;
}

void solve(int cs) {
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        v.push_back(string_to_int(s));
    }

    int ans = INT_MAX;
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            ans = min(ans, __builtin_popcount(v[i]^v[j]));

    cout << ans << endl;

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
