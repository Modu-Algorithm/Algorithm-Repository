class Solution {
public:
    vector<int> binarySearch(vector<int>& nums, int target, int start, int end) {
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                return {findLeft(nums, target, start, mid-1), findRight(nums, target, mid+1, end)};
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return {-1, -1};
    }

    int findLeft(vector<int>& nums, int target, int start, int end) {
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                return findLeft(nums, target, start, mid-1);
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return end + 1;
    }

    int findRight(vector<int>& nums, int target, int start, int end) {
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                return findRight(nums, target, mid+1, end);
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return start - 1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (!nums.size()) return {-1, -1};
        return binarySearch(nums, target, 0, nums.size()-1);
    }
};
