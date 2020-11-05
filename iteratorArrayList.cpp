class ArrayList {
    public:
        int arr[10]; // backing array
        int size;    // number of elements that have been inserted

        // Iterator class
        class iterator : public std::iterator<std::forward_iterator_tag, int> {
            public:
                friend class ArrayList;  // declare Array List class as a friend class
                int* curr;               // the element this iterator is pointing to

                // the following typedefs are needed for the iterator to play nicely with C++ STL
                typedef int value_type;
                typedef int& reference;
                typedef int* pointer;
                typedef int difference_type;
                typedef std::forward_iterator_tag iterator_category;

                // iterator constructor
                iterator(int* x=0):curr(x){}
                
                // overload the == operator of the iterator class
                bool operator==(const iterator& x) const {
                    return curr == x.curr; // compare curr pointers for equality
                }

                // overload the != operator of the iterator class
                bool operator!=(const iterator& x) const {
                    return curr != x.curr; // compare curr pointers for inequality
                }

                // overload the * operator of the iterator class
                reference operator*() const {
                    return *curr;          // return curr's value
                }

                // overload the ++ (pre-increment) operator of the iterator class
                iterator& operator++() {
                    curr++;                // move to next slot of array
                    return *this;          // return after the move
                }

                // overload the ++ (post-increment) operator of the iterator class
                iterator operator++(int) {
                    iterator tmp(curr);    // create a temporary iterator to current element
                    curr++;                // move to next slot of array
                    return tmp;            // return iterator to previous element
                }
        };

        // return iterator to first element
        iterator begin() {
            return iterator(&arr[0]);
        }

        // return iterator to JUST AFTER the last element
        iterator end() {
            return iterator(&arr[size]);
        }
};
