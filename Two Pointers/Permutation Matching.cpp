#include<bits/stdc++.h>
using namespace std;

void solve()
{
  int n,m;
  cin>>n>>m;
  vector<int> s(n),p(m);
  for(int i=0;i<n;i++)
  {
     cin>>s[i];
  }
  for(int i=0;i<m;i++)
  {
     cin>>p[i];
  }
  vector<int> freq(100100,0);
  for(auto x:p)
  {
     freq[x]++;
  }
  int mismatch=0;
  for(int i=0;i<100100;i++)
  {
     if(freq[i]!=0)mismatch++;
  }
  for(int i=0;i<n;i++)
  {
     if(freq[s[i]]==0)mismatch++;
     freq[s[i]]--;
     if(freq[s[i]]==0)mismatch--;
     if(i-m>=0)
     {
        if(freq[s[i-m]]==0)mismatch++;
        freq[s[i-m]]++;
        if(freq[s[i-m]]==0)mismatch--;
     }
     if(mismatch==0)
     {
        cout<<i-m+1<<endl;
     }
  }
}

int main() 
{
  actionbeam;
  solve();
  return 0;
}
