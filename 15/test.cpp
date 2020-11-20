#include "Quote.h"

class Bulk : public Quote {
public:
    Bulk(const string& book, double pri, double dis, size_t n):
                    Quote(book, pri), discount(dis), max_qty(n) {
                        max_dis = n * (1 - dis) * pri;
                    }
    double net_price(size_t n) const override {
        if(n <= max_qty) return n*(1-discount)*price;
        else return max_dis + (n-max_qty)*price;
    }
    void debug() const override {
        Quote::debug();
        cout << max_qty << " " << discount << " " << max_dis << endl;
    }
private:
    size_t max_qty;
    double discount;
    double max_dis;
};

void test6() {
    Quote q("bcsj", 12);
    Bulk_Quote bq("pfdsj", 15, 5, 0.2);
    Bulk b("sgyy", 20, 0.2, 5);
    cout << q.net_price(4) << endl;
    cout << bq.net_price(1) << endl;
    cout << bq.net_price(10) << endl;
    cout << b.net_price(1) << endl;
    cout << b.net_price(10) << endl;
    q.debug();
    bq.debug();
    b.debug();
}

void test16() {
    Bulk_quote bq("pfdsj", 15, 5, 0.2);
    Disc_quote& dp = bq;
    bq.debug();
    cout << dp.net_price(1) << endl;
    cout << dp.net_price(10) << endl;
    dp.debug();
    Disc_quote dq;
}

int main() {
    test16();
    return 0;
}
