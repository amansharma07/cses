#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

ll dp[100005];

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    // x is max weight
    ll n, x;
    cin >> n >> x;
    vector<ll> wei(n), val(n);
    for(auto &i : wei)
        cin >> i;
    for(auto &i : val)
        cin >> i;
    for(int i = 0; i < n; i++) {
        for(int j = x; j >= wei[i]; j--) {
            // if(j < wei[i])
            //     continue;

            dp[j] = max(dp[j], val[i] + dp[j-wei[i]]);
        }
    }
    cout << dp[x] << endl;
    return 0;
}