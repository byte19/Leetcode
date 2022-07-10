class Solution {
public:
   
	int maxResult(vector<int>& nums, int k)
	{
		vector<int> cache(nums.size(), INT_MIN);

		// index  size - 1
		// bottom up best cached result at last element is the value of last element 
		cache[nums.size() - 1] = nums[nums.size() - 1];
		// best index so far is the last element
		int bestIndex = nums.size() - 1;

		// calculate best values for the rest of the indices [size - 2 .. 0]
		for (int i = nums.size() - 2; i >= 0; i--)
		{
			// if we can't reach the best index directly we need to calculate a new one that is within range
			if (i + k < bestIndex)
			{
				int maxScore = INT_MIN;
				for (int j = i + 1; (j <= i + k) && (j < nums.size()); j++)
				{
					if ((cache[j]) > maxScore)
					{
						maxScore = cache[j];
						bestIndex = j;
					}
				}           
			}

			cache[i] = nums[i] + cache[bestIndex];
			// update best index 
			if (cache[i] > cache[bestIndex])
				bestIndex = i;
		}
		// answer will be in the top most calculated value
		return cache[0];
	}
};