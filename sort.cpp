#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        // Frequency count of each character
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Count how many characters have an odd frequency
        vector<char> oddChars;
        for (auto& entry : freq) {
            if (entry.second % 2 != 0) {
                oddChars.push_back(entry.first);
            }
        }

        if (oddChars.size() > 1) {
            // More than one character with an odd frequency, the string cannot form a palindrome
            cout << "0\n\n"; // We choose the empty subsequence
        } else {
            // The string can potentially form a palindrome
            // We need to remove a subsequence to make it impossible to rearrange into a palindrome
            // Remove the lexicographically smallest subsequence to break the palindrome structure
            
            string t = "";

            // Check if we can remove one character to break symmetry
            for (char c : s) {
                if (t.empty() || t.back() != c) {
                    t += c;
                    break;
                }
            }

            cout << t.size() << "\n";
            cout << t << "\n";
        }
    }

    return 0;
}
