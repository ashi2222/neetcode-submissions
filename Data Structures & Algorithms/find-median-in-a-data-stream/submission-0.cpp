class MedianFinder {
public:
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxheap.push(num);

        minheap.push(maxheap.top());
        maxheap.pop();

        if(minheap.size() > maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        int size = minheap.size() + maxheap.size();
        if(size%2 == 0){
            return (minheap.top() + maxheap.top())/2.0;
        }
        return (double)maxheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */