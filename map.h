#pragma once
#include "pair.h"

namespace mylib
{
	enum class ColorType
	{
		RED, BLACK
	};
	template<typename _T1, typename _T2>
	struct RBTree
	{
		RBTree* parent_node = nullptr;
		RBTree* left_child = nullptr;
		RBTree* right_child = nullptr;
		ColorType color_type = ColorType::RED;
		Pair<_T1, _T2> value;
		RBTree(RBTree<_T1, _T2>* parent, RBTree<_T1, _T2>* left, RBTree<_T1, _T2>* right, const ColorType color, Pair<_T1, _T2>& v)
		{
			parent_node = parent;
			left_child = left;
			right_child = right;
			color_type = color;
			value = v;
		}
		RBTree() {}
	};

	template<typename _T1, typename _T2>
	class Map
	{
	public:
		Map() {}
		Map(const Map& other) {}
		Map(Map&& other) noexcept {}

		RBTree<_T1, _T2>* insert(const _T1 &key, const _T2 &value)
		{
			RBTree<_T1, _T2>* y = nullptr;
			RBTree<_T1, _T2>* x = root_;
			RBTree<_T1, _T2>* node = new RBTree<_T1, _T2>;
			node->value = Pair<_T1, _T2>(key, value);
			while (x != nullptr)
			{
				y = x;
				if (x->value.first_ < key)
					x = x->right_child;
				else if (x->value.first_ > key)
					x = x->left_child;
				else
					return node;
			}
			node->parent_node ? node->parent_node = y : nullptr;
			if (!y)
				root_ = node;
			else if (key < y->value.first_)
				y->left_child = node;
			else if (key > y->value.first_)
				y->right_child = node;

			node->parent_node = y;
			node->left_child = nullptr;
			node->right_child = nullptr;
			node->color_type = ColorType::RED;
			fixup(node);

			return node;
		}

		_T2& operator[](const _T1 &key)
		{
			RBTree<_T1, _T2>* node = root_;
			while (node)
			{
				if (node->value.first_ == key)
					break;
				if (node->value.first_ > key)
				{
					if (node->left_child)
					{
						node = node->left_child;
					}
					else
					{
						break;
					}
				}
				else
				{
					if (node->right_child)
					{
						node = node->right_child;
					}
					else
						break;
				}
			}
			if (node->value.first_ == key)
			{
				return node->value.second_;
			}
			_T2 value;
			return insert(key, value)->value.second_;
		}

	private:
		void rotate_left(RBTree<_T1, _T2>* node)
		{
			RBTree<_T1, _T2>* x = node->right_child;
			node->right_child = x->left_child;
			if (x->left_child) x->left_child->parent_node = node;
			x->parent_node = node->parent_node;

			if (!node->parent_node) root_ = x;
			else if (node->parent_node ? node == node->parent_node->left_child : false) node->parent_node->left_child = x;
			else node->parent_node ? node->parent_node->right_child = x : nullptr;

			x->left_child = node;
			node->parent_node = x;
		}

		void rotate_right(RBTree<_T1, _T2>* node)
		{
			RBTree<_T1, _T2>* x = node->left_child;
			node->left_child = x->right_child;
			if (x->right_child) x->right_child->parent_node = node;
			x->parent_node = node->parent_node;

			if (!node->parent_node) root_ = x;
			else if (node == node->parent_node->right_child) node->parent_node->right_child = x;
			else node->parent_node->left_child = x;

			x->right_child = node;
			node->parent_node = x;
		}

		void fixup(RBTree<_T1, _T2>* node)
		{
			while (node->parent_node ? node->parent_node->color_type == ColorType::RED : false)
			{
				if (node->parent_node->parent_node)
				{
					if (node->parent_node == node->parent_node->parent_node->left_child)
					{
						RBTree<_T1, _T2>* y = node->parent_node->parent_node->right_child;
						if (y->color_type == ColorType::RED)
						{
							node->parent_node->color_type = ColorType::BLACK;
							y->color_type = ColorType::BLACK;
							node->parent_node->parent_node->color_type = ColorType::RED;
							node = node->parent_node->parent_node;
						}
						else if (node == node->parent_node->right_child)
						{
							node = node->parent_node;
							rotate_left(node);
						}
						node->parent_node->color_type = ColorType::BLACK;
						node->parent_node->parent_node->color_type = ColorType::RED;
						rotate_right(node->parent_node->parent_node);
					}
					else
					{
						if (node->parent_node == node->parent_node->parent_node->right_child)
						{
							RBTree<_T1, _T2>* y = node->parent_node->parent_node->left_child;
							if (y ? y->color_type == ColorType::RED : false)
							{
								node->parent_node->color_type = ColorType::BLACK;
								y->color_type = ColorType::BLACK;
								node->parent_node->parent_node->color_type = ColorType::RED;
								node = node->parent_node->parent_node;
							}
							else if (node == node->parent_node->left_child)
							{
								node = node->parent_node;
								rotate_right(node);
							}
							if (node->parent_node)
							{
								node->parent_node->color_type = ColorType::BLACK;
								if (node->parent_node->parent_node)
								{
									node->parent_node->parent_node->color_type = ColorType::RED;
									rotate_left(node->parent_node->parent_node);

								}
							}
						}
					}
				}
				else
					break;
			}
			root_->color_type = ColorType::BLACK;
		};

		RBTree<_T1, _T2>* root_ = nullptr;
	};
}
