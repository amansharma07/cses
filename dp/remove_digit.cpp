#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

ll recur(ll n, ll &steps) {
    if(n < 10) {
        steps++;
        return steps;
    }
    ll temp = n, maxi = 0;
    while(temp != 0) {
        ll r = temp % 10;
        maxi = max(r, maxi);
        temp /= 10;
    }
    steps = 1 + recur(n - maxi, steps);
    return steps;
}

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    ll n;
    cin >> n;
    ll steps = 0;
    recur(n, steps);
    cout << steps << endl;
}