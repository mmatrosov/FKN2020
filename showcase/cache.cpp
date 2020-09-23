#include <chrono>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

auto makeMatrix(int n) {
  auto m = std::vector<std::vector<int>>(n);
  for (int i = 0; i < n; ++i) {
    m[i].resize(n);
    for (int j = 0; j < n; ++j) {
      m[i][j] = i + j;
    };
  }
  return m;
}

int calcAverageRowFirst(const std::vector<std::vector<int>>& m) {
  int64_t sum = 0;
  int count = 0;
  const int n = m.size();
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      sum += m[i][j];
      ++count;
    }
  return sum / count;
}

int calcAverageColFirst(const std::vector<std::vector<int>>& m) {
  int64_t sum = 0;
  int count = 0;
  const int n = m.size();
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      sum += m[j][i];
      ++count;
    }
  return sum / count;
}

template <class F>
void runTimed(std::string_view message, F f) {
  using namespace std::chrono;
  static constexpr int trials = 1000;

  std::cout << message;
  auto start = steady_clock::now();
  for (int i = 0; i < trials; ++i) {
    volatile auto result = f();
  }
  std::cout << "Done in "
            << duration_cast<milliseconds>(steady_clock::now() - start).count()
            << "ms\n";
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << "Input the dimension of the matrix";
    return 0;
  }

  int n = std::stoi(argv[1]);

  auto m = makeMatrix(n);

  runTimed("Row-first: ", [&] { return calcAverageRowFirst(m); });
  runTimed("Col-first: ", [&] { return calcAverageColFirst(m); });
  runTimed("Row-first: ", [&] { return calcAverageRowFirst(m); });
  runTimed("Col-first: ", [&] { return calcAverageColFirst(m); });
  runTimed("Row-first: ", [&] { return calcAverageRowFirst(m); });
  runTimed("Col-first: ", [&] { return calcAverageColFirst(m); });
}
