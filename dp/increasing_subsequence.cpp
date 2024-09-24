#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

// O(n^2)
ll lis(vector<ll> &v, ll n) {
    ll dp[n + 3];
    dp[0] = 1;
    ll maxi = 1;
    for(ll i = 0; i < n; i++) {
        dp[i] = 1;
        for(ll j = 0; j < i; j++) {
            if(v[i] > v[j]) {
                dp[i] = max(dp[i], 1 + dp[j]);
                maxi = max(maxi, dp[i]);
            }
        }
    }
    return maxi;
}

// O(n * log(n))

ll LIS(vector<ll> &v, ll n) {
    vector<ll> res;
    res.push_back(v[0]);
    for(ll i = 1; i < n; i++) {
        if(v[i] > res.back()) {
            res.push_back(v[i]);
        } else {
            auto it = lower_bound(begin(res), end(res), v[i]);
            *it = v[i];
        }
    }
    return res.size();
}

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(auto &i : v)
        cin >> i;
    // I love the BinSea approach
    ll res = LIS(v, n);
    cout << res << endl;
}