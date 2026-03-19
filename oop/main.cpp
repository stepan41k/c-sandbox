#include <iostream>

class Player {
private:
  std::string name;
  int health;

public:
  std::string getName() { return this->name; }

  void setName(std::string name) {this->name = name; }
};

int main() {
  Player newPlayer = Player{};
  newPlayer.setName("Igor");

  std::cout << newPlayer.getName() << std::endl;

  return 0;
}