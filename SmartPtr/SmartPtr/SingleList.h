#pragma once
#include "Node.h"
#include <iostream>
#include <string>
#include <memory>

template <typename Type>
class SingleList
{
	using linkPointer = typename Node<Type>::pointer;

private:

	linkPointer head = {};
	Node<Type>* tail = nullptr;

public:

	/*
	* @brief Пустой объект односвязного списка 
	*/
	SingleList();

	/*
	* @brief Деструктор
	*/
	~SingleList();

	/*
	* @brief Преобразование в строку 
	*/
	std::string toString() const noexcept;

	/*
	* @brief Вставка элемента
	*/
	void pushFront(const Type value);

	/*
	* @brief Показать весь список
	*/
	void show() const;

	/*
	* @brief Проверка наличия элементов в списке
	* @return true - есть элементы, иначе false
	*/
	bool hasElements() const noexcept;

	/*
	* @brief Проверка отсутствия элементов в списке
	* @return true - нет элементов, иначе false
	*/
	bool isEmpty() const noexcept;

	linkPointer getHead();
};

template <typename Type>
SingleList<Type>::SingleList()
	: head{ nullptr }
{
}

template <typename Type>
SingleList<Type>::~SingleList()
{
	while (head != nullptr)
	{
		head = std::move(head->next);
	}
}

template<typename Type>
std::string SingleList<Type>::toString() const noexcept
{
	std::stringstream buffer;
	auto current = head.get();
	while (head->next != nullptr)
	{
		buffer << current->data;
		current = current->next.get();
	}
	return buffer.str();
}

template<typename Type>
inline void SingleList<Type>::pushFront(Type value)
{
	auto newLink = new Node<Type>(std::move(value));
	if (tail != nullptr)
	{
		tail->next.reset(newLink);
	}
	else
	{
		head.reset(newLink);
	}
	tail = newLink;
}

template<typename Type>
bool SingleList<Type>::hasElements() const noexcept
{
	return (this->isEmpty);
}

template<typename Type>
bool SingleList<Type>::isEmpty() const noexcept
{
	return this->head == nullptr;
}

template<typename Type>
typename Node<Type>::pointer SingleList<Type>::getHead()
{
	return head;
}

template<typename Type>
void SingleList<Type>::show() const
{
	auto current = head.get();
	while (current != nullptr)
	{
		std::cout << current->data << std::endl;
		current = current->next.get();
	}
}
