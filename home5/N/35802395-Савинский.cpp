#include <memory>
#include <optional>
#include <string>
#include "classifiers.h"

class CombinedClassifier {
   public:
    std::string main_string;
    std::optional<FastClassifier> fc;
    std::optional<MainClassifier> mc;

    CombinedClassifier(std::string fast, std::string main) : main_string(main) {
        fc.emplace(fast);
    }

    double classify(const string& s) {
        try {
            return fc->classify(s);
        } catch (const TooHardObjectException&) {
            if (mc == std::nullopt) {
                mc.emplace(main_string);
            }
            return mc->classify(s);
        }
    }
};
