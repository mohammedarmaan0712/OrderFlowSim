#pragma once
#include <iostream>
#include <queue>
#include "order.hpp"
#include <map>

using namespace std;



//this will have a price level and two pointers to bid and ask queues
class price_level{
    private:
        queue<Order*> bidQueue; // Queue for buy orders 
        queue<Order*> askQueue; // Queue for sell orders
    public:
    //constructor
    price_level();
    //getters
    queue<Order*>& getBidQueue();
    queue<Order*>& getAskQueue();
    //setters (needed for setting up new queues when an order is removed)
    void setBidQueue(queue<Order*> newBidQueue) { bidQueue = newBidQueue; }
    void setAskQueue(queue<Order*> newAskQueue) { askQueue = newAskQueue; }
    //add orders to queues
    void addBidOrder(Order* order) ;
    void addAskOrder(Order* order) ;
    //remove orders from queues
    void removeOrder(Order* order) ;
};



map <const double, price_level> orderbookMap (); // Map to hold price levels for quick access