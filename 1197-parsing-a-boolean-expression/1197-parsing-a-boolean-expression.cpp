class Solution {
public:
    bool andd(string exp){
        int n = exp.length(), j=0;
        string subexp;
        int active = 0;
        while(j<n){
            if(active == 0 && exp[j]==','){
                if(!parseBoolExpr(subexp)) return false;
                subexp = "";
                j++;
                continue;
            }
            if(exp[j]=='(') active++;
            if(exp[j]==')') active--;
            subexp += exp[j++];
        }
        if(!parseBoolExpr(subexp)) return false;
        return true;
    }

    bool orr(string exp){
        int n = exp.length(), j=0;
        string subexp;
        int active = 0;
        while(j<n){
            if(active==0 && exp[j]==','){
                if(parseBoolExpr(subexp)) return true;
                subexp = "";
                j++;
                continue;
            }
            if(exp[j]=='(') active++;
            if(exp[j]==')') active--;
            subexp += exp[j++];
        }
        if(parseBoolExpr(subexp)) return true;
        return false;
    }

    bool parseBoolExpr(string exp) {
        int n = exp.length();
        if(n==1) return (exp[0]=='t');
        if(exp[0] == '!') return !parseBoolExpr(exp.substr(2, n-3));
        if(exp[0] == '&') return andd(exp.substr(2, n-3));
        if(exp[0] == '|') return orr(exp.substr(2, n-3));
        return false;
    }
};