class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mpp;
        for(int& i: nums){
            mpp[i]++;
        }

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(const auto& it: mpp){
            pq.push({it.second, it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> res;
        for(int i=0; i<k; i++){
            pair<int, int> p = pq.top();
            res.push_back(p.second);
            pq.pop();
        }
        return res;
    }
};
