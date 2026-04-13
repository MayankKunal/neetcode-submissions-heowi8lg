class MedianFinder {
public:
  vector<double>arr;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        arr.push_back(num);
    }
    
    double findMedian() {
        
        sort(arr.begin(),arr.end());
        int n=arr.size();
        if(n%2==0)
        {
            return (arr[n/2]+arr[(n-1)/2])/2.0;
        }
        else
        {
            return arr[n/2];
        }
    }
};
