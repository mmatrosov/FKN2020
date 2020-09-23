#include "student.h"
#include <iostream>

bool compare(Student &one, Student &two) {
    return one.rating > two.rating;
}