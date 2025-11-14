class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;

        for (int i = 0; i < s1.length(); i++) {
            freq1[s1[i]]++;
            freq2[s2[i]]++;
        }

        if (freq1 == freq2) return true;

        int left = 0;
        for (int right = s1.length(); right < s2.length(); right++) {
            freq2[s2[right]]++;
            freq2[s2[left]]--;

            if (freq2[s2[left]] == 0) {
                freq2.erase(s2[left]);
            }

            left++;

            if (freq1 == freq2) return true;
        }

        return false;
    }
};

// [ Time taken: 1 hr 0 m 9 s ]

// TC - O(n  + m)
// SC - O(1)

