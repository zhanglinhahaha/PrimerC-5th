#include "strBlob.h"

class ConstStrBlobPtr {
public:
    ConstStrBlobPtr() : curr(0) { }
    ConstStrBlobPtr(const StrBlob& a, size_t sz = 0):
            wptr(a.data), curr(sz) { }
    string& deref() const;
    ConstStrBlobPtr& incr();
private:
    shared_ptr<vector<string>> check(size_t, const string&) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t i, const string &msg) const {
    auto ret = wptr.lock();
    if(!ret) {
        throw runtime_error("unbound ConstStrBlobPtr");
    }
    if(i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

string& ConstStrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];  
}

ConstStrBlobPtr& ConstStrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

ConstStrBlobPtr StrBlob::begin() const{
    return ConstStrBlobPtr(*this); 
}

ConstStrBlobPtr StrBlob::end() const{
    auto ret = ConstStrBlobPtr( *this, data->size() );
    return ret;
}