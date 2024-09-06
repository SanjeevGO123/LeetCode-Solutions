class Solution {
public:
    int removeElement(vector<int>& vec, int val) {
        int n=vec.size();
        vec.erase(remove(vec.begin(), vec.end(), val), vec.end());
        return vec.size();
    }
};