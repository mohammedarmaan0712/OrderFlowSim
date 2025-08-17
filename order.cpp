#include <iostream>
#include <map>
#include "orderbook.hpp"
#include "order.hpp"


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

// Key functions to be implemented in derived classes
LimitOrder::LimitOrder(OrderType type, double price, int quantity, int orderID, int accountID, OrderStatus status)
    : Order(type, price, quantity, orderID, accountID, status) {/*need to submit order here. once orderbook maps are finalized*/}

void LimitOrder::submitOrder(Order* order, map<const double, price_level>& book) {
    // Implementation for submitting a limit order
    if (order->getPrice() <= 0 || order->getQuantity() <= 0) {
        cout << "Invalid price or quantity for order." << endl;
        delete order; // Clean up the allocated memory
        return;
    }
    if(book.find(order->getPrice()) == book.end()) {
        // If not, create a new price level
        book[order->getPrice()] = price_level();
        if (order->getType() == OrderType::BuyLimit)
            book[order->getPrice()].addBidOrder(order); // Add the order to the appropriate queue
        else if (order->getType() == OrderType::SellLimit)
            book[order->getPrice()].addAskOrder(order); // Add the order to the appropriate queue
    }
    else{
        book[order->getPrice()] = price_level();
        if (order->getType() == OrderType::BuyLimit)
            book[order->getPrice()].addBidOrder(order); // Add the order to the appropriate queue
        else if (order->getType() == OrderType::SellLimit)
            book[order->getPrice()].addAskOrder(order); // Access existing price level
    }
}

void LimitOrder::cancelOrder(Order* order,  map<const double, price_level>& book) {
    //get order type
    OrderType type = order->getType(); // gets the type of the order
    queue<Order*> tempQueue; // declares a temp queue to modify
    if (type == OrderType::BuyLimit){ // find if buy or sell
        tempQueue = book[order->getPrice()].getBidQueue();
    }
    else if (type == OrderType::SellLimit){ // find if buy or sell
        tempQueue = book[order->getPrice()].getAskQueue();
    }
    else {
        cout << "Order type not recognized for removal." << endl;
        return;
    }
    queue<Order*> emptyQueue;//declares an empty queue that will be filled with orders that are not being removed
    // Loop through the tempQueue to find and remove the order
    while(!tempQueue.empty()) { //traverses the queue
        Order* currentOrder = tempQueue.front(); // Get the front order
        
        if (currentOrder->getOrderID() == order->getOrderID()) { // skip it do not add it to emptyQueue
            // Found the order to remove
            tempQueue.pop();
            continue; // Skip this order
        }
        else{
            // Keep the order in the queue
            emptyQueue.push(currentOrder); //add it to empty queue
            tempQueue.pop();
        }
    }
    // Now replace the original queue with the modified one
    if (type == OrderType::BuyLimit) {
        book[order->getPrice()].setBidQueue(emptyQueue); // replace bid queue with empty queue
    } else if (type == OrderType::SellLimit) {
        book[order->getPrice()].setAskQueue(emptyQueue); // replace ask queue with empty queue
    }
}

void LimitOrder::fillOrder(Order* order, map<const double, price_level>& book) {
    //Implementation for filling a limit order will require checking the price action and the order
    //requires matching incoming Market orders with existing limit orders
    //requires price action class to be implemented
    //price action is dependant on market orders and movements. 
    //price action will have an increment or decrement function that will fill orders
    cout<< "Filling limit order is not implemented yet." << endl;
}

MarketOrder::MarketOrder(OrderType type, double price, int quantity, int orderID, int accountID, OrderStatus status)
    : Order(type, price, quantity, orderID, accountID, status) {/*need to submit order here. once orderbook maps are finalized*/}

void submitOrder(Order* order, map<const double, price_level>& book) {
    // Implementation for submitting a market order
    cout<< "Submitting market order is not implemented yet." << endl;
}

void MarketOrder::fillOrder(Order* order, map<const double, price_level>& book) {
    // Implementation for filling a market order
    cout<< "Filling market order is not implemented yet." << endl;
}

void MarketOrder::cancelOrder(Order* order, map<const double, price_level>& book) {
    // Implementation for cancelling a market order
    cout<< "Cancelling market order is not implemented yet." << endl;
}
