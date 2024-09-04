#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

void recur(string str, string &tem, int idx, set<string> &st, vector<bool> &vis) {
    if(idx == (int)str.size()) {
        st.insert(tem);
        return;
    }
    for(int i = 0; i < (int)str.size(); i++) {
        if(!vis[i]) {
            vis[i] = true;
            tem.push_back(str[i]);
            recur(str, tem, idx + 1, st, vis);
            tem.pop_back();
            vis[i] = false;
        }
    }
}

void back_swap(int left, int right, string &str, set<string> &st) {
    if(left == right) {
        st.insert(str);
    }
    for(int i = left; i <= right; i++) {
        swap(str[left], str[i]);
        back_swap(left + 1, right, str, st);
        swap(str[left], str[i]);
    }
}

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    string str;
    cin >> str;
    sort(begin(str), end(str));
    set<string> st;

    // Option 1
    // do {
    //     st.insert(str);
    // } while(next_permutation(begin(str), end(str)));
    // cout << st.size() << endl;
    // for(auto val : st)
    //     cout << val << endl;
    // return 0;



    // Option 2
    // recursion considering array
    // int n = (int)str.size();
    // string tem = "";
    // vector<bool> vis(n, false);
    // recur(str, tem, 0, st, vis);
    // cout << st.size() << endl;
    // for(auto val : st)
    //     cout << val << endl;
    // return 0;



    // Option 3
    // Recursion using swaps
    int n = (int)str.size();
    int l = 0, r = n-1;
    back_swap(l, r, str, st);
    cout << st.size() << endl;
    for(auto val : st)
        cout << val << endl;
    return 0;
}