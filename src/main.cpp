#include "controller.h"
#include "view.h"
#include "models.h"

using namespace std;

int main() {
    Product model;
    View view(&model);
    Controller controller(&model);
    controller.start();
    return 0;
}