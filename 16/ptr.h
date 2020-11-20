#include <iostream>
#include <string>
#include <memory>

using namespace std;

class DebugDelete {
public:
    DebugDelete(ostream &s = cerr): os(s) { }
    template <typename T> void operator()(T *p) const {
        os << "deleting unique_ptr: " << *p << "\n";
        delete p;
    }
private:
    ostream& os;
};

template <typename T>
class shared_ptr_tmp {
public:
    shared_ptr_tmp(): spt(nullptr), use_count(new size_t(1)), deleter(DebugDelete()) { }
    shared_ptr_tmp(T* tmp): spt(tmp), use_count(new size_t(1)), deleter(nullptr) { }
    shared_ptr_tmp(T* tmp, function<void(T*)> d) {
        spt = tmp;
        deleter = d;
        use_count = new size_t(1);
    }
    //copy
    shared_ptr_tmp(const shared_ptr_tmp& tmp): spt(tmp.spt), use_count(tmp.use_count), deleter(tmp.deleter) {
        ++*use_count;
    }
    //Copy assignment
    shared_ptr_tmp& operator=(const shared_ptr_tmp& tmp) {
        ++*(tmp.use_count);
        ~shared_ptr_tmp();
        spt = tmp.spt;
        use_count = tmp.use_count;
        deleter = tmp.deleter;
    }
    T& operator*() { return *spt; }

    void reset(T *pointer, std::function<void(T*)> d) {
        if (spt != pointer) {
            ~shared_ptr_tmp();
            spt = pointer;
            use_count = new size_t(1);
        }
        deleter = d;
    }

    ~shared_ptr_tmp() {
        if(--*use_count == 0 && spt) {
            deleter? deleter(spt) : delete spt;
            delete use_count;
        }else if(!spt){
            delete use_count;
        }
        use_count = nullptr;
        spt = nullptr; 
    }
private:
    T* spt;
    function<void(T*)> deleter;
    size_t* use_count;
};

template <typename T, typename D>
class unique_ptr_tmp {
public:
    unique_ptr_tmp() = default;
    unique_ptr_tmp(T* up): upt(up) { }
    T& operator*() const { return *upt; }
    T* get() const noexcept { return upt; }
    void reset(T* p) noexcept { deleter(upt); upt = p;}
    ~unique_ptr_tmp()
    {
        deleter(upt);
    }
private:
    T* upt = nullptr;
    D  deleter = D();
};
