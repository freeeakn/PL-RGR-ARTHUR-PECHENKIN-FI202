#include "models.h"

int main() {
    Product Tshirt = Product("clothes", 12, 32);
    std::cout << Tshirt.getPrice() << std::endl;
    std::string str;
    std::cin >> str;
    Tshirt.setProductType(str);
    std::cout << Tshirt.getProductType() << std::endl;
    return 0;
}