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
    vector<vector<ll>> a(n, vector<ll>(3));
    for(int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    sort(begin(a), end(a), [](const vector<ll> &x, const vector<ll> &y){
        if(x[0] != y[0])
            return x[0] < y[0];
        return x[1] > y[1];
    });
    vector<ll> contains(n, 0);
    vector<ll> contained(n, 0);
    ll mini = INT_MAX;
    ll c = 0;
    for(ll i = n-1; i >= 0; i--) {
        if(a[i][1] >= mini) {
            contains[a[i][2]] += c;
        }
        ll prev = mini;
        mini = min(mini, a[i][1]);
        c += (mini <= prev && prev != INT_MAX) ? 1 : 0;
    }

    for(auto val : contains)
        cout << val << " ";
    cout << endl;

    ll maxi = 0;
    c = 0;
    for(ll i = 0; i < n; i++) {
        if(a[i][1] <= maxi) {
           contained[a[i][2]] += c;
        }
        ll prev = maxi;
        maxi = max(maxi, a[i][1]);
        c += (maxi >= prev && prev != 0) ? 1 : 0;
    }

    
    for(auto val : contained)
        cout << val << " ";
    cout << endl;
    return 0;
}