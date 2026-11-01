class Solution {
private:
    static constexpr string MAPPING[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        vector<string> ans;
        string path;
        auto dfs = [&](this auto&& dfs, int i) -> void {
            if (i == n) {
                ans.push_back(path);
                return;
            }
            for (int j = 0; j < MAPPING[digits[i] - '0'].size(); j++) {
                path.push_back(MAPPING[digits[i] - '0'][j]);
                dfs(i + 1);
                path.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};