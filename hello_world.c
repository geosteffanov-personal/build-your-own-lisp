#include <stdio.h>

void say_hello(int count) {
    while(count > 0) {
        puts("Hello, World!");
        count--;
    }
}

int main(int argc, char** argv) {
    say_hello(5);
    return 0;
}
