#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

void printLCS(vector<ll> &a, vector<ll> &b, ll m, ll n) {
    ll dp[m + 1][n + 1];
    for(ll i = 0; i <=m; i++) {
        for(ll j = 0; j <= n; j++) {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j-1], max(dp[i][j-1], dp[i-1][j]));
        }
    }
    cout << dp[m][n] << endl;
    
    
    ll i = m, j = n, index = dp[m][n];
    vector<ll> lcs(index);
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs[index - 1] = a[i - 1];
            i--;
            j--;
            index--; // reduce values of i, j and index
        }

        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    for(auto val : lcs) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;

    ll m, n;
    cin >> m >> n;
    vector<ll> a(m), b(n);

    for(ll i = 0; i < m; i++)
        cin >> a[i];
    for(ll i = 0; i < n; i++) 
        cin >> b[i];
    printLCS(a, b, m, n);
    return 0;
}