class Solution {
public:
    string convertDateToBinary(string date) {
        
        string year = date.substr(0, 4);
        string month = date.substr(5, 2);
        string day = date.substr(8, 2);

        int y = stoi(year);
        int m = stoi(month);
        int d = stoi(day);

        string yb = bitset<16>(y).to_string(); 
        string mb = bitset<8>(m).to_string(); 
        string db = bitset<8>(d).to_string();  

        yb = yb.substr(yb.find('1'));
        mb = mb.substr(mb.find('1'));
        db = db.substr(db.find('1'));

        return yb + "-" + mb + "-" + db;
    }
};