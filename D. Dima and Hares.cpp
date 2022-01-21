
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

const int inf=1e8;
const int mod=1e9+7;


const int N=3005;

int n,a[N],b[N],c[N],dp[N][2];


int solve(int idx,int prev)
{
    ///cout<<"IDx "<<idx<<" Rt "<<rt<<" LFT "<<lft<<endl;

    if(idx==n-1)
    {
        if(prev==0)
        {
            return a[idx];
        }
        else
        {
            return b[idx];
        }

    }

    if(dp[idx][prev]!=-1) return dp[idx][prev];

    int s=-1;

    if(prev==0)
    {
        ///if 2 before 1-prev and 3-next
        s=max(s,a[idx]+solve(idx+1,1));

        ///if 2 before 1-prev and after 3-next (first 3 then 2)
        s=max(s,b[idx]+solve(idx+1,0));

    }
    else
    {
        ///if 2 after prev-1 but before next-3
        s=max(s,b[idx]+solve(idx+1,1));

        ///if 2 after prev-1 and next-3    ...1...3....2
        s=max(s,c[idx]+solve(idx+1,0));

    }




   /// cout<<"FINAL IDx "<<idx<<" Rt "<<rt<<" LFT "<<lft<<endl;
    ///cout<<"S "<<s<<endl;

    return dp[idx][prev]=s;
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }




    memset(dp,-1,sizeof(dp));

    int ans=solve(0,0);

    cout<<ans<<endl;



    return 0;

}






