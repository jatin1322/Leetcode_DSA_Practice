class RandomizedSet {
public:
   vector<int> v;
        unordered_map<int,int> m;
    int i;
    RandomizedSet() {
      
         i=0;
    }
    
    bool insert(int val) {
       if(m[val]==0){
        v.push_back(val);
           m[val]=i+1;
          i++;
           return true;
       }
        else{
            return false;
        }
        
    }
    
    bool remove(int val) {
        if(m[val]!=0){
           int siz=v.size();
            v[m[val]-1]=v[siz-1];
            m[v[siz-1]]=m[val];
            v.pop_back();
            i--;
            m.erase(val);
        
          
          
           return true;
       }
        else{
            return false;
        }
    }
    
    int getRandom() {
        int a=rand()%v.size();
        return v[a];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */