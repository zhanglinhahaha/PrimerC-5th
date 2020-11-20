#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <set>

using namespace std;

class Quote {
public:
    Quote() { cout << "Quote()\n"; }
    Quote(string s, double p): bookNo(s), price(p) { cout << "Quote(string, double)\n"; }
    //copy construtor
    Quote(const Quote& q): bookNo(q.bookNo), price(q.price) { cout << "Quote(const Quote&)\n"; }
    //move construtor
    Quote(Quote&& q) noexcept: bookNo(move(q.bookNo)), price(move(q.price)) 
        { cout << "Quote(Quote&&)\n"; }
    //copy =
    Quote& operator=(const Quote& q) {
        bookNo = q.bookNo;
        price = q.price;
        cout << "Quote operator=(const Quote&)\n";
        return *this;
    }
    //move =
    Quote& operator=(Quote&& q) noexcept {
        bookNo = move(q.bookNo);
        price = move(q.price);
        cout << "Quote operator=(Quote&&)\n";
        return *this;
    }
    //destructor
    virtual ~Quote() { cout << "~Quote()\n"; }
    virtual void show() const { cout << bookNo << " " << price << endl; }
    virtual double net_price(size_t n) const { return price*n; }
    string isbn() const {return bookNo;}
private:
    string bookNo;
protected:
    double price;
};

class Disc_quote : public Quote {
public:
    Disc_quote() { cout << "Disc_quote()\n"; }
    Disc_quote(string s, double p, size_t n, double d): Quote(s, p), quantity(n), discount(d)
        { cout << "Disc_quote(string, double, size_t, double)\n"; }
    //copy construtor
    Disc_quote(const Disc_quote& q):Quote(q), quantity(q.quantity), discount(q.discount)
        { cout << "Disc_quote(const Disc_quote&)\n"; }
    //move construtor
    Disc_quote(Disc_quote&& q) noexcept:Quote(move(q)), quantity(move(q.quantity)), discount(move(q.discount))
        { cout << "Disc_quote(Disc_quote&&)\n"; }
    //copy =
    Disc_quote& operator=(const Disc_quote& q) {
        Quote::operator=(q);
        quantity = q.quantity;
        discount = q.discount;
        cout << "Disc_quote operator=(const Disc_quote&)\n";
        return *this;
    }
    //move =
    Disc_quote& operator=(Disc_quote&& q) noexcept {
        Quote::operator=(move(q));
        quantity = move(q.quantity);
        discount = move(q.discount);
        cout << "Disc_quote operator=(Disc_quote&&)\n";
        return *this;
    }
    //destructor
    ~Disc_quote() override { cout << "~Disc_quote()\n"; }
    double net_price(size_t n) const override = 0;
protected:
    size_t quantity;
    double discount;
};

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() { cout << "Bulk_quote()\n"; }
    /*
    Bulk_quote(string s, double p, size_t n, double d): Disc_quote(s, p, n, d)
        { cout << "Bulk_quote(string, double, size_t, double)\n"; }
    */
    using Disc_quote::Disc_quote;
    //copy construtor
    Bulk_quote(const Bulk_quote& q): Disc_quote(q)
        { cout << "Bulk_quote(const Bulk_quote&)\n"; }
    //move construtor
    Bulk_quote(Bulk_quote&& q) noexcept: Disc_quote(move(q))
        { cout << "Bulk_quote(Bulk_quote&&)\n"; }
    //copy =
    Bulk_quote& operator=(const Bulk_quote& q) {
        Disc_quote::operator=(q);
        cout << "Bulk_quote operator=(const Bulk_quote&)\n";
        return *this;
    }
    //move =
    Bulk_quote& operator=(Bulk_quote&& q) noexcept {
        Disc_quote::operator=(move(q));
        cout << "Bulk_quote operator=(Bulk_quote&&)\n";
        return *this;
    }
    //destructor
    ~Bulk_quote() override { cout << "~Bulk_quote()\n"; }
    double net_price(size_t n) const override {
        return n*price*(n >= quantity? 1-discount : 1);
    }
    void show() const override {
        Quote::show();
        cout << quantity << " " << discount << endl;
    }
};

class Basket {
public:
    void add_item(const shared_ptr<Quote>& sale) { items.insert(sale); }
    double total_receipt(ostream& os) const {
        double sum = 0.0;
        for(auto iter : items) {
            iter->show();
            sum += iter->net_price(20);
        }
        os << "sum: " << sum << endl;
        return sum;
    }
private:
    static bool compare(const shared_ptr<Quote>& lhs, const shared_ptr<Quote>& rhs) {
        return lhs->isbn() < rhs->isbn();
    }
    multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};
};

void test26() {
    cout << "=========1========\n";
    Bulk_quote bq1;
    cout << "=========2========\n";
    Bulk_quote bq2("tlbb", 20, 10, 5);
    cout << "=========3========\n";
    bq1 = move(bq2);
    cout << "=========4========\n";
    bq2.show();
    cout << "=========5========\n";
}

void test28() {
    vector<Quote> basket;
    basket.push_back(Quote("tlbb", 20));
    basket.push_back(Bulk_quote("sdxn", 20, 10, 0.5));
    cout << basket.back().net_price(20) << endl;
}

void test29() {
    vector<shared_ptr<Quote>> basket;
    basket.push_back(make_shared<Quote>("tlbb", 20));
    basket.push_back(make_shared<Bulk_quote>("sdxn", 20, 10, 0.5));
    cout << basket.back()->net_price(20) << endl;
}

void test30() {
    Basket b;
    b.add_item(make_shared<Quote>("tlbb", 20));
    b.add_item(make_shared<Bulk_quote>("sdxn", 20, 10, 0.5));
    b.total_receipt(cout);
}

int main() {
    test30();
    return 0;
}
