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

    /*
    1

    1 2 3
    2 4 6
    3 6 9

    1 2 2 3 3 4 6 6 9


    1 2 3 4 5
    2 4 6 8 10
    3 6 9 10 12
    4 8 12 16 20
    5 10 15 20 25


    1 2 2 3 3 4 4 4 5 5 6 6 8 8 9 10 10 10 12 12 15 16 20 20 25
    
    
    
    */

    ll n;
    cin >> n;

    map<ll, ll> freq;
    freq[1] = 1;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 2; j <= sqrt(n + 1) + 1; j++) {
            if(i % j == 0)
                
        }
    }

    ll c = 0;
    ll target = ((n * n) + 1) >> 1;
}