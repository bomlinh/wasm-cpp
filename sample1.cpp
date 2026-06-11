#include <iostream>

extern "C" {
    void sayHello() {
        std::cout << "Hello from WASM function sayHello()\n";
    }
    void sayHello2(const char* name) {
        std::cout << "Hello from WASM to " << name << "\n";
    }
}

int main(int, char**){
    std::cout << "Hello, from c_sample!\n";
}
