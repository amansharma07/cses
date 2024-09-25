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
    vector<ll> wei(n);
    for(auto &i : wei)
        cin >> i;
    ll maxi = (1 << n) - 1;
    ll dp[maxi + 5][2]; // Count of rides, weight of last ride
    dp[0][0] = 1; // 1 ride
    dp[0][1] = 0; // 0 weight

    for(ll mask = 1; mask <= maxi; mask++) {
        pair<ll, ll> bestResult = {INT_MAX, INT_MAX};
        for(ll i = 0; i < n; i++) {
            if(((1 << i) & mask) == 0)
                continue;
            auto val = dp[(1 << i) ^ mask]; // Result before i was set
            ll prevRide = val[0];
            ll prevWei = val[1];
            if(prevWei + wei[i] <= x) {
                prevWei += wei[i];
            } else {
                prevRide++;
                prevWei = wei[i];
            }
            
            pair<ll, ll> pair = {prevRide, prevWei};
            bestResult = min(bestResult, pair);
        }
        dp[mask][0] = bestResult.first;
        dp[mask][1] = bestResult.second;
    }
    cout << dp[maxi][0] << endl;
}
