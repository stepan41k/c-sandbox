#include <iostream>
#include <thread>

void print_message(std::string text) {
  std::cout << "Thread says: " << text << std::endl;
}

int main() {
  std::thread t1(print_message, "Hello from parallel world\n");

  std::cout << "Main thread is working" << std::endl;

  t1.join();

  return 0;
}