#include <iostream>
#include <vector>

const int MAX_NUM = 100'001;

struct Node {
    Node* next;
    int number;
};

int main() {
    std::vector<int> was(MAX_NUM);
    std::vector<Node> list(MAX_NUM);
    int athletes;
    std::cin >> athletes;
    Node* root = nullptr;
    for (int i = 0; i < athletes; i++) {
        int curAthlete, prevAthlete;
        std::cin >> curAthlete >> prevAthlete;
        if (!was[prevAthlete]) {
            auto& ref = list[curAthlete];
            ref.number = curAthlete;
            ref.next = root;
            root = &ref;
            was[curAthlete] = 1;
        } else {
            auto& refPrev = list[prevAthlete];
            auto& refCur = list[curAthlete];
            refCur.next = refPrev.next;
            refPrev.next = &refCur;
            refCur.number = curAthlete;
            was[curAthlete] = 1;
        }
    }
    while (root != nullptr) {
        std::cout << root->number << "\n";
        root = root->next;
    }
}
