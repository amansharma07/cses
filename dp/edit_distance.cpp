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
const int N = 1e6 + 2;
 
ll lengthOfLCS(string &str1, string &str2, int m, int n) {
    ll dp[m + 2][n + 2];
    for(ll i = 0; i <= m; i++)
        dp[i][0] = 0;
    for(ll i = 0; i <= n; i++)
        dp[0][i] = 0;
    // dp[0][0] = 1;
    for(ll i = 1; i <= m; i++) {
        for(ll j = 1; j <= n; j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
 
ll editDis(string &str1, string &str2, int m, int n) {
    ll dp[m + 2][n + 2];
    for(ll i = 0; i <= m; i++)
        dp[i][0] = i;
    for(ll i = 0; i <= n; i++)
        dp[0][i] = i;
    // dp[0][0] = 1;
    for(ll i = 1; i <= m; i++) {
        for(ll j = 1; j <= n; j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
    }
    return dp[m][n];
}

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    string str1, str2;
    cin >> str1 >> str2;
    int m = (int)str1.size();
    int n = (int)str2.size();
 
    cout << editDis(str1, str2, m, n);
    return 0;
}