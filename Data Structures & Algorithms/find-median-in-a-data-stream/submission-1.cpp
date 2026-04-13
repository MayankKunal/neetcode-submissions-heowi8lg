class MedianFinder {
public:
  priority_queue<double>pq1;
  priority_queue<double,vector<double>,greater<double>>pq2;
    MedianFinder() {
    }
    
    void addNum(int num) {
        pq1.push(num);
       
         if(!pq2.empty() && pq1.top()>pq2.top())
        {
             pq2.push(pq1.top());
            pq1.pop();
        }
         if(pq1.size()>1+pq2.size())
        {
            pq2.push(pq1.top());
            pq1.pop();
        }
        if(pq2.size()>pq1.size())
        {
            pq1.push(pq2.top());
            pq2.pop();
        }
    }
    
    double findMedian() {
        int n=pq1.size();
        int m=pq2.size();
        if((m+n)%2==0)
        {
            return (pq1.top()+pq2.top())/2.0;
        }
        else
        {
            if(n>m) return pq1.top();
        }
        return pq2.top();
    }
};
