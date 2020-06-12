#include "Vector.h" // ？
#include<utility>
#include<stdexcept>
#include<vector>

using namespace V;

template<typename Element>
Vector<Element>::Vector(std::size_t initCapacity)
    :elems { new Element[initCapacity] },
     v_size { 0 },
     v_capacity { initCapacity } {
}

template<typename Element>
Vector<Element>::~Vector() {
    delete[] elems;
}

template<typename Element>
Vector<Element>::Vector(const Vector<Element>& vec)
    :elems { new Element[vec.v_capacity] },
     v_size { 0 },
     v_capacity { vec.v_capacity } {
         for (std::size_t i = 0; i < vec.v_size; i++)
            push_back(std::move(*(vec.elems+i)));
}

template<typename Element>
Vector<Element>::Vector(Vector<Element>&& rvec)
    :elems { rvec.elems },
     v_size { rvec.v_size },
     v_capacity { rvec.v_capacity } {
         rvec.elems = nullptr;
}

template<typename Element>
Vector<Element>& Vector<Element>::operator=(const Vector<Element>& vec) {
    if (this == &vec)
        return *this;
    delete[] elems;
    elems = new Element[vec.v_capacity];
    v_size = 0;
    v_capacity = vec.v_capacity;
    for (std::size_t i = 0; i < vec.v_capacity; i++) 
        push_back(std::move(*(vec.elems+i)));
    return *this;
}

template<typename Element>
Vector<Element>& Vector<Element>::operator=(Vector<Element>&& rvec) {
    std::swap(elems, rvec.elems);
    std::swap(v_size, rvec.v_size);
    std::swap(v_capacity, rvec.v_capacity);
    return *this;
}

template<typename Element>
Element& Vector<Element>::operator[](std::size_t index) {
    if (index >= v_size)
        throw std::out_of_range("index out of range");
    return *(elems + index);
}

template<typename Element>
const Element& Vector<Element>::operator[](std::size_t index) const {
    if (index >= v_size)
        throw std::out_of_range("index out of range");
    return *(elems + index);
}

template<typename Element>
bool Vector<Element>::empty() {
    return v_size == 0;
}

template<typename Element>
std::size_t Vector<Element>::size() {
    return v_size;
}

template<typename Element>
std::size_t Vector<Element>::capacity() {
    return v_capacity;
}

template<typename Element>
void Vector<Element>::reserve(std::size_t capacity) {
    if (capacity <= v_capacity) return;
    Vector<Element> copy { capacity };
    std::swap(elems, copy.elems);
    copy.v_size = v_size;
    std::swap(*this, copy);
}

template<typename Element>
Element& Vector<Element>::back() {
    return *(elems + v_size - 1);
} 

template<typename Element>
const Element& Vector<Element>::back() const {
    return *(elems + v_size - 1);
}

template<typename Element>
void Vector<Element>::clear() {
    Vector<Element> copy { v_capacity };
    std::swap(*this, copy);
}

template<typename Element>
void Vector<Element>::resize(std::size_t size) {
    if (size = v_size) return; 
    else if (size < v_size)
        while (size != v_size)
            pop_back();
    else if (size <= v_capacity) {
        while (size != v_size)
            push_back(Element()); // 假定Element是自定类型;
    } else {
        reserve(size);
        while (size != v_size)
            push_back(Element()); // 假定Element是自定类型;
    }
}
template<typename Element>
void Vector<Element>::pop_back() {
    // 不用处理*(elems + v_size - 1);
    --v_size;
}

template<typename Element>
void Vector<Element>::push_back(const Element& e) {
    if (v_size == v_capacity)
        reserve(v_size + 1);
    *(elems + v_size++) = e;
}

template<typename Element>
void Vector<Element>::push_back(Element&& e) {
    // 这里是一个万能引用形参，所以一定要用move函数
    if (v_size == v_capacity)
        reserve(v_size + 1);
    elems[v_size++] = std::move(e);
    // std::swap(*(elems + v_size++), static_cast<Element&&>(e));    
}

// template<typename Element>
// typename Vector<Element>::iterator Vector<Element>::insert(const typename Vector<Element>::iterator& itr, const Element& e) {
// 不知道对不对
// }


void test() {
    std::vector<A> vec {10};
    std::vector<A> copy {5};
    std::swap(vec, copy);
}


int main() {
    Vector<A> vec(10);
    vec.push_back(A {});
    vec.push_back(A {});
    vec.push_back(A {});
    vec[3];
}
