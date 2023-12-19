#pragma once

#include <cstddef>

template<typename T>
class Node {
public:
	T item;

	Node<T> *prev = nullptr;
	Node<T> *next = nullptr;

	Node(const T &item) noexcept
		: item(item) {}
};

template<typename T>
class LinkedList {
public:
	// add items

	void append(const T &item) noexcept {
		this->length++;

		Node<T> *const node = new Node<T>(item);

		if (this->length == 0) {
			this->head = node;
			this->tail = node;

			return;
		}

		node->prev = this->tail;
		this->tail->next = node;

		this->tail = node;
	}

	// remove items

	void pop() noexcept {
		this->length--;

		this->tail = this->tail->prev;
		delete this->tail->next;
		this->tail->next = nullptr;
	}

	// getters

	inline size_t getLength() const noexcept {
		return this->length;
	}

	~LinkedList() noexcept {
		Node<T> *curr = this->head;
		Node<T> *next;

		while (curr != nullptr) {
			next = curr->next;
			delete curr;
			curr = next;
		}
	}
private:
	size_t length = 0;

	Node<T> *head = nullptr;
	Node<T> *tail = nullptr;
};
