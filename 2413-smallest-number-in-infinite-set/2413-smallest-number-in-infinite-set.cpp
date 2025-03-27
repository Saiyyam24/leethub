class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    set<int> exist;
    SmallestInfiniteSet() {
        for(int i=1;i<10001;i++)
        {
            pq.push(i);
            exist.insert(i);
        }
    }
    
    int popSmallest() {
        int val=pq.top();
        pq.pop();
        exist.erase(val);
        return val;
    }
    
    void addBack(int num) {
     if(exist.find(num)==exist.end())
     {
        pq.push(num);
        exist.insert(num);   
     }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */