#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

void balanceSets(std::multiset<ll> &low, std::multiset<ll> &high)
{
    ll size1 = low.size(), size2 = high.size();
    if (size1 > 0 && size2 > 0)
    {
        auto max_low = low.rbegin();
        auto min_high = high.begin();

        if (*max_low > *min_high)
        {
            // s1 -= (*max_low - *min_high);
            // s2 += (*max_low - *min_high);

            low.insert(*min_high);
            high.insert(*max_low);
            high.erase(high.find(*min_high));
            low.erase(low.find(*max_low));
        }
    }
}

void slidingWindowMedian(vector<ll> &v, ll n, ll k) {
    multiset<ll> low, high;
    // ll s1 = 0, s2 = 0;
    for(ll i = 0; i < n; i++) {
        if(i >= k) {
            if(low.find(v[i-k]) != low.end()) {
                low.erase(low.find(v[i-k]));
                // s1 -= v[i-k];
            } else {
                high.erase(high.find(v[i-k]));
                // s2 -= v[i-k];
            }
        }
       
        ll size1 = low.size(), size2 = high.size();

        if(size1 <= size2) {
            // s1 += v[i];
            low.insert(v[i]);
        } else {
            // s2 += v[i];
            high.insert(v[i]);
        }

        balanceSets(low, high);

        // size1 = low.size(), size2 = high.size();

        if(i >= (k-1)) {
            ll median = *low.rbegin();
            // cout << (size1 * median - s1) + (s2 - median * size2) << " ";
			cout << median << " ";
        }
    }
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
    slidingWindowMedian(v, n, k);
    return 0;
}