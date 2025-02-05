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
    /*Intuition:
    Make half of array containing all even numbers.
    Rest half containing all odd numbers. or vice versa
    because in doing so we maintain diff>=2
    also even half must be in descending order n odd half in descending..
    or vice versa.
    On solving we find no solution possible for n<=4
    because for n=3 diff b/w smallest even and greatest odd is |2-3|=1
    for n=4 |2-3|=1
    */
    /*wrong ans on previous solution*/
    /*correction*/
    /*for n=1 ans is 1 itself coz constraint maintained
    for n=4 permutation 2 4 1 3 is possible*/
    //learning- always check edge cases
    int n;
    cin>>n;
    if(n==1){
    	cout<<1<<endl;
    	return;
    }
    else if(n==2 || n==3){
    	cout<<"NO SOLUTION"<<endl;
    	return;
    }
    else if(n==4){
    	cout<<"2 4 1 3"<<endl;
    	return;
    }
    for(int i=n;i>=1;i-=2) cout<<i<<" ";
    for(int i=n-1;i>=1;i-=2) cout<<i<<" ";
    cout<<endl;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*Multi testcase*/
    // int t;
    // cin >> t;
    // while (t--) {
        // solve();
    // }
    /*comment till here*/
    solve();
    return 0;
}
