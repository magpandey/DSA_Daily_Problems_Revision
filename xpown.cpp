#include <iostream>
using namespace std;
//This program is a leetcode famous problem about calculating x to the power of n but here n is high 
//and we are supposed to be preventing the unneccessary time complexity
//Its turn s out for this exact purpose there is this solution ousing binary to reduce the amout of calculation 
//That would be originally required if we go with the standard approach''''''
double myPow(double x, int n){
    if(n == 0) return 1.0;
    if(x == 0) return 0.0;
    if(x == -1 && n%2 == 0) return 1.0;
    if(x == -1 && n%2 != 0) return -1.0;
    if(x == 1) return 1.0;
    long binForm = n;
    double ans = 1;
    if(n<0){
        binForm = -binForm;
        x = 1/x;
    }
    while(binForm>0){
        if(binForm % 2 ==1){
            ans*= x;
        }
        x *= x;
        binForm /= 2;
    }    
    return ans;
}
int main(){
    double num;
    int n;
    cin >> num;
    cin >> n;
    double value = myPow(num,n);
    return 0;
}   