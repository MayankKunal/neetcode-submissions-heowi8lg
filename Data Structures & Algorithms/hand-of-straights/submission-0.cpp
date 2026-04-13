class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        map<int,int>mp;
        for(int card:hand)
        {
            mp[card]++;
        }
        int n=hand.size();
        // if(n%groupSize!=0) return false;

        while(!mp.empty())
        {
            int curr=mp.begin()->first;
            for(int i=0;i<groupSize;i++)
            {
                if(mp[curr+i]>0)
                {
                    mp[curr+i]--;
                    if(mp[curr+i]==0) mp.erase(curr+i);
                }
                else
                 return false;
            }
        }
        return true;
    }
};
