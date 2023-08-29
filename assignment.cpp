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
    else if (spacecraft.direction == "Up") spacecraft.z++;
    else if (spacecraft.direction == "Down") spacecraft.z--;
}

void move_backward(Spacecraft& spacecraft) {
    if (spacecraft.direction == "N") spacecraft.y--;
    else if (spacecraft.direction == "S") spacecraft.y++;
    else if (spacecraft.direction == "E") spacecraft.x--;
    else if (spacecraft.direction == "W") spacecraft.x++;
    else if (spacecraft.direction == "Up") spacecraft.z--;
    else if (spacecraft.direction == "Down") spacecraft.z++;
}

void turn_left(Spacecraft& spacecraft) {
    std::vector<std::string> directions = {"N", "W", "S", "E", "Up", "Down"};
    int currentIndex = std::find(directions.begin(), directions.end(), spacecraft.direction) - directions.begin();
    int newIndex = (currentIndex + 1) % directions.size();
    spacecraft.direction = directions[newIndex];
}

void turn_right(Spacecraft& spacecraft) {
    std::vector<std::string> directions = {"N", "E", "S", "W", "Up", "Down"};
    int currentIndex = std::find(directions.begin(), directions.end(), spacecraft.direction) - directions.begin();
    int newIndex = (currentIndex + 1) % directions.size();
    spacecraft.direction = directions[newIndex];
}

void turn_up(Spacecraft& spacecraft) {
    if (spacecraft.direction != "Up") spacecraft.direction = "Up";
}

void turn_down(Spacecraft& spacecraft) {
    if (spacecraft.direction != "Down") spacecraft.direction = "Down";
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
            case 'l':
                turn_left(spacecraft);
                break;
            case 'r':
                turn_right(spacecraft);
                break;
            case 'u':
                turn_up(spacecraft);
                break;
            case 'd':
                turn_down(spacecraft);
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