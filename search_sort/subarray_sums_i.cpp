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
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    bool flg = false;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        flg = flg || (v[i] <= x);
    }
    ll res = 0, pref = 0;
    unordered_map<ll, ll> mp;
    for(ll right = 0; right < n && flg; right++) {
        pref += v[right];
        if(pref == x)
            res++;
        if(mp.count(pref-x))
            res += mp[pref-x];
        mp[pref]++;
    }
    cout << res << endl;
    return 0;
}