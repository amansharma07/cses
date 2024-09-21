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
ll dp[(ll)1e6 + 5];
    
int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for(auto &i : v)
        cin >> i;
    dp[0] = 1;
    for(ll j = 0; j < n; j++) {
        for(ll i = 0; i <= x; i++) {
            if(v[j] <= i) {
                dp[i] = (dp[i] + dp[i-v[j]]) % MOD;
            }
        }
    }
    cout << dp[x] << endl;
}