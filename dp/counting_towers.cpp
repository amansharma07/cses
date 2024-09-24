#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

ll dp_a[1000003]; // Towers where the two cells of top most row are part of same block
ll dp_b[1000003]; // Towers where the two cells of top most row are part of different block

const int MOD = 1e9 + 7;

void pre() {
    dp_a[1] = 1;
    dp_b[1] = 1;
    for(ll i = 2; i <= 1e6; i++) {
        dp_a[i] = 2 * dp_a[i-1] + dp_b[i-1];
        dp_a[i] %= MOD;
        dp_b[i] = 4 * dp_b[i-1] + dp_a[i-1];
        dp_b[i] %= MOD;
    }
}

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    pre();
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        cout << (dp_a[n] + dp_b[n]) % MOD << endl;
    }
}