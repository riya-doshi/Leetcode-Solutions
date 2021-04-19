// Data Structure Design question

class FreqStack {
public:
    int maxfreq;
    
//     we create a frequency map
//         wherein the index will be the frequency
//         and value will be a stack 
        
    // ^ here key is freq and val is stack of elements 
    
    
//     We maintain a frequency counter for mapping
    // ^ here key is element and value is freq (duh :P)
        
    unordered_map<int, stack<int>> map;
    unordered_map<int, int> freq;
    
    FreqStack() {
        maxfreq=0;
    }
    
    void push(int val) {
        freq[val]++;
        
        map[freq[val]].push(val);
        maxfreq = max(maxfreq, freq[val]);
    }
    
    int pop() {
        int temp = map[maxfreq].top(); 
        //^ upper most element of stack paied to max freq of that time 
        
        freq[temp]--;
        map[maxfreq].pop();
        
        if(map[maxfreq].empty()){
            maxfreq--;
        }
        return temp;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
