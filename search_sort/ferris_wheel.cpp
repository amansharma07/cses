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
    // freopen("test_input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(begin(a), end(a));
    int i;
    ll res = 0, low = 0, high = n-1;
    while(low <= high) {
        if(a[low] + a[high] <= x) {
            low++;
            high--;
            res++;
        } else {
            high--;
            res++;
        }
    }
    cout << res << endl;
    return 0;
}