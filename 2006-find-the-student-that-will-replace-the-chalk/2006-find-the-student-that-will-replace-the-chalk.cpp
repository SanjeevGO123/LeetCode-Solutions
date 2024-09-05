class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        long long sum=accumulate(chalk.begin(),chalk.end(),0LL);
        int i=0;
        k%=sum;
        while(k>0){
            if(k<chalk[i]) return i;
            k-=chalk[i];
            i++;
        }
        return i;
    }
};