class SpecialQueue {

  public:
    queue<int> q;
    deque<int> mini, maxi;
    void enqueue(int x) {
        // Insert element into the queue
        q.push(x);
        while(!mini.empty() && mini.back() > x)
            mini.pop_back();
        mini.push_back(x);
        while(!maxi.empty() && maxi.back() < x)
            maxi.pop_back();
        maxi.push_back(x);
    }

    void dequeue() {
        // Remove element from the queue
        if(q.empty())
            return;
        int val = q.front();
        q.pop();
        if(!mini.empty() && mini.front() == val)
            mini.pop_front();
        if(!maxi.empty() && maxi.front() == val)
            maxi.pop_front();
    }

    int getFront() {
        // Get front element
        return q.front();
    }

    int getMin() {
        // Get minimum element
        return mini.front();
    }

    int getMax() {
        // Get maximum element
        return maxi.front();
    }
};