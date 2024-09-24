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
    ll sum = accumulate(begin(v), end(v), 0LL);
    bool dp[n + 3][sum + 3];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    ll c = 0;
    for(ll i = 1; i <= n; i++) {
        for(ll s = 0; s <= sum; s++) {
            dp[i][s] = dp[i-1][s];
            if(s >= v[i-1] && dp[i-1][s-v[i-1]])
                dp[i][s] = true;
            if(s && dp[n][s])
                c++;
        }
    }
    cout << c << endl;
    for(ll i = 1; i <= sum; i++)
        if(dp[n][i])
            cout << i << " ";
    cout << endl;
    return 0;
}