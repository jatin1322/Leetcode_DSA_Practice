class MyStack {
public:
    queue<int> q1,q2;
    int topo;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        topo=x;
    }
    
    int pop() {
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        int res=q1.front();
        q1.pop();
        while(q2.size()>0){
            topo=q2.front();
            q1.push(q2.front());
            q2.pop();
        }
        
        return res;
    }
    
    int top() {
        return topo;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
// using push o(n)
  queue<int> q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        if(q1.empty()){
            q1.push(x);
        }
        else{
            q2.push(x);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }
        
    }
    
    int pop() {
        int temp=q1.front();
        q1.pop();
        return temp;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
       return q1.empty(); 
    }
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */