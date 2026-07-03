class Solution {
public:
    bool isFreqSame(int freq1[], int freq2[]) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            int idx = s1[i] - 'a'; // a->0  b->1
            freq[idx]++;
        }

        int windowsize = s1.size();
        for (int i = 0; i < s2.size(); i++) {
            int windowIdx = 0, idx = i;
            int windowfreq[26] = {0};

            while (windowIdx < windowsize && idx < s2.length()) {
                windowfreq[s2[idx] - 'a']++;
                windowIdx++;
                idx++;
            }

            if (isFreqSame(freq, windowfreq)) {
                return true;
            }
        }
        return false;
    }
};