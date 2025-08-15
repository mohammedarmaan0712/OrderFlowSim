#pragma once

#include <iostream>

using namespace std;

enum class OrderType {
    BuyLimit,
    SellLimit,
    BuyMarket,
    SellMarket,
    StopLoss,
    TakeProfit,
    TrailingStop
};


enum class OrderStatus {
    Active,
    Filled,
    Cancelled,
};


//this class of order takes in the type, price and quantity of the order to match it when needed
class Order{
    //these ought to be private since they are variables that should not be modified directly
    private:
        OrderType type;
        double price;
        int quantity;
        int orderID;
        int accountID;
        OrderStatus status;
    //public declaration of constructors, getters and setters
    public:
    //constructor
        Order(OrderType type, double price, int quantity, int orderID, int accountID, OrderStatus status);
    //getters
        OrderType getType() const;
        double getPrice() const;
        int getQuantity() const;
        int getOrderID() const;
        int getAccountID() const;
        OrderStatus getStatus() const;
    //setters
        void setStatus(OrderStatus newStatus);
    //Key functions
        void fillOrder();
        void cancelOrder();
};
