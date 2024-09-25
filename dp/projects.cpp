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
    vector<vector<ll>> v(n, vector<ll>(3));
    for(auto &i : v)
        cin >> i[0] >> i[1] >> i[2];
    sort(begin(v), end(v), [](const vector<ll> &a, const vector<ll> &b) {
        return a[1] < b[1];
    });
    ll bestTotalReward = 0;
    map<ll, ll> dp; // {endTime : BestTotalRewardSoFar}
    dp[0] = 0;
    for(auto val : v) {
        auto it = dp.lower_bound(val[0]);
        it--;
        ll reward = it->second + val[2];
        bestTotalReward = max(bestTotalReward, reward);
        dp[val[1]] = bestTotalReward;
    }
    cout << bestTotalReward << endl;
    return 0;
}