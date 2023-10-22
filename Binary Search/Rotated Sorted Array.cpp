#include<bits/stdc++.h>

using namespace std;

//------------------Definition --------------//

#define ll unsigned long long int
#define fn() for(int i=1;i<=n;i++)
#define actionbeam cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);

int n;
int arr[100000];
int check(int mid){
    if(arr[mid]>=arr[0])return 1;
    else return 0;
}

int main()
{
    actionbeam
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int lo=0;
        int hi=n-1;
        int ans=0;
        
        while(lo<=hi)
        {
            int mid=(lo+hi)/2;
            if(check(mid)==1)
            {
                lo = mid+1;
            }
            else
            {
                ans = mid;
                hi = mid-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

//------------------ CP TEMPLATE BY SPARSH PRAKASH --------------//
