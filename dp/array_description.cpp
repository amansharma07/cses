#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

const int MOD = 1e9 + 7;

ll dp[100005][105];

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for(auto &i : v)
        cin >> i;
    if(v[0] == 0) {
        for(ll i = 1; i <= m; i++)
            dp[0][i] = 1;
    }
    else
        dp[0][v[0]] = 1;
    for(ll i = 1; i < n; i++) {
        if(v[i] == 0) {
            for(ll j = 1; j <= m; j++) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1];
                dp[i][j] %= MOD;
            }
        } else {
            ll j = v[i];
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1];
            dp[i][j] %= MOD;
        }
    }

    ll ans = 0;

    for (int val = 1; val <= m; val++) {
        ans = (ans + dp[n - 1][val]) % MOD;
    }

    cout << ans;
    return 0;
}