#include "reverse_string.h"

namespace reverse_string {
    std::string reverse_string(const std::string str){
        std::string rev(str.crbegin(), str.crend());
        return rev;
    }
}  // namespace reverse_string