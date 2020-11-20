#include <iostream>
#include <string>

class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price):
        bookNo(book), price(sales_price) { }
    std::string isbn() const { return bookNo;}
    virtual double net_price(std::size_t n) const;
    virtual ~Quote() = default;
    void out(const std::string &s) {std::cout << "hello world! " << s << std::endl;}
private:
    std::string bookNo;
//允许派生类访问，禁止其他用户访问
protected:
    double price = 0.0;
};

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& book, double p, std::size_t qty, double disc):
        Quote(book, p), min_qty(qty), discount(disc) { }
    double net_price(std::size_t) const override;
    using Quote::out;
    using Quote::price;
private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

double Quote::net_price(size_t cnt) const {
    return cnt * price;
}

double Bulk_quote::net_price(size_t cnt) const {
    if(cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string& book, double p, std::size_t qty, double disc):
        Quote(book, p), quantity(qty), discount(disc) { }
    //含义纯虚函数的类是抽象基类,定义接口，不能创建抽象基类的对象
    double net_price(std::size_t) const override = 0;
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class B_quote : public Disc_quote {
public:
    B_quote() = default;
    B_quote(const std::string &book, double p, std::size_t qty, double disc):
        Disc_quote(book, p, qty, disc) { }
    double net_price(std::size_t) const override;
};

double B_quote::net_price(size_t cnt) const {
    if(cnt > quantity)
        return price * ((1- discount) * 10 + (cnt - 10));
    else
        return price * cnt * (1 - discount);
}

/*
//派生类向基类的自动类型转换只对指针或引用类型有效
Quote item;//基类对象
Bulk_quote bulk;//派生类对象
Quote *p = &item;//p指向Quote对象
p = &bulk;//p指向bulk的Quote部分
Quote &r = bulk;//r绑定到bulk的Quote部分
基类的指针或引用的静态类型可能与其动态类型不一致

不能将基类转换成派生类,可以使用类型转换 dynamic_cast 或者 static_cast
Quote base;
Bulk_quote *bulkP = &base;//error
Bulk_quote &bulkRef = base;//error
*/

double print_total(std::ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
       << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

int main() {
    Bulk_quote q("Tfc", 20, 5, 0.5);
    q.out("zl");
    std::cout << q.price << std::endl;
    print_total(std::cout, q, 2);
    print_total(std::cout, q, 10);
    Quote base("PC++", 50);
    print_total(std::cout, base, 3);
    B_quote b1("JAVA", 20, 10, 0.5);
    print_total(std::cout, b1, 10);
    B_quote b2("JAVA", 20, 10, 0.5);
    print_total(std::cout, b2, 20);
    return 0;
}
