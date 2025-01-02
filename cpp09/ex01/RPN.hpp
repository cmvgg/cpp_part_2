#include <iostream>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <sstream>

class RPN
{
private:
    std::stack<int> list;

    bool isArithmetic(char const &c) const;
	bool aritmetics(char const &c) const;
    void parser(const std::string &input);
    void operate(const char &operando);

public:
    RPN(void);
    ~RPN(void);
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    void open(const std::string &input);
};
