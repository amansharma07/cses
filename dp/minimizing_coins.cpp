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
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(auto &i : a)
        cin >> i;
    ll dp[x + 3];
    for(ll i = 1; i <= x; i++)
        dp[i] = INT_MAX;
    dp[0] = 0;
    for(auto &coin : a) {
        for(ll sum = coin; sum <= x; sum++) {
            dp[sum] = min(dp[sum], 1 + dp[sum - coin]);
        }
    }
    cout << (dp[x] == INT_MAX ? -1 : dp[x]) << endl;
}