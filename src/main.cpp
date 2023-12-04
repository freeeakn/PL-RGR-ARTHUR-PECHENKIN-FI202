#include "models.h"

int main() {
    User user("admin", "admin", true);
    std::cout << user.getUserName() << std::endl;
    std::cout << user.getPass() << std::endl;
    return 0;
}