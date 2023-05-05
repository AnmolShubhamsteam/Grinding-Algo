#include<bits/stdc++.h>
using namespace std;
int maxCoins(int coin[],int n,int amt){
    sort(coin,coin+n,greater<int>());
    int res=0;
    for (int i = 0; i < n; i++)
    {
        if(coin[i]<=amt){
            int c=floor(amt/coin[i]);
            res=res+c;
            amt=amt-(c*coin[i]);
        }
        if(amt==0){
            break;
        }
    }
    return res;
    
}
int main(){
    int coin[4]={5,10,1,2};
    int amt=51;
    cout<<maxCoins(coin,4,amt);
    return 0;
}