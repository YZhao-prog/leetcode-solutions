class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        auto decode = [&](this auto&& decode) -> string {
            string res;
            int k = 0;
            while (i < s.size()) {
                char c = s[i];
                i++;
                if (isalpha(c)) {
                    res += c;
                } else if (isdigit(c)) {
                    k = k * 10 + (c - '0');
                } else if (c == '[') {
                    auto t = decode();
                    while (k > 0) {
                        res += t;
                        --k;
                    }
                } else {
                    break;
                }
            }
            return res;
        };
        return decode();
    }
};