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

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    ll n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++)
            cin >> grid[i][j];
    }
    ll dp[n + 3][n + 3];
    dp[0][0] = grid[0][0] == '.' ? 1 : 0;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            if(i == 0 && j == 0) {
                dp[0][0] = grid[0][0] == '.' ? 1 : 0;
            } else if (i == 0) {
                dp[0][j] = grid[i][j] == '*' ? 0 : dp[0][j-1];
            } else if (j == 0) {
                dp[i][0] = grid[i][j] == '*' ? 0 : dp[i-1][0];
            } else {
                dp[i][j] = grid[i][j] == '*' ? 0 : dp[i-1][j] + dp[i][j-1];
            }
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n-1][n-1];
    return 0;
}