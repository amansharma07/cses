#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

bool getMaxProducts(vector<ll> &a, ll n, ll mid, ll t);

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 

    // 3 7
    // 3 2 5
    fast;
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    ll low = 1, high = *max_element(begin(a), end(a)) * t;
    while(low <= high) {
        ll mid = low + (high - low) / 2;
        bool max_products = getMaxProducts(a, n, mid, t);
        if(max_products)
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout << low << endl;
    return 0;
}

bool getMaxProducts(vector<ll> &a, ll n, ll mid, ll t) {
    ll res = 0;
    for(auto val : a) {
        res += (mid / val);
        if(res >= t)
            return true;
    }
    return res >= t;
}