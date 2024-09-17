class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>>pq;
    vector<int> v;
    SmallestInfiniteSet() {
        v.push_back(1);
        for(int i=1;i<=1000;i++){
            pq.push(i);
            v.push_back(1);
        }
    }
    
    int popSmallest() {
        int x=pq.top();
        pq.pop();
        v[x]--;
        return x;
    }
    
    void addBack(int num) {
        if(v[num]) return;
        v[num]++;
        pq.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */