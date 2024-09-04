#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

ll maxi;

void recur(ll sum, ll idx, ll tem_sum, vector<ll> &a, ll &mini) {
    if(idx == (ll)a.size()) {
       mini = min(mini, abs(sum - 2 * tem_sum));
        return;
    }
    for(int i = idx; i < (ll)a.size(); i++) {
        tem_sum += a[i];
        recur(sum, i + 1, tem_sum, a, mini);
        tem_sum -= a[i];
    }
}

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    ll n;
    cin >> n;

    vector<ll> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    ll mini = INT_MAX;
    recur(sum, 0, 0, a, mini);
    cout << mini << endl;
}