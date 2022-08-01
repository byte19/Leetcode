class NumArray
{
public:
    vector<int> vec;
    int sum = 0;
    NumArray(vector<int> &nums)
    {
        vec = nums;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
    }

    void update(int index, int val)
    {
        sum -= vec[index];
        vec[index] = val;
        sum += vec[index];
    }

    int sumRange(int left, int right)
    {
        int ans = sum;
        for (int i = 0; i < left; i++)
            ans -= vec[i];
        for (int i = right + 1; i < vec.size(); i++)
            ans -= vec[i];
        return ans;
    }
};