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

ll countSubsetsWithGivenSum(vector<ll> &v, ll s, ll n) {
    ll dp[n + 3][s + 3];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 0; j <= s; j++) {
            if(j >= v[i-1])
                dp[i][j] = dp[i-1][j] + dp[i-1][j-v[i-1]];
            else
                dp[i][j] = dp[i-1][j];
            dp[i][j] %= MOD;
        }
    }
    return dp[n][s];
}

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    ll n;
    cin >> n;
    ll s = n * (n + 1) / 2;
    if(s & 1) {
        cout << 0 << endl;
        return 0;
    }
    s /= 2;
    // Taking only till n - 1 because ans would have been subset count of s / 2 which again is not possible with Mod
    // So its better to always assume n lies in second set for which we are not calculating
    vector<ll> v(n - 1);
    for(ll i = 0; i < n - 1; i++)
        v[i] = i + 1;
    ll c = countSubsetsWithGivenSum(v, s, n - 1);
    cout << c << endl;
}