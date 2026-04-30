class Solution {
public:

    string encode(vector<string>& strs) {
        string toReturn = "";
        for (string s : strs) {
            int currLength = s.size();
            toReturn += to_string(currLength) + "_";
            toReturn += s;
        }

        return toReturn;
    }

    vector<string> decode(string s) {
        int i = 0;

        vector<string> toReturn;
        while (i < s.size()) {
            int length = 0;
            int numOfDigits = 0;
            for (int index = i; index < s.size(); index++) {
                if (s[index] == '_') break;
                length = length * 10 + (s[index] - '0');
                numOfDigits++;
            }
            string subString = s.substr(i + numOfDigits + 1, length);
            toReturn.push_back(subString);
            i += length + numOfDigits + 1;
        }

        return toReturn;
    }
};
