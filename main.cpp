#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

/*
Do the following:
1. Simulate a fake orderbook using rand function
2. Simulate Market orders by taking rand() and
3. Match market to orderbook (initially, the orderbook is static, will make it dynamic later)
4. use different algorithms to match market orders to orderbook
5. Print the orderbook and the matched orders together
6. Initially, the orderbook will have only a small price range and then will simulate a larger, more realistic orderbook

*/


class price_level{
    private:
        const double price;
        int bid;
        int ask;
    public:
        //constructor
        price_level(double p, int b, int a)
            : price(p), bid(b), ask(a)
        {
            if (price < 0 || bid < 0 || ask < 0) {
                throw std::invalid_argument("Price, bid, and ask must be non-negative.");
            }
        }
        //getters
        double get_price() const { return price; }
        int get_bid() const { return bid; }
        int get_ask() const { return ask; }
        //setters
        void set_bid(int b) { 
            if (b < 0) {
                throw std::invalid_argument("Bid must be non-negative.");
            }
            bid = b; 
        }
        void set_ask(int a) { 
            if (a < 0) {
                throw std::invalid_argument("Ask must be non-negative.");
            }
            ask = a; 
        }
};

vector<price_level> create_orderbook() {
    vector<price_level> orderbook;
    // Simulating a small price range orderbook
    for (double price = 0; price <= 10.0; price += 1.0) {
        orderbook.emplace_back(price, rand() % 10, rand() % 10);
    }
    return orderbook;
}



int main() {
    vector<price_level> orderbook = create_orderbook();
    for (const auto& level : orderbook) {

        cout << "Bid: " << level.get_bid() 
             << ", Price: " << level.get_price()  
             << ", Ask: " << level.get_ask() << endl;
    }
    return 0;
}