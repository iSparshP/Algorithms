//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    static bool comp(pair<int,double>&a,pair<int,double>&b){
        return a.second>b.second;
    }
    int maxCoins(int A[], int B[], int T, int N) {
        vector<pair<int,double>>vec;
        for(int i=0;i<N;i++){
            vec.push_back({i,B[i]});
        }
        sort(vec.begin(),vec.end(),comp);
        long long x=0,sum=0;
        while(T&&x<N){
            int index=vec[x].first;
            int cnt=A[index];
            cnt=min(cnt,T);
            sum+=cnt*B[index];
            T-=cnt;
            x++;
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}
// } Driver Code Ends