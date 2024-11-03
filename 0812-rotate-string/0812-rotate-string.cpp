class Solution {
public:
    bool rotateString(string str1, string goal) {
        if(str1.length() != goal.length()) return false;

        string antiClockString = str1;

        int i = 1;
        while(i <= str1.size()){
            i++;
            char temp = antiClockString[0];
            for(int k=0; k<antiClockString.length()-1; k++){
                antiClockString[k] = antiClockString[k+1];
            }
            antiClockString[antiClockString.length()-1] = temp;

            bool antiClockFlag = 0;
            for(int k=0; k<goal.size(); k++){
                if(goal[k] != antiClockString[k]) {
                    antiClockFlag = 1; 
                    break;
                }
            }

            if(!antiClockFlag) return true;
        }
        return false;
    }
};