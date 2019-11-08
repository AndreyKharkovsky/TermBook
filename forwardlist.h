#ifndef FORWARDLIST_H
#define FORWARDLIST_H

#include <memory>
#include <iterator>

template <typename T>
class ForwardList {
// typedefs
public:
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using pointer = T *;
private:
    struct Node {
        T data_{};
        std::shared_ptr<Node> next_;

        Node (T && data, std::shared_ptr<Node> next): data_{std::forward<T>(data)}, next_{std::move(next)} {}
        Node (const T & data, std::shared_ptr<Node> next): data_{data}, next_{std::move(next)} {}

        // Delegate
        Node(): Node{T{}, nullptr} {}

        ~Node() { std::cout << "Dtor for " << data_ << '\n'; }
    };
    using Link = std::shared_ptr<Node>;
// Other
public:

    class ForwardList_iterator
    {
    //typedefs
    public:
        using difference_type = std::ptrdiff_t;
        using value_type = ForwardList::value_type;
        using pointer = ForwardList::pointer;
        using referenece = ForwardList::reference;
        using iteretor_category = std::forward_iterator_tag;
    public:
        ForwardList_iterator(Link p) : ptr_(p) {}

        ForwardList_iterator(const ForwardList_iterator& it) : ptr_(it.ptr_) {}
        bool operator == (const ForwardList_iterator& rhs) const {return ptr_ == rhs.ptr_;}
        bool operator !=(const ForwardList_iterator& rhs) const {return !(*this == rhs);}
        ForwardList_iterator& operator ++() {ptr_ = ptr_->next_; return *this;}
        ForwardList_iterator operator ++(int) {ForwardList_iterator tmp(*this); ++(*this); return tmp;}
        reference operator *() {return ptr_->data_;}
    private:
        Link ptr_;
    };



    ForwardList(): link_{nullptr}, size_{0} {}

    ForwardList(std::initializer_list<T> lst) {
        for (const T & elem: lst) {
            push_front(elem);
        }
    }

    ~ForwardList() noexcept = default;

    void push_front(const T & data) {
        link_ = std::make_shared<Node>(data, std::move(link_));
        ++size_;
    }

    void push_front(T && data) {
        link_ = std::make_shared<Node>(std::forward<T>(data), std::move(link_));
        ++size_;
    }

    [[nodiscard]] const_reference top() const noexcept { return link_->data_; }
    [[nodiscard]] reference       top()       noexcept { return link_->data_;}

    void pop() {
        if (link_) {
            link_ = std::move(link_->next_);
            --size_;
        }
    }
    [[nodiscard]] bool        empty() const noexcept { return link_ == nullptr; }
    [[nodiscard]] std::size_t size()  const noexcept { return size_; }

    ForwardList_iterator begin() {
        return ForwardList_iterator(link_);
    }

    ForwardList_iterator end() {
        return ForwardList_iterator(nullptr);
    }



private:
    Link link_;
    std::size_t size_{};
};


//namespace std {
//    template <>
//    template <typename T>
//    struct iterator_traits<typename ForwardList<T>::ForwardList_iterator> {

//    };
//}





#endif // FORWARDLIST_H
