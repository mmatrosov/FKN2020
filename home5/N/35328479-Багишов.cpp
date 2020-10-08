#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "classifiers.h"

class CombinedClassifier {
    std::optional<MainClassifier> mMain;
    FastClassifier mFast;
    std::string mMainSeed;

public:
    CombinedClassifier(std::string const& fast_seed, std::string const& main_seed)
        : mFast(fast_seed), mMainSeed(main_seed) {
    }

    double classify(std::string const& object) {
        double score;
        try {
            score = mFast.classify(object);
        } catch (TooHardObjectException const&) {
            if (!mMain.has_value()) {
                mMain = MainClassifier(std::move(mMainSeed));
            }
            score = mMain->classify(object);
        }
        return score;
    }
};