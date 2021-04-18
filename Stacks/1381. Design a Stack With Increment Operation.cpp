class CustomStack {
public:
  
    vector<int> st_;
    //we think about vector as we need a way to be able to access
    //the bottom k elements
    int size_;
    
    CustomStack(int maxSize) {
        size_ = maxSize;
    }
    // O(1)
    void push(int x) {
        //if stack size is less tham the max size then
        //push into stack otherwise do nothing
        
        if(st_.size() == size_)return;
        else st_.push_back(x);
    }
    // O(1)
    int pop() {
        if(st_.empty())return -1;
        else {
            int last = st_.back();
            st_.pop_back();
            return last;
        }
    }
    // O(k)
    void increment(int k, int val) {
        int n = st_.size();
        
        for(int i=0; i<min(k, n); i++){
            st_[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
