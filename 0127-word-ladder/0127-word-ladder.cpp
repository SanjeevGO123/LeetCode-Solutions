class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& word) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> st(word.begin(),word.end());
        st.erase(beginWord);
        while(!q.empty()){
            string w=q.front().first;
            int len=q.front().second;
            q.pop();
            if(w==endWord) return len;
            for(int i=0;i<w.size();i++){
                char og=w[i];
                for(char c='a';c<='z';c++){
                    w[i]=c;
                    if(st.find(w)!=st.end()){
                        st.erase(w);
                        q.push({w,len+1});
                    }
                }
                w[i]=og;
            }
        }
        return 0;
    }
};