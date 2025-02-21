
/*
	Author : SURYA HALDER
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
//#define int long long int
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

void solve() {
    /*Your code here */
    int n,m;
    cin>>n>>m;
    vi x(n+1);
    loop(i,1,n+1) cin>>x[i];
    //count inversion similar to counting no. I problem
    vector<int> pos(n+1);
    for(int i=1;i<=n;i++) pos[x[i]]=i;
    int ans=1; //atleast 1 pass needed
    for(int i=1;i<n;i++){
    	// 1 2 3 5 4
    	//pos of 5 before 4 so one extra pass needed
    	if(pos[i]>pos[i+1]) ans++;
    }
    int a,b;
    set<pair<int,int>> s;
    //cout<<ans<<endl;
    while(m--){
    	cin>>a>>b;
    	if(x[a]+1<=n) s.insert({x[a],x[a]+1});
    	if(x[a]-1>=1) s.insert({x[a]-1,x[a]});
    	if(x[b]+1<=n) s.insert({x[b],x[b]+1});
    	if(x[b]-1>=1) s.insert({x[b]-1,x[b]});
    	for(pair<int,int> swapped:s){
    		//smaller value coming after larger value
    		//so after swapping, this inversion is no more
    		if(pos[swapped.ff]>pos[swapped.ss]) ans--; //undoing inversion caused by swapping
    	}
    	pos[x[a]]=b;
    	pos[x[b]]=a;
    	swap(x[a],x[b]);
    	
    	//after swaping, we check how many more inversion made by us
    	//now redoing inversion caused by swapping
    	for(pair<int,int> swapped:s){
    		//smaller value coming after larger value
    		if(pos[swapped.ff]>pos[swapped.ss]) ans++; //redoing inversion caused by swapping
    	}
    	cout<<ans<<endl;
    	s.clear();
    }
    
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
