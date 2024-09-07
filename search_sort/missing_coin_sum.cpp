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
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(begin(a), end(a));
    /*
    My thought
    
    If you have the current answer ans, and a number you didn't use yet x that is not larger that it, 
    you can generate all numbers from 1 to ans+x-1 because you can use x with 1 to ans-1 from before 
    to generate x+1 to ans+x-1 and just used 1 to x from before for the rest. 
    so ans += x.

    If all the numbers are larger than ans, you're stuck. 
    and the cleanest way to check that is to sort the elements and loop from the smallest to the largest
    */
    // Take first missing sum as 1
    /*
    GPT

    The approach relies on the fact that if you can form all sums up to some value x, and the next coin is greater than x + 1, 
    then the smallest sum that cannot be formed is x + 1. I
    f a coin is less than or equal to x + 1, it can extend the range of sums you can form.
    */
    ll missing_sum = 1;
    for(auto val : a) {
        if(val > missing_sum)
            break;
        missing_sum += val;
    }
    cout << missing_sum << endl;
}