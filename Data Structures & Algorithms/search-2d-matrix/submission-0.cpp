class Solution {
    bool search(vector<int>&arr,int target,int l,int r)
    {
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(arr[mid]==target) return true;
            else if(arr[mid]<target) l=mid+1;
            else r=mid-1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int l=0,r=n-1;
        while(l<=r)
        {
              int mid=(l+r)/2;
              if(matrix[mid][m-1]>=target)
              {
                if(search(matrix[mid],target,0,m-1)) return true;
                r=mid-1;
              }
              else
              {
                    l=mid+1;
              }
        }
        return false;
    }
};
