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
    ll x, n;
    cin >> x >> n;
    set<ll> points;
    points.insert(0);
    points.insert(x);
    multiset<ll> st;
    st.insert(x);
    while(n--) {
        ll k;
        cin >> k;

        auto it = points.upper_bound(k);
        auto prev = it;
        auto left = *(--prev);
        auto right = *it;

        st.erase(st.find(right - left));
        st.insert(k - left);
        st.insert(right - k);

        points.insert(k);
        cout << *(--st.end()) << " ";
    }
    return 0;
}