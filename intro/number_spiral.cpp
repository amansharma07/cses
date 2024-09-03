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
    ll t;
    cin >> t;
    while(t--) {
        ll x, y;
        cin >> x >> y;
        ll maxi = max(x, y);
        ll num = maxi * maxi;
        ll mini_num = (maxi-1) * (maxi-1) + 1;
        ll mid = (num + mini_num) >> 1;
        if(maxi == x) {
            if(maxi & 1)
                num = mid - abs(x - y);
            else
                num = mid + abs(x - y);
        } else {
            if(maxi & 1)
                num = mid + abs(x - y);
            else
                num = mid - abs(x - y);
        }
        cout << num << endl;
    }
    return 0;
}