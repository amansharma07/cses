#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

bool canDivideVec(vector<ll> &v, ll sum, ll k) {
    ll curr = 0, count = 1;
    for(auto val: v) {
        if(curr + val > sum) {
            count++;
            curr = val;
            if(count > k)
                return false;
        } else {
            curr += val;
        }
    }
    return count <= k;
}

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    ll low = *max_element(begin(v), end(v));
    ll high = accumulate(begin(v), end(v), 0LL);
    while(low <= high) {
        ll mid = low + (high - low) / 2;
        // debug3(low, high, mid);
        bool canDivide = canDivideVec(v, mid, k);
        if(canDivide)
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout << low << endl;
    return 0;
}