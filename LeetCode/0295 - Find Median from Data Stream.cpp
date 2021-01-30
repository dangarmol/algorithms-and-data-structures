class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> data;
    size_t size;
    
    MedianFinder() {
        size = 0;
    }
    
    int findPos(const int &target) {
        
        int start = 0;
        int end = size - 1;
        
        while (start <= end) {
            int mid = (start + end) / 2;
            if (data[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return start;
    }
    
    void addNum(const int &num) {
        data.insert(data.begin() + findPos(num), num);
        ++size;
    }
    
    double findMedian() {
        if (size == 1) return data[0];
        else {
            return size % 2 == 0 ?
                (double) (data[size / 2] + data[(size / 2) - 1]) / 2 :
                data[size / 2];
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */