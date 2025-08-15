#include "order.hpp"
#include <iostream>

using namespace std;

//constructor implementation
Order::Order(OrderType type, double price, int quantity, int orderID, int accountID, OrderStatus status)
    : type(type), price(price), quantity(quantity), orderID(orderID), accountID(accountID), status(status) {}

//getters implementation
OrderType Order::getType() const {
    return type;
}
double Order::getPrice() const {
    return price;
}
int Order::getQuantity() const {
    return quantity;
}
int Order::getOrderID() const {
    return orderID;
}
int Order::getAccountID() const {
    return accountID;
}
OrderStatus Order::getStatus() const {
    return status;
}
//setters implementation
void Order::setStatus(OrderStatus newStatus){
    status = newStatus;
}

// Key functions implementation
void Order::fillOrder() {
    // Logic to fill the order
    status = OrderStatus::Filled;
    delete this; // Assuming this is a self-managed object, delete it after filling
}
void Order::cancelOrder() {
    // Logic to cancel the order
    status = OrderStatus::Cancelled;
    delete this; // Assuming this is a self-managed object, delete it after cancelling
}
