#include <iostream>

namespace console {
    void write_line() {
        std::cout << std::endl;
    }
    
    template <class T>
    void write_line(T value) {
        std::cout << value << std::endl;
    }
}