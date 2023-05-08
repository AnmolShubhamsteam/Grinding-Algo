// https://practice.geeksforgeeks.org/batch/dsa-4/track/DSASP-Greedy/problem/job-sequencing-problem-1587115620

class Solution 
{
public:
    static bool comp(Job a, Job b){
        return a.profit > b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, comp);
        
        int jobs_done = 0;
        int max_profit = 0;
        int schedule_max = INT_MIN;
        
        for(int i = 0; i < n; i++){
            schedule_max = max(schedule_max, arr[i].dead);
        }
        
        vector<int> schedule(schedule_max + 1, -1);
        
        for(int i = 0; i < n; i++){
            int cur_prof = arr[i].profit;
            int cur_dead = arr[i].dead;
            int cur_id = arr[i].id;
            
            for(int j = cur_dead; j >= 1; j--){
                if(schedule[j] == -1){
                    max_profit += cur_prof;
                    schedule[j] = cur_id;
                    jobs_done++;
                    break;
                }
            }
        }
        
        vector<int> ans;
        ans.push_back(jobs_done);
        ans.push_back(max_profit);
        return ans;
    } 
};
