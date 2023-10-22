#include<bits/stdc++.h>
using namespace std;

//------------------Definition --------------//

#define ll unsigned long long int
#define fn() for(int i=0;i<n;i++)
#define actionbeam cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);

int n,q;
vector<int> arr;

int check(int num)
{
    if(arr[num]>arr[num-1]) return 1;
    else return 0;
}

int main()
{
    actionbeam
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        arr.resize(n);
        fn()
        {
            cin>>arr[i];
        }
        int lo=0;
        int hi=n-1;
        int peak=0;
        while(lo<=hi)
        {
            int mid=(lo+hi)/2;
            if(check(mid)==1)
            {
                peak = mid;
                lo = mid + 1;

            }
            else
            {
                hi = mid - 1;
            }
        }
        while(q--)
        {
            int k;
            cin>>k;
            vector<int> ans;
            lo=0;
            hi=peak-1;
            while(lo<=hi)
            {
                int mid= (lo+hi)/2;
                if(arr[mid]==k)
                {
                    ans.push_back(mid+1);
                    break;
                }
                else if(arr[mid]>k)
                {
                    hi=mid-1;
                }
                else{
                    lo=mid+1;
                }
            }

            lo=peak;
            hi=n-1;
            while(lo<=hi)
            {
                int mid= (lo+hi)/2;
                if(arr[mid]==k)
                {
                    ans.push_back(mid+1);
                    break;
                }
                else if(arr[mid]>k)
                {
                    lo=mid+1;
                }
                else{
                    hi=mid-1;
                }
            }

            for(auto v:ans)
            {
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }
}
//------------------ CP TEMPLATE BY SPARSH PRAKASH --------------//
