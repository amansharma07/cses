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
    ll q;
    cin >> q;
    while(q--) {

        //69
        
        // k = 60 --> digits = 2
        // index = 2
        // num = 10 + 60/2 - 1 --> 39
        // 9


        ll k;
        cin >> k;
        ll base = 9, digits = 1;
        while(k - base * digits > 0) {
            k -= base * digits;
            base *= 10;
            digits++;
        }

        /*
        int index = (k % digits == 0) ? digits : k % digits;

        ll num = 1; 
        // Reach the starting number
        for(int i = 1; i < digits; i++)
            num *= 10;
        num += (index == digits) ? k / digits - 1 : k / digits;

        for(int i = index; i < digits; i++)
            num /= 10;
        cout << num % 10 << endl;

        */

        // Option 2
        // Simplified a bit

        int index = k % digits;
        ll num = pow(10, digits - 1) + (k-1) / digits;
        if(index != 0) {
            num = num / pow(10, digits - index);
        }
        cout << num % 10 << endl;
    }
    return 0;
}