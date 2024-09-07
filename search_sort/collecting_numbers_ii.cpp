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
    // 1 3 5 4 2    ---> 12, 34, 5                 
    // 3 2 1        ---> 1, 2, 3                        
    // 6 4 3 1 2 5  ---> 12, 3, 45, 6
    // 6 3 1 2 5 4  ---> 12, 34, 5, 6
    // 1 2 3        ---> 123
    // 1 2 3 5 4    ---> 1234, 5
    // N and n+1 can be in same group only if N is before N+1
    fast;
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    unordered_map<ll, ll> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    vector<ll> copy(a);
    sort(begin(copy), end(copy));
    ll res = 1;
    for(ll i = 1; i < n; i++) {
        if(mp[copy[i]] < mp[copy[i-1]])
            res++;
    }
    // debug(res);
    while(m--) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        if(x == y) {
            cout << res << endl;
            continue;
        }
        // debug2(x, y);
        ll v1 = a[x], v2 = a[y];
        ll v3 = a[x] - 1;
        ll v4 = a[x] + 1;
        ll v5 = a[y] - 1;
        ll v6 = a[y] + 1;
        // debug2(v1, v2);
        // debug4(v3, v4, v5, v6);
        
        ll diff1, diff2;
        set<vector<ll>> st;
        if(v3 >= 1) {
            diff1 = x - mp[v3];
            diff2 = y - mp[v3];
            if(diff1 < 0 && diff2 >= 0) {
                st.insert({v3, a[x], -1});
            } else if(diff1 > 0 && diff2 <= 0) {
                st.insert({v3, a[x], 1});
            }
        }

        if(v4 <= n) {
            diff1 = mp[v4] - x;
            diff2 = mp[v4] - y;
            if(diff1 < 0 && diff2 >= 0) {
                st.insert({a[x], v4, -1});
            } else if(diff1 > 0 && diff2 <= 0) {
                st.insert({a[x], v4, 1});
            }
        }

        if(v5 >= 1) {
            diff1 = y - mp[v5];
            diff2 = x - mp[v5];
            if(diff1 < 0 && diff2 >= 0) {
                st.insert({v5, a[y], -1});
            } else if(diff1 > 0 && diff2 <= 0) {
                st.insert({v5, a[y], 1});
            }
        }

        if(v6 <= n) {
            diff1 = mp[v6] - y;
            diff2 = mp[v6] - x;
            if(diff1 < 0 && diff2 >= 0) {
                st.insert({a[y], v6, -1});
            } else if(diff1 > 0 && diff2 <= 0) {
                st.insert({a[y], v6, 1});
            }
        }

        for(auto val : st) {
            // debug3(val[0], val[1], val[2]);
            res += val[2];
        }
        cout << res << endl;
        mp[a[x]] = y;
        mp[a[y]] = x;
        a[x] = v2;
        a[y] = v1;
    }
    return 0;
}