#include<iostream>
#include<vector>

using namespace std;

int res(int n, int s){
    int result = 0;
    for(int  i = s; i<n; i = i+s){
        result += i;
    }
    return result;
}

int main(){
    //find sum of multiple of 3 and 5 below 1000
    int n = 1000;
    int sum3 = res(n,3);
    // cout<<sum3<<endl;
    int sum5 = res(n,5);
    int sum15 = res(n,15);
    cout<<"Sum3: "<<sum3<<endl<<"Sum5: "<<sum5<<endl<<"sum15:"<<sum15<<endl;
    cout<<"Collective result: "<<(sum3 + sum5 -sum15);


    return 0;

}