#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
#define bug(a) cout << #a << " : " << a << endl;

void solve(int cs) {
    ll n, x;
    cin >> n >> x;

    ll arr_l[n], arr_r[n];
    for(ll i=0; i<n/2; i++) cin >> arr_l[i];
    for(ll i=0; i<n-n/2; i++) cin >> arr_r[i];

    vector<ll> l, r;
    for(ll mask=0; mask<(1<<n/2); mask++) {
        ll seg_sum=0;
        for(ll i=0; i<n/2; i++)
            if(mask&(1<<i)) seg_sum += arr_l[i];

        l.push_back(seg_sum);
    }

    for(ll mask=0; mask<(1<<(n-n/2)); mask++){
        ll seg_sum=0;
        for(ll i=0; i<n-n/2; i++)
            if(mask&(1<<i)) seg_sum += arr_r[i];

        r.push_back(seg_sum);
    }
    sort(all(l));
    sort(all(r));

    ll ans=0;
    for(auto u:l){
        auto left = lower_bound(all(r), x-u);
        auto right = upper_bound(all(r), x-u);
        ans += right-left;
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
