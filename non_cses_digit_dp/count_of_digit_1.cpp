#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

ll dp[20][20][2];

ll solve(vector<ll> &nums, ll currPos, ll count, bool tight) {
    if(currPos == 0)
        return count;
    if(dp[currPos][count][tight] != -1)
        return dp[currPos][count][tight];
    ll ub = tight ? nums[nums.size() - currPos] : 9;
    ll ans = 0;
    for(ll i = 0; i <= ub; i++)
        ans += solve(nums, currPos - 1, count + (i == 1), tight & (ub == i) );
    return dp[currPos][count][tight] = ans;
}

ll countDigitOne(ll n) {
    if(n == 0)
        return 0;
    memset(dp, -1, sizeof(dp));
    vector<ll> nums;
    ll tem = n;
    while(tem) {
        nums.push_back(tem % 10);
        tem /= 10;
    }
    reverse(begin(nums), end(nums));
    return solve(nums, nums.size(), 0, 1);
}

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    ll n;
    cin >> n;
    cout << countDigitOne(n) << endl;
    return 0;
}