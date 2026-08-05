class Solution {
private:
    map<char, string> m{{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int n = digits.size();
        auto dfs = [&](this auto&& dfs, string str, int i) {
            if (i == n) {
                ans.push_back(str);
                return;
            }
            for (int j = 0; j < m[digits[i]].size(); j++) {
                str += m[digits[i]][j];
                dfs(str, i + 1);
                str.pop_back();
            }
        };
        dfs("", 0);
        return ans;
    }
};