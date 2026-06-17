class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> hashMap;

        for (string word : wordList) {
            for (int i = 0; i < word.size(); i++) {
                string pattern = word; pattern[i] = '*';
                
                if (hashMap.find(pattern) == hashMap.end()) hashMap[pattern] = {word};
                else hashMap[pattern].push_back(word);
            }
        }

        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);

        int count = 1;
        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                string currWord = q.front(); q.pop();
                if (currWord == endWord) return count;

                for (int j = 0; j < currWord.size(); j++) {
                    string pattern = currWord; pattern[j] = '*';

                    if (visited.find(pattern) != visited.end()) continue;
                    for (string word : hashMap[pattern]) {
                        cout << word << endl;
                        q.push(word);
                    }
                    visited.insert(pattern);
                    cout << endl;
                } 
            }
            count++;
        }

        return 0;
    }
};
