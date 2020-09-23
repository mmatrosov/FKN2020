#include <iostream>
#include <vector>

int main() {
    std::string temp;
    std::vector<int> count(26, 3);
    /*
    Before and after each iteration:
        count[x] == 3, if char x satisfies the condition;
        count[x] == 0, otherwise.
    */
    int wordCount = 0;
    while (std::cin >> temp) {
        for (char c : temp)
            count[c - 'a'] &= 1;
        /*
        It's easy to see that after performing this cycle only such x that count[x]==1 satisfy the condition.
        So we should replace count[x] by 3 for each x such that count[x]==1, and by 0 for all others.
        */
        for (int i = 0; i < 26; i++)
            count[i] = (count[i] == 1) * 3;
    }
    for (int i = 0; i < 26; i++)
        if (count[i] == 3)
            std::cout << static_cast<char>(i + 'a');
    return 0;
}