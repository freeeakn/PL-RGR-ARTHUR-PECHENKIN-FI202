#include "models.h"

using namespace std;

int main() {
    Product Tshirt = Product("clothes", 12, 32);
    Client person("John", "Dupon", "1320242");
    Order first;
    first.setClient(person);
    cout << first.getClient().getLastName() << endl;
    return 0;
}