#include <iostream>
#include <stack>
#include <list>
#include <vector>
#include <cstdlib>

template <class T = int, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
    typedef typename Container::iterator                     iterator;
    typedef typename Container::reverse_iterator             reverse_iterator;
    typedef typename Container::const_iterator               const_iterator;
    typedef typename Container::const_reverse_iterator       const_reverse_iterator;

    MutantStack(void);
    ~MutantStack(void);
    MutantStack(const MutantStack<T, Container> &other);
    MutantStack &operator=(const MutantStack<T, Container> &other);

    iterator begin(void);
    iterator end(void);
    reverse_iterator rbegin(void);
    reverse_iterator rend(void);

    const_iterator begin(void) const;
    const_iterator end(void) const;
    const_reverse_iterator rbegin(void) const;
    const_reverse_iterator rend(void) const;
};

#include "MutantStack.tpp"
