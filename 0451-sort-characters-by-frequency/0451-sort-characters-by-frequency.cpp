class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char,int>> freq(62, {'#',0});

        for(char ch : s) {
            if(ch >= 'A' && ch <= 'Z') {
                int idx = (ch - 'A') + 26;
                freq[idx].first = ch;
                freq[idx].second++;
            } else if(ch >= 'a' && ch <= 'z') {
                freq[ch - 'a'].first = ch;
                freq[ch - 'a'].second++;
            } else {
                int idx = (ch - '0') + 52;
                freq[idx].first = ch;
                freq[idx].second++;
            }
        }

        sort(freq.begin(), freq.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        int idx = 0;
        for(auto[ch, fr] : freq) {
            while(fr > 0) {
                s[idx++] = ch;
                fr--;
            }
        }

        return s;
    }
};