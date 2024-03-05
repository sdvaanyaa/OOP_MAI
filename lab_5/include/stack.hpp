#pragma once

#include <iostream>
#include <memory>

template <class T, class ALLOCATOR>
class Stack
{
private:
    struct stack_node
    {
        T data;
        stack_node* next;

        stack_node() noexcept : data(), next(nullptr){};
        explicit stack_node(const T &elem) noexcept : data(elem), next(nullptr) {}

        explicit operator T(){
            return data;
        }

        friend std::ostream &operator<<(std::ostream &out, const stack_node &node)
        {
            out << node.data;
            return out;
        }
    };

    using allocator_type = typename ALLOCATOR::template rebind<stack_node>::other;

    struct allocator
    {
        allocator_type stack_node_allocator;

        allocator() : stack_node_allocator(){};
        allocator(allocator_type *another_allocator) : stack_node_allocator(another_allocator) {}

    };

    stack_node* top_node;
    allocator stack_allocator;
    std::size_t _size {0};

public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = std::size_t;

    Stack() noexcept : top_node(){};

    class iterator {
	private:
		stack_node* ptr;
	public:
		using iterator_category = std::forward_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = T;
		using pointer = T*;
		using reference = T&;
		using const_reference = const T&;

		iterator() : ptr(nullptr) {}
		iterator(stack_node* another_ptr) : ptr(another_ptr) {}

		bool is_null() const {
			return ptr == nullptr;
		}

		void unvalidate() {
			ptr = nullptr;
		}

		iterator & operator++ () {
			if (!is_null()) {
				ptr = ptr->next;
				return *this;
			} 
            else {
				throw std::logic_error("iterator: trying to increment points to nullptr");
			}
		}

		bool operator != (const iterator & other_iterator) {
			return &other_iterator.ptr->data != &this->ptr->data;
		}

		bool operator == (const iterator & other_iterator) {
			return &other_iterator.ptr->data == &this->ptr->data;
		}

		friend std::ostream & operator << (std::ostream & out, const iterator & it){
            if (it.is_null()) {
                throw std::logic_error("iterator: error dereference the pointer");
            } 
			out << *(it.ptr);
			return out;
		}

		T operator* () {
            if (is_null()) {
                throw std::logic_error("iterator: error dereference the pointer");
            }
			return T(*ptr);
		}
	};

    void pop()
    {
        if (top_node)
        {
            stack_node* next = top_node->next;
            stack_allocator.stack_node_allocator.deallocate(top_node, 1);
            top_node = next;
            _size--;
        }
        else
        {
            throw(std::runtime_error("Stack is empty!"));
        }
    }

    void push(const T &elem)
    {
        stack_node *new_node = stack_allocator.stack_node_allocator.allocate(1);

        stack_allocator.stack_node_allocator.construct(new_node, elem);

        new_node->next = top_node;
        top_node = new_node;

        _size++;
    }

    T top() const 
    {
        if (top_node)
        {
            return top_node->data;
        }
        else
        {
            throw(std::runtime_error("Stack is empty!"));
        }
    }

    size_t size() const 
    {
        return _size;
    }

    iterator begin() const
    {
        return iterator(top_node);
    }

    iterator end() const
    {
        return iterator(nullptr);
    }
};

