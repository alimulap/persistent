#include "find_it/2022/qualification/kurung_mengurung.hpp"
#include <ctime>

int main() {
    std::string input;
    std::cin >> input;
    long start = std::clock();
    findit::kurungMengurung(input);
    std::cout << "\n" << std::clock() - start << "\n\n";
    start = std::clock();
    findit::kurungMengurung2(input);
    std::cout << "\n" << std::clock() - start << "\n\n";
    return 0;
}
