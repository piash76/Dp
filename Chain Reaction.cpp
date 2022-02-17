
///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define ll long long
#define pll  pair<ll,ll>

#define ff    first
#define ss    second


#define  pb  push_back

#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;

const ll inf=1e15;
const int mod=1e9+7;


const int N=1000005;

int a[N],b[N],dp[N];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;cin>>n;

    int mxn=-1;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        b[x]=y;
        a[x]=1; ///there is a beacon
        mxn=max(mxn,x);

    }

    ///dp[i] here it states how many can be saved if
    /// ith beacon was the starting point meaning the right ones
    ///after it is destroyed

    if(a[0]) dp[0]=1;

    for(int i=1;i<=mxn;i++)
    {
        if(a[i])
        {
           if(i-b[i]-1>=0)
           {
               dp[i]=dp[i-b[i]-1]+1;
           }
           else
           {
               dp[i]=1;

           }

        }
        else dp[i]=dp[i-1];
    }

    int ans=-1;

    for(int i=0;i<=mxn;i++)
    {
        ///cout<<dp[i]<<" ";
        ans=max(ans,dp[i]); /// max alive
    }


    cout<<(n-ans)<<endl; ///min dead






    return 0;

}






