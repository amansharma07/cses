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
    cout << 0 << endl;
    for(int i = 2; i <= n; i++) {
        ll sq = i * i;
        ll tot = ( sq * (sq-1) ) >> 1; // nC2
        ll attack = 2 * ((i - 1) * (i - 2) + (i - 2) * (i - 1)); // 2*3 grids + 3*2 grids times two because two possibilities for both
        /* 
        . #       # .
        . .  and  . .
        # .       . #

        similarly for 2*3 as well

        */

        ll ways = tot - attack;
        cout << ways << endl;
    }
    return 0;
}