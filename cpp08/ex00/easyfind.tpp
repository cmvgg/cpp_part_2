#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include <algorithm>
#include <stdexcept>
#include <iterator>

template <typename T>
void easyfind(const T &container, const int &value) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it != container.end()) {
        std::cout << "Value found in container: " << *it << std::endl;
    } else {
        throw std::out_of_range("Value not found in container");
    }
}

#endif
