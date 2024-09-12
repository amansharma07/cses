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
    vector<ll> a(n);
    unordered_map<ll, pair<ll, ll>> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i <  n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j)
                continue;
            mp[a[i] + a[j]] = {i, j};
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j)
                continue;
            ll target = x - (a[i] + a[j]);
            if(mp.count(target) && mp[target].first != i && mp[target].first != j && mp[target].second != i && mp[target].second != j) {
                cout << i + 1 << " " << j + 1 << " " << mp[target].first + 1 << " " << mp[target].second + 1 << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}