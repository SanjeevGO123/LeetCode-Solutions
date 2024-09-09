class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;

        int jumps = 0;
        int curr = 0;
        int far = 0;

        for (int i = 0; i < n - 1; ++i) {
            far = max(far, i + nums[i]);
            if (i == curr) {
                jumps++;
                curr = far;
                if (curr >= n - 1)
                    break;
            }
        }

        return jumps;
    }
};