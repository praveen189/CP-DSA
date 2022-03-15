#include<iostream>
#include<vector>

using namespace std;

int main(){
    // sum of first 10 fibonacci series 
    
    int n = 100;

    vector<double> fiboVec;
    double first = 1;
    double sec = 2;
    fiboVec.push_back(first);
    fiboVec.push_back(sec);

    for(int i = 2; i<n; i++){
        double sum = first + sec;
        fiboVec.push_back(sum);
        first = sec;
        sec = sum;
    }
    for(int i = 0; i<n; i++){
        cout<<fiboVec[i]<<" ";
    }

    double res = 0;
    for(int i = 0; i<n; i++){
        // double x = fiboVec[i];
        if( int(fiboVec[i]) % 2 == 0){
            res += fiboVec[i];
        }
    }
    cout<<"\nsum of first even no <10th term: "<<res;
    return 0;


}