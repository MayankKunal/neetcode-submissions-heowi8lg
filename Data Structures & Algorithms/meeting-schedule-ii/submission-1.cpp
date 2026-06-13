/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        
        vector<int>s,e;
        int n=intervals.size();
        for(int i=0;i<n;i++)
        {
           s.push_back(intervals[i].start);
           e.push_back(intervals[i].end);
        }
        sort(s.begin(),s.end());
        sort(e.begin(),e.end());

        int i=0,j=0,temp=0,ans=0;
        while(i<n)
        {
            if(s[i]<e[j])
            {
                i++;
                temp++;
            }
            else
            {
                j++;
                temp--;
            }
            ans=max(ans,temp);
        }
        return ans;
    }
};
