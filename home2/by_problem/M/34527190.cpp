#include <iostream>
#include "student.h"

bool compare(Student &one, Student &two) {
    return one.less(two);
}
