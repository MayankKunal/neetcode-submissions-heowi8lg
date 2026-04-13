class Solution {
public:
    int maxArea(vector<int>& heights) {

     int n=heights.size();
     int l=0,r=n-1;
     int ans=0;
     while(l<r)
     {
         int h1=heights[l];
         int h2=heights[r];
          int curr=min(h1,h2)*(r-l);
         ans=max(ans,curr);
         if(h1<h2)
         {
            l++;
         }
         else
         r--;
     }   
     return ans;
    }
};
