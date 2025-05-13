#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++) cin>>a[i];
    bool fg=true;
    for(int i=1;i<n;i++){
        if(a[i-1]>a[i]){
            fg=false;
            break;
        }
    }
    if(fg) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}