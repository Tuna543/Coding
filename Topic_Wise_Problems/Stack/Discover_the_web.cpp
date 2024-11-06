#include<iostream>
#include<string>
#include<stack>

using namespace std;
#define ll long long int
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
//#define srt_v sort(v.begin(),v.end())
#define srt_v(n) sort(v,v+n)
#define all(v) v.begin(),v.end()
#define tc int test;cin>>test;while(test--)
#define rep(i,a,b) for(int i=a; i<b; i++)
#define rev(i,a,b) for(int i=a; i>=b; i--)
#define vpi vector<pair<int,int> >
#define MAX  100000002
int j=0;
void solve()
{
    stack<string> bs,fs;
    string input,s,current="http://www.lightoj.com/";
    cout<<"Case "<<++j<<":\n";
    while(true){
    cin>>input;
    if(input=="VISIT"){
        //if(current.size()!=0)
            bs.push(current);
        cin>>s;
        current=s;
        cout<<current<<"\n";
        while(!fs.empty())
            fs.pop();
    }
    else if(input=="BACK"){
        if(bs.empty())
            cout<<"Ignored\n";
        else{
        //if(current.size()!=0)
            fs.push(current);
        current=bs.top();
        bs.pop();
        cout<<current<<"\n";
        }
    }
    else if(input=="FORWARD"){
        if(fs.empty())
            cout<<"Ignored\n";
        else{
        //if(current.size()!=0)
            bs.push(current);
        current=fs.top();
        fs.pop();
        cout<<current<<"\n";
        }
    }
    else return;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    tc{
    solve();
    }
    return 0;
}