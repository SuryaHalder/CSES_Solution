/*
	Author : SURYA HALDER
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long int
#define ff first
#define ss second
#define inf INT_MAX
#define sz size()
#define rtn return
#define rnt return
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define pb push_back
#define endl '\n'
#define maxheap priority_queue<int> //max heap
#define minheap priority_queue <int, vector<int>, greater<int>> //min heap
#define loop(i,a,b) for(int i=a;i<b;i++)     //for loop from a(included)->b(excluded)
#define roop(i,b,a) for(int i=b;i>=a;i--)    //rev. for loop from b(included)->a(inluded)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

//==============Modular arithematic==============//
const int mod=1000000000+7; 
ll mod_pow(ll a,ll b){
    if(b==0) return 1;
    if(b%2){
        return a* mod_pow(a,b-1) %mod;
    }
    ll temp= mod_pow(a,b/2);
    return temp*temp %mod;
}
ll mod_mul(ll a,ll b){
    return ((a%mod) * (b%mod))%mod;
}
ll mod_add(ll a,ll b){
    return ((a%mod) + (b%mod))%mod;
}
ll mod_sub(ll a,ll b){
    return ((a%mod) - (b%mod))%mod;
}
ll mod_inv(ll a,ll b=mod-2){
    return mod_pow(a,b);
}
ll mod_div(ll a,ll b){
    int invb=mod_inv(b);
    return mod_mul(a,invb);
}
//==============End of Modular Arithematic==============//

//==============i/p and o/p==============//
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
//==============end of i/p and o/p==============//

//==============sorting==============//
template<typename T>
void sortA(vector<T>& v) {
    sort(v.begin(), v.end());
}

template<typename T>
void sortD(vector<T>& v) {
    sort(v.begin(), v.end(), greater<T>());
}
//==============End of sorting==============//

int dr[]={-1,0,1,0}; //up,left,down,right
int dc[]={0,-1,0,1};
bool in(int i,int j,int n,int m){
    rtn (i>=0 && i<n && j>=0 && j<m);
}
int queen[8]; //queen[i]->where q. on ith row
bool isv(int r,int c,vector<vector<int>>&a){
	for(int i=0;i<r;i++){
		int prevr=i;
		int prevc=queen[i];
		if((prevc==c)|| abs(c-prevc)==abs(r-prevr)) return false;
	}
	return 1;
}

int f(int r,vector<vector<int>>&a){
	if(r==8){
		return 1;
	}
	int ans=0;
	for(int i=0;i<8;i++){
		if(a[r][i]==-1) continue;
		if(isv(r,i,a)){
			queen[r]=i;
			ans+=f(r+1,a);
			queen[r]=-1;
		}
	}
	return ans;
}
void solve() {
    /*Your code here */
   vector<vector<int>> a(8,vector<int>(8,0));
   for(int i=0;i<8;i++){
   	queen[i]=-1;
   	for(int j=0;j<8;j++){
   		char k;
   		cin>>k;
   		if(k=='*') a[i][j]=-1;
   		else continue;
   	}
   }
   cout<<f(0,a)<<endl; 
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //==============Multi testcase==============//
    int t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
    //==============comment till here==============//
    
    //==============ATCODER ALERT..don't forget to uncomment below==============//
    
    //solve();
    return 0;
}
