class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long left = 0;
        unordered_map<int,int>mp;
        long long n = nums.size();
        long long sum = 0;
        long long maxi = 0;

        for(int right = 0; right < n;right ++){
            sum += nums[right];
            mp[nums[right]]++;
           
            if(right - left +1  > k){
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) mp.erase(nums[left]);
                sum -= nums[left];
                left++;
            }
            //agar valid size ka subarray mil gya or mp.size == k hai matlb duplicate nhi h sab unique h
             if(right - left + 1 == k && mp.size() == k){
                
            maxi = max(maxi,sum);
            }
        }
        return maxi;
    }
};