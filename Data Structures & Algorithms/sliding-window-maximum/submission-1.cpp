class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k > nums.size()) return {};

        priority_queue<pair<int, int>, vector<pair<int,int>>> pq;
        
        int start = 0;
        
        for(int i=0; i<k; i++){
            pq.push({nums[i], i});
            // cout << nums[i];
        }
        vector<int> ans;
        ans.push_back(pq.top().first);

        for(int i=k; i<nums.size(); i++){
            pq.push({nums[i], i});
            start++;
            pair<int, int> seq = pq.top();

            while(seq.second < start){ 
                pq.pop();
                seq = pq.top();
            }
            ans.push_back(seq.first);
            // cout << seq.first;   
        }

        return ans;
    }
};
/* 
first insert all K elements in the heap.. then go throught the sliding widnow.. add elems.. and if elems on top has index < start.. pop them

store elems in pair in min heap.. <elem, index>
 */