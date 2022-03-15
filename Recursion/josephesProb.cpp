#include<iostream>
#include<vector>

using namespace std;
void JosephesProb(vector<int> v, int index, int k, int &ans){

    // base condition.
    // if vector have one ele left then the value of that ele is the postion was safe.
    
    if(v.size() == 1){
        ans =v[0];
        return ;    
    }

    index = (index + k)%v.size(); // at this postion the person will die 
    v.erase(v.begin()+ index);

    // hypo
    // after the  index ele person dies 
    JosephesProb(v,index, k, ans);

    return;

}
int main(){

    // n and k 
    // we have to find the value of positon where the last person left in cave.
    int n =40, k =7;

    // cout<<"Enter n and then k: ";
    // cin>>n >>k;

    vector<int> v;
    for(int i = 1; i<=n ;i++){
        v.push_back(i);
    }

    // for(int i = 0; i<v.size(); i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;

    int ans = -1;
    int index = 0;
    JosephesProb(v, 0, --k, ans);

    cout<<" Position is: "<<ans;
    return 0;
}