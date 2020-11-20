#include <iostream>
#include <string>
#include <memory>

using namespace std;

template <typename T>
class Vec {
public:
    Vec() : elements(NULL),first_free(NULL), cap(NULL) { }
    Vec(initializer_list<T> l) {
        T* const newData = alloc.allocate(l.size());
        T* p = newData;
        for(const auto &t : l)
            alloc.construct(p++, t);
        elements = newData;
        first_free = cap = elements+l.size();
    }
    Vec(const Vec&);
    Vec &operator=(const Vec&);
    ~Vec();
    void push_back(const T&);
    void push_back(T &&s) {
        chk_n_alloc();
        alloc.construct(first_free++, move(s));
    }
    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap - elements;}
    T* begin() const {return elements;}
    T* end() const {return first_free;}
    //移动构造函数
    Vec(Vec &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap) {
        s.elements = s.first_free = s.cap = NULL;
    }
    Vec& operator=(Vec &&s) noexcept {
        if(this != &s) {
            free();
            elements = s.elements;
            first_free = s.first_free;
            cap = s.cap;
            s.elements = s.first_free = s.cap = NULL;
        }
        return *this;
    }
    template<typename... Args> void emplace_back(Args... args) {
        chk_n_alloc();
        alloc.construct(first_free++, forward<Args>(args)...);
    }
private:
    static allocator<T> alloc;
    void chk_n_alloc() {
        if(size() == capacity()) reallocate();
    }
    pair<T*, T*> alloc_n_copy(const T*, const T*);
    void free();
    void reallocate();
    T* elements; //数组首元素
    T* first_free; //数组第一个空闲元素
    T* cap; //数组尾后位置
};

template <typename T>
allocator<T> Vec<T>::alloc;

template <typename T>
void Vec<T>::push_back(const T &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

template <typename T>
pair<T*, T*> Vec<T>::alloc_n_copy(const T* b, const T* e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

template <typename T>
void Vec<T>::free() {
    if(elements) {
        for(auto p = first_free; p != elements;) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

template <typename T>
Vec<T>::Vec(const Vec &s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template <typename T>
Vec<T>::~Vec() {free(); }

template <typename T>
Vec<T> &Vec<T>::operator=(const Vec &s) {
    auto data = alloc_n_copy(s.begin(), s.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

template <typename T>
void Vec<T>::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for(size_t i = 0; i != size(); ++i)
        alloc.construct(dest++,move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

int main() {
    Vec<int> v = { 1, 2, 3, 4, 5 };
    Vec<int> v2;
    v2 = v;
    std::cout << v2.capacity() << "\n";
    v2.push_back(99);
    for (auto t : v2)
        std::cout << t << " ";
    std::cout << v2.capacity() << "\n";

    Vec<string> vs;
    vs.emplace_back(10, 'c');
    string s1 = "hello", s2 = " world", s = "hahaha";
    vs.emplace_back(s1 + s2);
    vs.emplace_back(s);
    cout << vs.size() << endl;
    for(auto s : vs) cout << s << " ";
    return 0;
}
