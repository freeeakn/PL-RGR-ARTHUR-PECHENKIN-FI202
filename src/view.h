#ifndef VIEWS_H
#define VIEWS_H

#include "models.h"

class View : public Observer {
public:
   View(Product *model) {
      _model = model;
      _model->addObserver(this);
   }
   virtual void update() {
      system("clear");
      std::cout << "Name of product:" << _model->getName() << std::endl;
      printf("Price of product: %.2u\n", _model->getPrice());
      printf("Size: %.2u\n", _model->getSize());
      printf("Input name: ");
   }
private:
   Product *_model;
};

#endif //VIEWS_H
