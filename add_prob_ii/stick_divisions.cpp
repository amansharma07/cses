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
    priority_queue<ll> pq;
    for(ll i = 0; i < n; i++) {
        ll a;
        cin >> a;
        pq.push(-a);
    }
    ll res = 0, curr;
    
    while(pq.size() > 1) {
        ll a = -pq.top();
        pq.pop();
        ll b = -pq.top();
        pq.pop();

        curr = a+b;
        res += curr;
        pq.push(-curr);
    }

    cout << res << endl;
    return 0;
}