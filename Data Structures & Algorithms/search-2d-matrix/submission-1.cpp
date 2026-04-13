class Solution {
bool help(vector<int>&nums,int target)
{
    int l=0,r=nums.size()-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(nums[mid]==target) return true;
        else if(nums[mid]<target) l=mid+1;
        else r=mid-1;
    }
    return false;
}
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        int m=matrix[0].size();

        int l=0,r=n-1;
        bool ans=false;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(matrix[mid][m-1]>=target && matrix[mid][0]<=target)
            {
                return help(matrix[mid],target);
            }
            else if(matrix[mid][0]<target)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};
