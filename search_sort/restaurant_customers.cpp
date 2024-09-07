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
    vector<vector<ll>> v;
    for(ll i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        // 1 for person entering
        v.push_back({x, 1});
        // -1 for person exiting
        v.push_back({y, -1});
    }
    sort(v.begin(), v.end());
    ll res = 0, people = 0;
    for(auto val : v) {
        people += val[1];
        res = max(res, people);
    }
    cout << res << endl;
    return 0;
}