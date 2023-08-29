#include <iostream>
#include <vector>

class Spacecraft {
public:
    int x, y, z;
    std::string direction;

    Spacecraft(int initialX, int initialY, int initialZ, std::string initialDirection) : x(initialX), y(initialY), z(initialZ), direction(initialDirection) {}
};

void move_forward(Spacecraft& spacecraft) {
    if (spacecraft.direction == "N") spacecraft.y++;
    else if (spacecraft.direction == "S") spacecraft.y--;
    else if (spacecraft.direction == "E") spacecraft.x++;
    else if (spacecraft.direction == "W") spacecraft.x--;
   
}

void move_backward(Spacecraft& spacecraft) {
    if (spacecraft.direction == "N") spacecraft.y--;
    else if (spacecraft.direction == "S") spacecraft.y++;
    else if (spacecraft.direction == "E") spacecraft.x--;
    else if (spacecraft.direction == "W") spacecraft.x++;
  
}

void execute_commands(Spacecraft& spacecraft, const std::vector<char>& commands) {
    for (char command : commands) {
        switch (command) {
            case 'f':
                move_forward(spacecraft);
                break;
            case 'b':
                move_backward(spacecraft);
                break;
            
            default:
                break;
        }
    }
}

int main() {
    Spacecraft spacecraft(0, 0, 0, "N");
    std::vector<char> commands = {'f', 'r', 'u', 'b', 'l'};
    execute_commands(spacecraft, commands);
    std::cout << "Final Position: (" << spacecraft.x << ", " << spacecraft.y << ", " << spacecraft.z << ")\n";
    std::cout << "Final Direction: " << spacecraft.direction << "\n";
    return 0;
}
