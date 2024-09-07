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
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(begin(a), end(a));
    if(n & 1) {
        ll mid = a[n/2];
        ll res = 0;
        for(auto val : a)
            res += abs(val - mid);
        cout << res << endl;
    } else {
        ll mid1 = a[n/2+1], mid2 = a[n/2];
        ll res = 0, res2 = 0;
        for(auto val : a)
            res += abs(val - mid1);
        for(auto val : a)
            res2 += abs(val - mid2);
        cout << min(res, res2) << endl;
    }
    return 0;
}