#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void paste(std::vector<std::vector<std::string>> &files) {
    static int curString = 0;
    for (int i = 0; i < files.size(); i++) {
        if (files[i].size() > curString)
            std::cout << files[i][curString];
        std::cout << '\t';
    }
    std::cout << '\n';
    ++curString;
}

int main() {
    int M;
    std::cin >> M;
    std::vector<std::vector<std::string>> files(M);
    size_t maxCnt = 0;
    for (int i = 0; i < M; i++) {
        size_t N;
        std::cin >> N;
        files[i].resize(N);
        for (size_t j = 0; j < N; j++)
            std::cin >> files[i][j];
        maxCnt = std::max(maxCnt, N);
    }
    for (int i = 0; i < maxCnt; i++)
        paste(files);
    return 0;
}