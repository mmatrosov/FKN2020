#include <deque>
#include <iostream>
#include <vector>

struct Minimum {
    int value, position;
};

struct Window {
    std::deque<Minimum> mins;

    void add_number(const Minimum& number) {
        while (!mins.empty() && number.value <= mins.back().value)
            mins.pop_back();
        mins.push_back(number);
    }

    void remove_number(int position) {
        if (mins.front().position == position)
            mins.pop_front();
    }

    int get_min() {
        return mins[0].value;
    }
};

int main() {
    int elems, windowLen;
    std::cin >> elems >> windowLen;
    std::vector<int> numbers(elems);
    Window window;
    for (int i = 0; i < elems; ++i) {
        std::cin >> numbers[i];
        if (i < windowLen - 1)
            window.add_number({numbers[i], i});
    }
    for (int i = windowLen - 1; i < elems; ++i) {
        window.add_number({numbers[i], i});
        std::cout << window.get_min() << "\n";
        window.remove_number(i - windowLen + 1);
    }
}
