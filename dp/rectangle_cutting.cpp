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
    ll a, b;
    cin >> a >> b;
    ll dp[a + 3][b + 3] = {0};
    memset(dp, 0, sizeof(dp));
    for(ll i = 1; i <= a; i++) {
        for(ll j = 1; j <= b; j++) {
            if(i == j)
                dp[i][j] = 0;
            else {
                dp[i][j] = INT_MAX;
                for(ll k = 1; k < i; k++)
                    dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
                for(ll k = 1; k < j; k++)
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
            }
        }
    }
    cout << dp[a][b] << endl;
    return 0;
}