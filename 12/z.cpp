#include "x.h"

class StrBlobPtr;
class StrBlob {
    friend class StrBlobPtr;
public:
    StrBlobPtr begin() { return StrBlobPtr(*this);}
    StrBlobPtr end() {
        auto ret = StrBlobPtr(*this, data->size());
        return ret;
    }
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const { return data->size();}
    bool empty() const { return data->empty();}
    void push_back(const string &s) { data->push_back(s);}
    void pop_back();
    string &front();
    string &back();
private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};

StrBlob::StrBlob(): data(make_shared<vector<string>>()) { }
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) { }

void  StrBlob::check(size_type i, const string &msg) const {
    if(i >= data->size()) {
        throw out_of_range(msg);
    }
}

string & StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}
string & StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}
void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    return data->pop_back();
}

int main() {
    StrBlob b1 = {"I", "am", "zl"};
    auto sum = b1.size();
    cout << sum << endl;
    while(sum >= 0) {
        try {
            string s = b1.back();
            cout << s << endl;
            sum--;
            b1.pop_back();
        }
        catch(out_of_range &m) {
            cout << m.what() << endl;
            break;
        }
    }
    return 0;
}

