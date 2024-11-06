#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

#define tc int test;cin>>test;while(test--)
int j=0;

void solve()
{
    stack<int> stk;
    int n,index, area = 0;
    cin>>n;
    int arr[n], left_index[n], right_index[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }


    for(int i=0; i<n; i++) {
        while(!stk.empty()) {
            if(arr[i]>arr[stk.top()]) break;
            else stk.pop();
        }
        
        if(stk.empty()) left_index[i] = 0;
        else left_index[i] = stk.top() + 1;
        
        stk.push(i);
    }

    while(!stk.empty()) { stk.pop(); }

    for(int i=n-1; i>=0; i--) {
        while(!stk.empty()) {
            if(arr[i]>arr[stk.top()]) break;
            else stk.pop();
        }
        
        if(stk.empty()) right_index[i] = n-1;
        else right_index[i] = stk.top() - 1;
        
        stk.push(i);
    }
    for(int i=0; i<n; i++) 
        area = max(area, (right_index[i]-left_index[i]+1) * arr[i]);
    
    cout<<"Case "<<++j<<": ";
    cout<<area<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    tc{
        solve();
    }
}