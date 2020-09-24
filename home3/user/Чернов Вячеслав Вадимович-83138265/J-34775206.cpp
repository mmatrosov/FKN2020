#include <algorithm>
#include <vector>

template <typename T>
void process(const std::vector<T>& data) {
    std::vector<T> filtered(data.size());

    filtered.erase(std::copy_if(
      data.begin(),
      data.end(),
      filtered.begin(),
      [](const T& x) { return x > 0; }),
    filtered.end());

    print_results(filtered.begin(), filtered.end());
}
