#pragma once
#include <memory>
template <typename Type>

struct Node
{
public:
	using pointer = std::unique_ptr<Node>;

	Type data;
	pointer next;
	Node(Type value) : data{ std::move(value) }, next{ nullptr } {};
};
