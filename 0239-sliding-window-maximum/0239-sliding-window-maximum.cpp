class Solution {
public:
    #define dbg(...) 42;
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  deque<int>dq;
  int n = nums.size();
  vector<int> ans;
  for (int i = 0;i < n;i++) {
    if (!dq.empty() && dq.front() == i - k) dq.pop_front();
    while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
    dq.push_back(i);
    if (i >= k - 1) ans.push_back(nums[dq.front()]);
  }
  return ans;
}
};