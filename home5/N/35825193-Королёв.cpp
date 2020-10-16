#include "classifiers.h"
#include <memory>

class CombinedClassifier {
private:
    std::string data1, data2;
    std::unique_ptr <FastClassifier> fc;
    std::unique_ptr <MainClassifier> mc;
    bool WasCreatedmc;

public:
    CombinedClassifier(const std::string& s1, const std::string& s2) : data1(s1), data2(s2) {
        fc.reset(new FastClassifier(data1));
        WasCreatedmc = 0;
    }

    double classify(const std::string& s) {
        try {
            return fc->classify(s);
        } catch (TooHardObjectException) {
            if (!WasCreatedmc) {
                mc.reset(new MainClassifier(data2));
                WasCreatedmc = 1;
            }
            return mc->classify(s);
        }
    }

    ~CombinedClassifier() {
        fc.reset();
        mc.reset();
    }
};