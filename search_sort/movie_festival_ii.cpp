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
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> a(n, vector<ll>(2));
    multiset<ll> endTimes; // Movie end time of each person
    for(int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    sort(begin(a), end(a), [](const vector<ll> &x, const vector<ll> &y) { return x[1] < y[1];});
    for(ll i = 0; i < k; i++)
        endTimes.insert(0);
    ll res = 0;
    for(auto val : a) {
        auto it = endTimes.upper_bound(val[0]);
		if (it == begin(endTimes)) continue;
		// assign movie to be watched by member in multiset who finishes at time
		endTimes.erase(--it);
		// member now finishes watching at time v[i].first
		endTimes.insert(val[1]);
		res++;
    }
    cout << res << endl;
}