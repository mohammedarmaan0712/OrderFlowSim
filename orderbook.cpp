#include "orderbook.hpp"
#include <vector>
#include <queue>
#include <map>

using namespace std;


//implementation of price_level constructor
price_level::price_level() {
    // Initialize the bid and ask queues
    queue<Order*> bidQueue;
    queue<Order*> askQueue;
}
//getters implementation

queue<Order*>& price_level::getBidQueue() {
    return bidQueue;
}
queue<Order*>& price_level::getAskQueue() {
    return askQueue;
}
//add orders to queues implementation
void price_level::addBidOrder(Order* order) {
    bidQueue.push(order);
}
void price_level::addAskOrder(Order* order) {
    askQueue.push(order);
}
//remove orders from queues implementation
void price_level::removeOrder(Order* order) {
    //get order type
    OrderType type = order->getType(); // gets the type of the order
    queue<Order*> tempQueue; // declares a temp queue to modify
    if (type == OrderType::BuyLimit){ // find if buy or sell
        tempQueue = bidQueue;
    }
    else if (type == OrderType::SellLimit){ // find if buy or sell
        tempQueue = askQueue;
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
        bidQueue = emptyQueue; // replace bid queue with empty queue
    } else if (type == OrderType::SellLimit) {
        askQueue = emptyQueue; // replace ask queue with empty queue
    }
}

map <const double, price_level> orderbookMap (){
    map <const double, price_level> orderbookMap; // Map to hold price levels for quick access
    for (double price = 0.0; price <= 100.0; price += 0.01) {
        orderbookMap[price] = price_level(); // Initialize each price level with an empty price_level object
    }
    return orderbookMap; // Return the initialized map
}
 // Map to hold price levels for quick access