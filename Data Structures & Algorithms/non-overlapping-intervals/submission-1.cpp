class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int prevEnd=intervals[0][1];
        int count=0;
        for(int i=1;i<n;i++)
        {
            int start=intervals[i][0];
            int end=intervals[i][1];
            if(prevEnd<=start)
            {
                prevEnd=end;
            }
            else
            {
                count++;
                prevEnd=min(prevEnd,end);
            }

        }
        return count;
    }
};
