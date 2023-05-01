#include "find_it/2022/qualification/kurung_mengurung.hpp"

void findit::kurungMengurung(const std::string_view& input) {
    //std::string input;
    //std::cin >> input;

    std::stack<char> kurungs;
    std::stack<char> temp;
    for (int i = input.size()-1; i >= 0; --i)
        kurungs.emplace(input[i]);
    
    int output[] = {1, 0, 0, 0, 0};
    temp.emplace(kurungs.top());
    kurungs.pop();
    while (!kurungs.empty()) {
        if (temp.top() == '{' && kurungs.top() == '}') {
            ++output[1]; temp.pop(); kurungs.pop(); }
        else if (temp.top() == '(' && kurungs.top() == ')') {
            ++output[2]; temp.pop(); kurungs.pop(); }
        else if (temp.top() == '[' && kurungs.top() == ']') {
            ++output[3]; temp.pop(); kurungs.pop(); }
        else if (temp.top() == '<' && kurungs.top() == '>') {
            ++output[4]; temp.pop(); kurungs.pop(); }

        if (!kurungs.empty()) {
            temp.emplace(kurungs.top()); kurungs.pop(); }
    }

    if (!temp.empty())
        std::fill(output, output+5, 0);

    for (auto& i : output) std::cout << i << "\n";
}


void findit::kurungMengurung2(const std::string_view& input) {
    //std::string input;
    //std::cin >> input;

    std::stack<char> brackets;
    int output[] = { 1, 0, 0, 0, 0 };
    for (char c : input) {
        switch (c) {
            case '{':
            case '(':
            case '[':
            case '<':
                brackets.push(c);
                break;
            case '}':
                if (!brackets.empty() && brackets.top() == '{') {
                    ++output[1];
                    brackets.pop();
                }
                break;
            case ')':
                if (!brackets.empty() && brackets.top() == '(') {
                    ++output[2];
                    brackets.pop();
                }
                break;
            case ']':
                if (!brackets.empty() && brackets.top() == '[') {
                    ++output[3];
                    brackets.pop();
                }
                break;
            case '>':
                if (!brackets.empty() && brackets.top() == '<') {
                    ++output[4];
                    brackets.pop();
                }
                break;
        }
    }

    if (!brackets.empty()) std::fill(output, output+5, 0);

    for (auto i : output) std::cout << i << "\n";
}

