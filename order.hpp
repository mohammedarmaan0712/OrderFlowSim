#pragma once
#include <iostream>
#include <map>
#include "orderbook.hpp"
#include "order.hpp"


using namespace std;

enum class OrderType {
    BuyLimit,
    SellLimit,
    BuyMarket,
    SellMarket
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
    //Key functions to be implemented in derived classes
        virtual void submitOrder(Order* order, map<const double, price_level>& book)=0;
        virtual void fillOrder(Order* order, map<const double, price_level>& book)=0;
        virtual void cancelOrder(Order* order, map<const double, price_level>& book)=0;
};

//different types of orders
//Limit orders: Buy Limit, Sell Limit
//Market orders: Buy Market, Sell Market
//Stop orders: Stop Loss, Take Profit, Trailing Stop

class LimitOrder : public Order {
    public:
        LimitOrder(OrderType type, double price, int quantity, int orderID, int accountID, OrderStatus status);
        void submitOrder(Order* order, map<const double, price_level>& book) override;
        void fillOrder(Order* order, map<const double, price_level>& book) override;
        void cancelOrder(Order* order, map<const double, price_level>& book) override;
};
class MarketOrder : public Order {
    public:
        MarketOrder(OrderType type, double price, int quantity, int orderID, int accountID, OrderStatus status);
        void submitOrder(Order* order, map<const double, price_level>& book) override;
        void fillOrder(Order* order, map<const double, price_level>&book) override;
        void cancelOrder(Order* order, map<const double, price_level>&book) override;
};

