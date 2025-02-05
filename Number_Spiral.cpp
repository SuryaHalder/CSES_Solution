/*
	Author : SURYA HALDER
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define pb push_back
#define endl '\n'
#define maxheap priority_queue<int> //max heap
#define minheap priority_queue <int, vector<int>, greater<int>> //min heap
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define reprev(i,a,b) for(int i=a;i>=b;i--)

template<typename T>
void input(vector<T>& v) {
    for (auto& x : v) {
        cin >> x;
    }
}

template<typename T>
void output(const vector<T>& v) {
    for (const auto& x : v) {
        cout << x << " ";
    }
    cout << '\n';
}

template<typename T>
void sortA(vector<T>& v) {
    sort(v.begin(), v.end());
}

template<typename T>
void sortD(vector<T>& v) {
    sort(v.begin(), v.end(), greater<T>());
}


void solve() {
    /*Your code here */
    /*Observation: (1 based indexing)
    Every principal diagonal element is (n*n)-(n-1);
    For even and odd values of col and row different pattern is being followed
    
   */
    ll y,x;
    cin>>y>>x;
    //y->row, x->col
    ll val=0;
    ll maxi=max(x,y);
    ll diagVal=(maxi*maxi)-(maxi-1);
    //cout<<"diag"<<diagVal<<endl;
    if(y<maxi){
    	if(maxi%2==0) val=diagVal-(maxi-y);
    	else val=diagVal+(maxi-y);
    }
    else{
    	if(maxi%2==0) val=diagVal+(maxi-x);
    	else val=diagVal-(maxi-x);
    }
    cout<<val<<endl;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*Multi testcase*/
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    /*comment till here*/
    //solve();
    return 0;
}
