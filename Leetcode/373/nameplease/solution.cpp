// read start 3:54
#include <algorithm>

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>> heap; // <sum, <i,j>>

        for (int i = 0; i<nums1.size(); i++) {
            for (int j = 0; j<nums2.size(); j++) {
                int sum = nums1[i] + nums2[j];
                if (heap.size() < k) {
                    heap.push({sum, make_pair(i,j)});
                } else if (heap.top().first > sum) {
                    heap.pop();
                    heap.push({sum, make_pair(i,j)});
                } else {
                    break;
                }
            }
        }
        
        vector<vector<int>> answer;
        while(!heap.empty()) {
            auto [i, j] = heap.top().second;
            answer.push_back({nums1[i], nums2[j]});
            heap.pop();
        }
        return answer;
    }
};
