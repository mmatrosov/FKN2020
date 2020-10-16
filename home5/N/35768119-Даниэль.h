#include <optional>

#include "classifiers.h"

class CombinedClassifier {
    FastClassifier fastClass;
    std::optional<MainClassifier> mainClass = std::nullopt;
    const std::string stringForMain;

public:
    CombinedClassifier(const std::string& sfast, const std::string& smain)
        : fastClass(sfast), stringForMain(smain) {
    }

    double classify(const std::string& s) {
        try {
            return fastClass.classify(s);
        } catch (TooHardObjectException) {
            if (!mainClass.has_value()) {
                mainClass = std::optional<MainClassifier>(stringForMain);
            }
            return mainClass->classify(s);
        }
    }
};
