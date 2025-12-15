#include "leap.h"

namespace leap {

bool is_leap_year(int year){
    return (year % 400 == 0) || (year % 100 && !(year % 4));
}

}  // namespace leap