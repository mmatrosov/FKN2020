#include <exception>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include "classifiers.h"

class CombinedClassifier {
private:
    FastClassifier* fc;
    std::string mainstring;
    MainClassifier* mc;
    bool used_mc = false;

public:
    CombinedClassifier(const std::string& s1, const std::string& s2): mainstring(s2) {
        fc = new FastClassifier(s1);
    }

    double classify(const string& s) {
        double ans;
        try {
            ans = (*fc).classify(s);
        } catch (TooHardObjectException) {
            if (!used_mc) {
                mc = new MainClassifier(mainstring);
                used_mc = true;
            }
            ans = (*mc).classify(s);
        }
        return ans;
    }

    ~CombinedClassifier() {
        delete fc;
        if (used_mc)
            delete mc;
    }
};