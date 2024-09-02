#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;


ll longestUniqueSubArray(vector<ll> &v, ll n) {
    ll res = 0;
    map<ll, ll> mp;
    ll len = 0, prev = 0;
    ll i;
    for(i = 0; i < n; i++) {
        if(mp.find(v[i]) == mp.end()) {
            mp[v[i]] = i;
        } else {
            if(mp[v[i]] >= prev)
                prev = mp[v[i]] + 1;
            mp[v[i]] = i;
        }
        res = max(res, i - prev + 1);
    }
    return res;
}

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    ll n;
    cin >> n;
    vector<ll> songs(n);
    for(ll i = 0; i < n; i++) {
        cin >> songs[i];
    }
    ll res = longestUniqueSubArray(songs, n);
    cout << res << endl;
}