#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
#define bug(a) cout << #a << " : " << a << endl;
#pragma GCC target("popcnt")

void solve(int cs) {
    int n;
    cin >> n;
    string s;
    bitset<3000> arr[n];
    for(int i=0; i<n; i++){
        cin >> s;
        bitset<3000>bs(s);
        arr[i] = bs;
    }

    ll ans = 0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            ll cnt = (arr[i]&arr[j]).count();
            ans += (cnt*(cnt-1))/2;
        }
    }

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
