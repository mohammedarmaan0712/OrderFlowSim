#include <iostream>
#include <map>
#include "orderbook.hpp"
#include "order.hpp"

using namespace std;


int main() {
    map<const double, price_level> book = orderbookMap(); // Initialize the orderbook map
    cout << "Bid  Price  Ask" << endl;
    cout << "------------------" << endl;
    for (auto& [price, level] : book) {
        
        cout << level.getBidQueue().size() << "  ";
        cout << price << "  ";
        cout << level.getAskQueue().size() << endl;
    }
}



/*
The objective is to create s mini market simulator with orderbooks, bid and ask orders, order placement mechanism and a matching en
engine

Step 1: Define what an order is and the types of orders there are. Use ENUM for different ordertypes:
Here are a few that come to mind:
Buy limit, sell limit, buy market, sell market, stop loss, take profit, trailing stop.
Step 2: create a way for orders to be recorded at key specific levels
This will involve creating a data structure of orderbooks that can hold a bid queue and ask queue
Step 3: Create a way for price to move and orders to match
This will involve modifying the order class to allow for price levels and matching logic
Step 4: Implement a matching engine building on to step 3
Step 5: User interface that shows the movement, orderbook, ability to place orders and modify them

*/


//Define orderbook
