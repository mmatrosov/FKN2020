#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long dot_prod(const vector<long long> &v1, const vector<long long> &v2, size_t cop) {
    long long ans = 0;
    for (size_t i = 0; i < cop; ++i) {
        ans += (v1[i] * v2[i]);
    }
    return ans;
}

int main() {
    size_t wor_am, vec_cop;
    cin >> wor_am >> vec_cop;
    string word, first_word;
    vector<string> ans_words;
    vector<long long> vec(vec_cop), first_vec(vec_cop);
    long long max_dp = -10000000000;
    cin >> first_word;
    for (size_t i = 0; i < vec_cop; ++i) cin >> first_vec[i];
    for (size_t i = 0; i < wor_am - 1; ++i) {
        cin >> word;
        for (size_t j = 0; j < vec_cop; ++j) cin >> vec[j];
        if (dot_prod(vec, first_vec, vec_cop) > max_dp) {
            ans_words = {word};
            max_dp = dot_prod(vec, first_vec, vec_cop);
        } else if (dot_prod(vec, first_vec, vec_cop) == max_dp) {
            ans_words.push_back(word);
        }
    }
    for (auto w : ans_words) cout << w << '\n';
}