// Question Link - https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1

class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies,candies+N);
        int min=0;
        int buy=0;
        int free=N-1;
        while(buy<=free){
            min=min+candies[buy];
            buy++;
            free=free-K;
        }
        int max=0;
        buy=N-1;
        free=0;
        while(free<=buy){
            max=max+candies[buy];
            buy--;
            free=free+K;
        }
        vector<int>ans;
        ans.push_back(min);
        ans.push_back(max);
        return ans;
    }
};
