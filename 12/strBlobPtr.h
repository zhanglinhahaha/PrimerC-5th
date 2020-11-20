#include "strBlob.h"

class StrBlobPtr {
public:
    StrBlobPtr() : curr(0) { }
    StrBlobPtr(StrBlob& a, size_t sz = 0):
            wptr(a.data), curr(sz) { }
    string& deref() const;
    StrBlobPtr& incr();
private:
    shared_ptr<vector<string>> check(size_t, const string&) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const {
    auto ret = wptr.lock();
    if(!ret) {
        throw runtime_error("unbound StrBlobPtr");
    }
    if(i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

string& StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];  
}

StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this); 
}

StrBlobPtr StrBlob::end() {
    auto ret = StrBlobPtr( *this, data->size() );
    return ret;
}