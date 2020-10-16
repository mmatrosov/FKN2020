#include <memory>

#include "classifiers.h"

class CombinedClassifier {
    std::unique_ptr<MainClassifier> heavy;
    FastClassifier fast;
    std::string heavyInit;

public:
    explicit CombinedClassifier(const std::string& fastInit, const std::string& heavyInit)
        : fast(fastInit), heavyInit(heavyInit) {
    }

    double classify(const std::string& s) {
        try {
            return fast.classify(s);
        } catch (const TooHardObjectException&) {
            if (!heavy)
                heavy = std::make_unique<MainClassifier>(heavyInit);
            return heavy->classify(s);
        }
    }
};
