class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<double,double>>v;
        int n=position.size();
        for(int i=0;i<n;i++)
        {
             v.push_back({position[i],speed[i]});
        }
          sort(v.rbegin(),v.rend());
        //   stack<double>st;
          int fleet=0;
          double prevTime=0;
        for(int i=0;i<n;i++)
        {
            double time=((target-v[i].first)/v[i].second);
             if(time>prevTime)
             {
                fleet++;
                prevTime=time;
             }
        }
        return fleet;
    }
};
