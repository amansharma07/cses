#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

class Solution {
public:
    #define ll long long
    int K;
    ll dp[12][2][12][12][22];
    ll solve(vector<int> &num, int n, bool tight, int cntEven, int cntOdd, int currRem) {
        if(n == 0) {
            if(cntEven == cntOdd && currRem == 0) {
                return 1;
            }
            return 0;
        }
        if(dp[n][tight][cntEven][cntOdd][currRem] != -1)
            return dp[n][tight][cntEven][cntOdd][currRem];
        int ub = tight ? num[num.size() - n] : 9;
        ll ans = 0;
        for(int i = 0; i <= ub; i++) {
            // isLeading replaced by (cntEven + cntOdd == 0)
            if((cntEven + cntOdd == 0) && i == 0) {
                ans += solve(num, n - 1, 0, 0, 0, 0);
            } else {
                ans += solve(num, n - 1, tight & (i == ub), cntEven + !(i % 2), cntOdd + i % 2, (currRem * 10 + i) % K);
            }
        }
        return dp[n][tight][cntEven][cntOdd][currRem] = ans;
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        memset(dp, -1, sizeof(dp));
        K = k;
        low--;
        vector<int> low_num;
        vector<int> high_num;
        while(low > 0) {
            low_num.push_back(low % 10);
            low /= 10;
        }
        while(high > 0) {
            high_num.push_back(high % 10);
            high /= 10;
        }
        reverse(begin(low_num), end(low_num));
        reverse(begin(high_num), end(high_num));
        ll res1 = solve(high_num, high_num.size(), 1, 0, 0, 0);
        memset(dp, -1, sizeof(dp));
        ll res2 = solve(low_num, low_num.size(), 1, 0, 0, 0);
        return res1 - res2;
    }









    static const int maxDigits = 12;
    static const int countOfOnes = 12;
    int dp[maxDigits][countOfOnes][2];
    int solve(vector<int> &nums, int currPos, int count, bool tight) {
        if(currPos == 0)
            return count;
        if(dp[currPos][count][tight] != -1)
            return dp[currPos][count][tight];
        int ub = tight ? (nums[nums.size() - currPos]) : 9;
        int ans = 0;
        for(int i = 0; i <= ub; i++) {
            ans += solve(nums, currPos - 1, (i == 1 ? 1 : 0) + count, (tight & (i == ub)));
        }
        return dp[currPos][count][tight] = ans;
    }
    int countDigitOne(int n) {
        if(n == 0)
            return 0;
        memset(dp, -1, sizeof(dp));
        vector<int> nums;
        int tem = n;
        while(tem) {
            nums.push_back(tem % 10);
            tem /= 10;
        }
        reverse(begin(nums), end(nums));
        return solve(nums, nums.size(), 0, 1);
    }


















    #define ll long long
    const int MOD = 1e9 + 7;
    ll dp[24][2][2][402];
    ll solve(string &num1, string &num2, int n, bool tight1, bool tight2, int currSum) {
        if(currSum < 0)
            return 0;
        if(n == 0)
            return 1;
        if(dp[n][tight1][tight2][currSum] != -1)
            return dp[n][tight1][tight2][currSum];
        int ub1 = tight1 ? num1[num1.size() - n] - '0' : 0;
        int ub2 = tight2 ? num2[num2.size() - n] - '0' : 9;
        
        ll ans = 0;
        for(int i = ub1; i <= ub2; i++) {
            ans += solve(num1, num2, n-1, tight1 & (i == ub1), tight2 & (i == ub2), currSum - i);
            ans %= MOD;
        }
        return dp[n][tight1][tight2][currSum] = ans;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {

        memset(dp, -1, sizeof(dp));
        int leadingZeroes = num2.length() - num1.length();
        string num1extended = string(leadingZeroes,'0') + num1;


        ll res1 = solve(num1extended, num2, num1extended.length(), 1, 1, max_sum);
        memset(dp, -1, sizeof(dp));
        ll res2 = solve(num1extended, num2, num1extended.length(), 1, 1, min_sum-1);
        return (res1 - res2 + MOD ) % MOD;
    }




    #define ll long long
    ll dp[11][1<<10][2][2];
    int solve(vector<int> &num, int n, int mask, bool isLeading, bool tight) {
        if(n == 0)
            return 1;
        if(dp[n][mask][isLeading][tight] != -1)
            return dp[n][mask][isLeading][tight];
        int ub = tight ? num[num.size() -  n] : 9;
        ll ans = 0;
        for(int i = 0; i <= ub; i++) {
            if(isLeading & (i == 0))
                ans += solve(num, n-1, mask, 1, 0);
            else if(!(mask & (1 << i)))
                ans += solve(num, n - 1, mask | (1<<i), 0, tight & (i == ub));
        }
        return dp[n][mask][isLeading][tight] = ans;
    }
    int numDupDigitsAtMostN(int n) {
        ll tem = n;
        memset(dp, -1, sizeof(dp));
        vector<int> num;
        while(n) {
            num.push_back(n % 10);
            n /= 10;
        }
        reverse(begin(num), end(num));
        return tem - solve(num, num.size(), 0, 1, 1) + 1;
    }
};





int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
}