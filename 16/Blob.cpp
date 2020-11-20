#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "ptr.h"

using namespace std;

template <typename T> class BlobPtr;
template <typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
template <typename T>
bool operator< (const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);


template <typename T>
class Blob {
    friend class BlobPtr<T>;
public:
    typedef T value_type;
    typedef typename vector<T>::size_type size_type;
    Blob(): data(make_shared<vector<T>>()) { }
    Blob(initializer_list<T> il): data(make_shared<vector<T>>(il)) { }
    size_type size() const { return data->size(); }
    void push_back(const T& t) { data->push_back(t); }
    void push_back(T &&t) { data->push_back(move(t)); }
    void pop_back() {
        check(0, "pop_back on empty Blob");
        data->pop_back();
    }
    T& back() {
        check(0, "back on empty Blob");
        return data->back();
    }
    const T& back() const {
        check(0, "back on empty Blob");
        return data->back();
    }
    T& operator[](size_type i) {
        check(i, "subscript out of range");
        return (*data)[i];
    }
    const T& operator[](size_type i) const {
        check(i, "subscript out of range");
        return (*data)[i];
    }
private:
    shared_ptr<vector<T>> data;
    void check(size_type i, const string& msg) const;
};

template <typename T>
void Blob<T>::check(size_type i, const string& msg) const {
    if(i >= data->size())
        throw out_of_range(msg);
}


template <typename T>
class BlobPtr {
    friend bool operator==<T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
    friend bool operator< <T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
public:
    BlobPtr(): curr(0) { }
    BlobPtr(Blob<T>& a, size_t sz = 0): wptr(a.data), curr(sz) { }
    T& operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    BlobPtr& operator++() {
        check(curr, "increment past end of StrBlob");
        ++curr;
        return *this;
    }
    BlobPtr& operator--() {
        --curr;
        check(curr, "decrement past begin of StrBlob");
        return *this;
    }
    BlobPtr operator++(int) {
        BlobPtr ret = *this;
        ++*this;
        return ret;
    }
    BlobPtr operator--(int) {
        BlobPtr ret = *this;
        --*this;
        return ret;
    }
private:
    shared_ptr<vector<T>> check(size_t, const string&) const;
    weak_ptr<vector<T>> wptr;
    size_t curr;
};
template <typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
    if(lhs.wptr.lock() != rhs.wptr.lock()) {
        throw runtime_error("ptrs to different Blobs!");
    }
    return lhs.curr == rhs.curr;
}
template <typename T>
bool operator<(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
    if(lhs.wptr.lock() != rhs.wptr.lock()) {
        throw runtime_error("ptrs to different Blobs!");
    }
    return lhs.curr < rhs.curr;
}
template <typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(size_t i, const string& msg) const {
    auto ret = wptr.lock();
    if(!ret)
        throw runtime_error("undound BlobPtr"); 
    if(i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

int main() {
    Blob<int> ia = {0,1,2,3,4};
    cout << ia[2] << ia.back() << endl;
    BlobPtr<int> bp(ia);
    cout << *bp << endl;
    cout << (bp == ++bp) << endl;
    cout << *bp << endl;
    bp--;bp--;
    return 0;
}
