class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        int n=triplets.size();
        int trip1=0,trip2=0,trip3=0;
        for(int i=0;i<n;i++)
        {
            if(triplets[i][0]>target[0] || triplets[i][1]>target[1] || 
            triplets[i][2]>target[2]) continue;

            trip1=max(trip1,triplets[i][0]);
            trip2=max(trip2,triplets[i][1]);
            trip3=max(trip3,triplets[i][2]);
        }
        if(trip1==target[0] && trip2==target[1] && trip3==target[2]) return true;
        return false;
    }
};
