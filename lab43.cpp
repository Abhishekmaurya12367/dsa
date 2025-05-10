#include<bits/stdc++.h>
using namespace std;

#define MAX_CHAR 128

struct CharFreq {
    char ch;
    int freq;
};

bool compare(const CharFreq& a, const CharFreq& b) {
    if (a.freq == b.freq) {
        return a.ch < b.ch;
    }
    return a.freq > b.freq;
}

void frequencySort(char* s) {
    int len = strlen(s);
    int freq[MAX_CHAR] = {0};

    for (int i = 0; i < len; i++) {
        freq[(int)s[i]]++;
    }

    CharFreq charArray[MAX_CHAR];
    int count = 0;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] > 0) {
            charArray[count].ch = (char)i;
            charArray[count].freq = freq[i];
            count++;
        }
    }

    std::sort(charArray, charArray + count, compare);

    int index = 0;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < charArray[i].freq; j++) {
            s[index++] = charArray[i].ch;
        }
    }
    s[index] = '\0';
}

int main() {
    char s[100];
    std::cin >> s;

    frequencySort(s);
    std::cout  << s << std::endl;

    return 0;
}