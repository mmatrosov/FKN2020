#include "student.h"
#include <iostream>

bool compare(const Student& one, const Student& two) {
    return one.less(two);
}
