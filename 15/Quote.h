#ifndef QUOTE_H
#define QUOTE_H
#include <iostream>
using namespace std;

class Quote {
public:
    Quote() = default;
    Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) { }
    string isbn() const { return bookNo;}
    virtual double net_price(size_t n) const { return n*price;}
    virtual ~Quote() = default;//基类通常都应该定义一个虚析构函数
    virtual void debug() const {
        cout << bookNo << " " << price << endl;
    }
private:
    string bookNo;
protected:
    double price = 0.0;
};

class Bulk_Quote : public Quote {
public:
    Bulk_Quote() = default;
    Bulk_Quote(const string& book, double p, size_t qty, double disc):
                Quote(book, p), min_qty(qty), discount(disc) { }
    double net_price(size_t n) const override {
        if(n >= min_qty) return n*(1-discount)*price;
        else return n*price;
    }
    void debug() const override {
        Quote::debug();
        cout << min_qty << " " << discount << endl;
    }
private:
    size_t min_qty;
    double discount;
};

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const string& book, double p, size_t qty, double disc):
                Quote(book, p), quantity(qty), discount(disc) { }
    double net_price(size_t n) const = 0;
    void debug() const override {
        Quote::debug();
        cout << quantity << " " << discount << endl;
    }
protected:
    double discount;
    size_t quantity;
};

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string& book, double p, size_t qty, double disc):
                Disc_quote(book, p, qty, disc) { }
    double net_price(size_t n) const override {
        if(n <= quantity) return n*(1-discount)*price;
        else return quantity*(1-discount)*price+(n-quantity)*price;
    }
};
#endif
