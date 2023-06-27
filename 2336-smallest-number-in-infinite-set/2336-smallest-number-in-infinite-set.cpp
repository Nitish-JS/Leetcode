// optimised approach
class SmallestInfiniteSet {
public:
    set<int> st;
    int cur;
    SmallestInfiniteSet() {
        cur=1;
    }
    
    int popSmallest() {
        if(st.size()>0){
            int ans=*(st.begin());
            st.erase(ans);
            return ans;
        }
        else{
            cur+=1;
            return cur-1;
        }
    }
    
    void addBack(int num) {
        if(cur>num)
            st.insert(num);
    }
};

// class SmallestInfiniteSet {
// public:
//     set<int> st;
//     SmallestInfiniteSet() {
//         for(int i=1;i<=1000;i++){
//             st.insert(i);
//         }
//     }
    
//     int popSmallest() {
//         int ans=*(st.begin());
//         st.erase(ans);
//         return ans;
//     }
    
//     void addBack(int num) {
//        st.insert(num);
//     }
// };

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */