#include "models.h"

using namespace std;

int main() {
    Product Tshirt = Product("clothes", 12, 32);
    Client person("John", "Dupon", "1320242");
    Order first;
    first.setClient(person);
    first.addToCart(Tshirt);
    cout << first.getCart()[0].getName() << endl;
    return 0;
}