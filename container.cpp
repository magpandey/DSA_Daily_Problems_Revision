//This is the famous double pointer problem problem from leetcode .Water container with maximum water contained;;;

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> waterLevel = {1,5,3,6,9,2,4};
    int MaxWater = 0;
    int lp = 0, ep = waterLevel.size() - 1;
    while(lp < ep){
        int wt = ep - lp;
        int ht = min(waterLevel[lp],waterLevel[ep]);
        int area = wt * ht;
        MaxWater = max(MaxWater,area);
        if(waterLevel[lp] < waterLevel[ep]){
            lp++;
        }else{
            ep--;
        }
    }

    return 0;
}