#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <limits>

class Span {
private:
    mutable std::vector<int> array;
    mutable unsigned int n;

public:
    Span(void);
    Span(unsigned int _n);
    ~Span(void);
    Span(const Span &other);
    Span &operator=(const Span &other);
    void addNumber(unsigned int o) const;
    void addNumber(const std::vector<int> &other) const;
    unsigned int shortestSpan(void) const;
    unsigned int longestSpan(void) const;
};
