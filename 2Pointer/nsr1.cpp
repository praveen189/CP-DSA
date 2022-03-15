#include<iostream>
#include<vector>
#include<stack>
#include<bits/stdc++.h>

using namespace std;
vector<int> NSRFun(vector<int> a, int n){
    // in right case we have to reverse the actual vector.
    vector<int> ans;
    stack<int> s;
    int def = n; // default value if smaller to right is not found.

    for (int  i = n-1; i >=0; i--)
    {
        if(s.size() == 0){
            // stack is empty.
            ans.push_back(def);
        }
        else if(s.size() > 0 && s.top() < a[i]){
            ans.push_back(s.top());
        }
        else if(s.size() > 0 && s.top() >= a[i]){
            // we have to pop the stack 
            while (s.size() > 0 && s.top() >= a[i])
            {
                s.pop();
            }
            
            if(s.size() == 0){
                ans.push_back(def);
            }
            else if(s.top() < a[i]){
                ans.push_back(s.top());
            }
            
        }
        s.push(a[i]);
    }
    
    reverse(ans.begin(), ans.end());

    return ans;
}

int main(){

    vector<int> v = {4,5,2,10,8};
    
    int n = v.size();

    vector<int> ans = NSRFun(v, n);
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
