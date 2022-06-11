class RandomizedCollection {
public:
    vector<int> v;
        unordered_map<int,vector<int>> m;
    int i;
    RandomizedCollection() {
       i=0; 
    }
    
    bool insert(int val) {
        if(m[val].size()==0){
        v.push_back(val);
           m[val].push_back(i);
          i++;
           return true;
       }
        else{ 
            v.push_back(val);
           m[val].push_back(i);
          i++;
        
            return false;
        }
    }
    
    bool remove(int val) {
         if(m[val].size()!=0){
           int siz=v.size();
         if(m[val].back()!=siz-1)   
         {v[m[val].back()]=v[siz-1];
             m[v[siz-1]].pop_back();
            m[v[siz-1]].push_back(m[val].back());
          sort(m[v[siz-1]].begin(),m[v[siz-1]].end());
         }
            v.pop_back(); m[val].pop_back();
            i--;
           
        
          
          
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

