#include <iostream>
#include <queue>
#include <map>
#include "order.hpp"
#include "orderbook.hpp"
#include "price_action.hpp"

using namespace std;

//constructor
price_action :: price_action(double initialPrice, map<const double, price_level>& initialOrderbook)
    : currentPrice(initialPrice), orderbook(initialOrderbook) {}

//getter for current price
double price_action::getCurrentPrice() const {
    return currentPrice;
}
//setter for current price
void price_action::updatePrice() {
    currentPrice+=0.01; //increment of 0.01 modelling CL price action
}

