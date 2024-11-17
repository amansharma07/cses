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
    ll n, q;
    cin >> n >> q;
    ll m = 31; // Max log2 n

    vector<vector<ll>> sparseTable(m + 1, vector<ll>(n + 1, -1));

    for(ll i = 1; i <= n; i++) {
        cin >> sparseTable[0][i];
    }

    for(ll i = 1; i <= m; i++) {
        for(ll j = 1; j <= n; j++) {
            sparseTable[i][j] = sparseTable[i-1][sparseTable[i-1][j]];
        }
    }

    while(q--) {
        ll x, k;
        cin >> x >> k;
        int ans = x;
        for(ll i = 0; i <= m; i++) {
            if(k & (1 << i)) {
                ans = sparseTable[i][ans];
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}