class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>>pq;
           for(auto point:points)
           {
             double dis=sqrt((double)(pow(point[0],2)+pow(point[1],2)));

             pq.push({dis,{point[0],point[1]}});

           }
         vector<vector<int>>ans;
           while(k--)
           {
            auto it=pq.top();
            pq.pop();
            double d=it.first;
            int x=it.second.first;
            int y=it.second.second;
            ans.push_back({x,y});
           }
           return ans;
    }
};
