#include <iostream>
#include <string>
#include <vector>
#include <set>

std::string common_prefix(const std::vector<std::string>& words) {
    if (words.size() == 0)
        return "";
    std::string prefix;
    for (int char_id = 0;; ++char_id) {
        std::set<char> chars;
        for (const std::string& word : words) {
            if (char_id >= word.length())
                return prefix;
            chars.insert(word[char_id]);
        }
        if (chars.size() > 1)
            return prefix;
        prefix += *chars.begin();

        /*if (char_id >= words[0].length())
            return prefix;
        for (int i = 1; i < words.size(); ++i) {
            if (char_id >= words[i].length() || words[i][char_id] != words[0][char_id])
                return prefix;
        }
        prefix += words[0][char_id];*/
    }
}

