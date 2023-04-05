//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minimumElement;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
        	if(s.empty()){
        		return -1;
        	}
        	return minimumElement;
       }
       
       /*returns poped element from stack*/
       int pop(){
            int ans=-1;
        	if(s.empty()){
        		return ans;
        	}
        	else{
        	    ans = s.top();
        	    s.pop();
        	    if(ans<minimumElement){
        	        int minOld = minimumElement;
        	        minimumElement=2*minimumElement-ans;
        	        ans = minOld;
        	    }
        	}
        	return ans;
       }
       
       /*push element x into the stack*/
       void push(int x){
        	if(s.empty()){
        		s.push(x);
        		minimumElement=x;
        	}
        	else{
        		if(x<minimumElement){
        			s.push(2*x-minimumElement);
        			minimumElement=x;
        		}
        		else{
        			s.push(x);
        		}
        	}
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends