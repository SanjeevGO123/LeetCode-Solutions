class Solution {
public:
    string convert(std::string s, int numRows) {
    int col = 0;
    int l = s.length();
    while (l > 0) {
        l -= numRows;
        col++;
        for (int i = 0; i < numRows - 2; i++) {
            if (l > 0) {
                l--;
                col++;
            }
        }
    }

    std::vector<std::vector<char>> m(numRows, std::vector<char>(col, ' '));

    l = s.length();
    int c = 0;
    int p = 0;
    while (l > 0) {
        for (int i = 0; i < numRows; i++) {
            if (l > 0) {
                l--;
                m[i][c] = s[p++];
            }
        }
        c++;
        for (int i = numRows - 2; i > 0; i--) {
            if (l > 0) {
                l--;
                m[i][c++] = s[p++];
            }
        }
    }

    std::string f = "";
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < col; j++) {
            if (m[i][j] != ' ') {
                f += m[i][j];
            }
        }
    }
    return f;
}
};