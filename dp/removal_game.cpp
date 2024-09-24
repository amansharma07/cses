#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

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
    ll sum = accumulate(begin(v), end(v), 0LL); // s1 + s2
    vector<vector<ll>> dp(n, vector<ll>(n)); // all possible s1 - s2 over range of indices pair
    // Reverse iteration because we need answer of l+1, r
    // Two pointer approach
    for(ll left = n-1; left >= 0; left--) {
        for(ll right = left; right < n; right++) {
            if(left == right)
                dp[left][right] = v[left];
            else {
                dp[left][right] = max(v[left] - dp[left + 1][right], v[right] - dp[left][right - 1]);
            }
        }
    }
    ll res = (sum + dp[0][n-1]) / 2; // s1 = (sum + diff) / 2
    cout << res << endl;
}