//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool isVowel(char ch){
	    ch=tolower(ch);
	    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
	        return true;
	    }
	    return false;
	}
	string removeVowels(string S) 
	{
	    // Your code goes here
	    string ans="";
	    for(int i=0;i<S.size();i++){
	        if(!isVowel(S[i])){
	            ans.push_back(S[i]);
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.


int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	string tc;
   	getline(cin, tc);
   	t = stoi(tc);
   	while(t--)
   	{
   		string s, ch; 

	    getline(cin, s);  
   		
       
   		Solution ob;
   		cout << ob.removeVowels(s) << "\n";
   		
   	}

    return 0;
}
// } Driver Code Ends