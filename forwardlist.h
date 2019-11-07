#ifndef FORWARDLIST_H
#define FORWARDLIST_H

#include <memory>
#include <iterator>

template<typename ValueType>
class ForwardList_iterator;

template <typename T>
class ForwardList {
// typedefs
public:
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using pointer = T *;
	using iterator = ForwardList_iterator<T>;
// Other
public:
    ForwardList(): link_{nullptr}, size_{0} {}

    ForwardList(std::initializer_list<T> lst) {
        for (const T & elem: lst) {
            push_front(elem);
        }
    }

    ~ForwardList() noexcept = default;

    void push_front(const T & data) {
        link_ = std::make_unique<Node>(data, std::move(link_));
        ++size_;
    }

    void push_front(T && data) {
        link_ = std::make_unique<Node>(std::forward<T>(data), std::move(link_));
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

	[[nodiscard]] iterator begin() {
		return iterator(link_);
	}

	[[nodiscard]] iterator end() {
		Link end = nullptr;
		for (auto i = link_; i != nullptr; i = i.next_) {
			end = i;
		}

		return iterator(end);
	}

private:
    struct Node {
        T data_{};
        std::unique_ptr<Node> next_;

        Node (T && data, std::unique_ptr<Node> next): data_{std::forward<T>(data)}, next_{std::move(next)} {}
        Node (const T & data, std::unique_ptr<Node> next): data_{data}, next_{std::move(next)} {}

        // Delegate
        Node(): Node{T{}, nullptr} {}

        ~Node() { std::cout << "Dtor for " << data_ << '\n'; }
    };
    using Link = std::unique_ptr<Node>;

    Link link_;
    std::size_t size_{};
};

template<typename ValueType>
class ForwardList_iterator : public std::iterator<std::input_iterator_tag, ValueType>
{
	template <typename T>
	friend class ForwardList;
private:
	ForwardList_iterator(ValueType* p) : p(p) {}
public:
	ForwardList_iterator(const ForwardList_iterator& it) : p(it.p) {}

	bool operator!=(ForwardList_iterator const& other) const {
		return p != other.p;
	}

	bool operator==(ForwardList_iterator const& other) const {
		return p == other.p;
	}
	typename ForwardList_iterator::reference operator*() const {
		return *p;
	}
	ForwardList_iterator& operator++() {
		++p;
		return *this;
	}
private:
	ValueType* p;
};
#endif // FORWARDLIST_H
