#include <iostream>
#include <string>
#include <emscripten/bind.h>

 void sayHello() {
    std::cout << "Hello from WASM function sayHello()\n";
}
void sayHello2(std::string name) {
    std::cout << "Hello from WASM to " << name << "\n";
}

int main(int, char**){
    std::cout << "Hello, from c_sample!\n";
}

EMSCRIPTEN_BINDINGS(my_module) {
    emscripten::function("sayHello", &sayHello);
    // emscripten::function("sayHello2", &sayHello2, allow_raw_pointers());
    emscripten::function("sayHello2", &sayHello2);
}
