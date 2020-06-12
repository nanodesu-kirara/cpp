#ifndef M_V
#define M_V
#include<cstddef>
namespace V
{

    template<typename Element>
    class Vector {
        public:
            explicit Vector(std::size_t);
            ~Vector();

            Vector(const Vector&);
            Vector(Vector&&);

            Vector& operator=(const Vector&);
            Vector& operator=(Vector&&);

            Element& operator[](std::size_t);
            const Element& operator[](std::size_t) const;

            inline bool empty();
            inline std::size_t size();
            inline std::size_t capacity();
            void reserve(std::size_t);

            inline Element& back();
            inline const Element& back() const;

            void clear();
            void resize(std::size_t);
            void pop_back();
            void push_back(const Element&);
            void push_back(Element&&);

            class iterator {
                private:
                    Element* pe;
                public:
                    explicit iterator(Element* e): pe {e} {}

                    iterator(const iterator& itr): pe { itr.pe } {}

                    Element& operator*() { return *pe; }

                    iterator operator++() { 
                        ++pe;
                        return *this;
                    }

                    iterator operator++(int) {
                        iterator old { *this };
                        ++pe;
                        return old; 
                    }

                    iterator operator--() { 
                        --pe;
                        return *this;
                    }

                    iterator operator--(int) { 
                        iterator old { *this };
                        --pe;
                        return old; 
                    }   

                    bool operator==(const iterator& rhs) {
                        return this->pe == rhs.pe; 
                    }

                    bool operator!=(const iterator& rhs) {
                        return this->pe != rhs.pe; 
                    }
            };

            iterator begin() {
                return iterator(elems);
            }

            iterator end() {
                return iterator(elems+v_size);
            }

            iterator insert(const iterator& itr, const Element& e) {
                if (v_capacity == v_size)
                    reserve(2*v_capacity);
                iterator i = end(); 
                while (i != itr)
                    *i = *(--i);
                *itr = e;
                ++v_size;
            }

            iterator erase(const iterator&) {

            }

        private:
            Element* elems;
            std::size_t v_size;
            std::size_t v_capacity;
    };   

    class A {
        public:
            explicit A() = default;
            ~A() = default;
            A(const A&) {}
            A(A&&) {}
            A& operator=(const A&) { return *this; }
            A& operator=(A&&) { return *this; }
    };

} // namespace nameV

#endif
