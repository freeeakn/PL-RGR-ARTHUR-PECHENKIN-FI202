#include <iostream>
#include <string>

#include <iostream>

class Product {
private:
    std::string productName;
    unsigned int price;
    unsigned int size;

public:
    Product(std::string productName, unsigned int price, unsigned int size) :
        productName(productName), price(price), size(size) {}

    ~Product() {}

    std::string getProductName() const {
        return productName;
    }

    unsigned int getPrice() const {
        return price;
    }

    unsigned int getSize() const {
        return size;
    }

};

class Order {
private:
    Product *Cart;
    unsigned int quantity;

public:

    Order() : Cart(), quantity(0) {}
    Order(Product *Cart, unsigned int quantity) :
        Cart(Cart), quantity(quantity) {}

    ~Order() {
        delete Cart;
        std::cout << "Destructor called for Order" << std::endl;
    }

    Product* getCart() const {
        return Cart;
    }

    unsigned int getQuantity() const {
        return quantity;
    }

    void setCart(Product *Cart) {
        delete this->Cart;
        this->Cart = Cart;
    }

    void setQuantity(unsigned int quantity) {
        this->quantity = quantity;
    }

};

class User {
private:
    std::string userName;
    std::string pass;
    bool isAdmin;

public:
    User(std::string userName, std::string pass, bool isAdmin) :
        userName(userName), pass(pass), isAdmin(isAdmin) {}

    ~User() {
        std::cout << "Destructor called for User" << std::endl;
    }

    std::string getUserName() const {
        return userName;
    }

    std::string getPass() const {
        return pass;
    }

    bool getIsAdmin() const {
        return isAdmin;
    }

    void setUserName(std::string userName) {
        this->userName = userName;
    }

    void setPass(std::string pass) {
        this->pass = pass;
    }

    void setIsAdmin(bool isAdmin) {
        this->isAdmin = isAdmin;
    }

};