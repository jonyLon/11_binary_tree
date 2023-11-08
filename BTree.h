#pragma once
using namespace std;

template<typename T>
struct Node
{
	T data;
	Node* parent, * left, * right;
	Node(const T& data = T(), Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr) : data{ data }, left{ left }, parent{ parent }, right{ right } 
	{
	}
};



template<typename T>
class BTree
{
public:
	BTree() = default;
	~BTree() {
		clear();
	}
	void add(const T& data);
	void print() const;
	bool isEmpty() const;
	T min() const;
	T max() const;
	bool find(const T& data) const;
	void removeSubTree(const T& data);
	void clear();
	void printRange(const T& left, const T& right);
private:
	Node<T>* root = nullptr;
	size_t size = 0;
	void printRangeHelper(Node<T>* node, const T& left, const T& right) const;
	void helperPrint(Node<T>* node) const;
	void helperClear(Node<T>* node);
	Node<T>* findPtr(const T& data) const;
};

template<typename T>
inline void BTree<T>::add(const T& data)
{
	Node<T>* newNode = new Node<T>(data);
	size++;
	if (isEmpty()) {
		root = newNode;
		return;
	}
	auto tmp = root;
	while (true)
	{
		if (newNode->data < tmp->data) {
			if (tmp->left == nullptr) {
				tmp->left = newNode;
				newNode->parent = tmp;
				break;
			}
			tmp = tmp->left;
		}
		else {
			if (tmp->right == nullptr) {
				tmp->right = newNode;
				newNode->parent = tmp;
				break;
			}
			tmp = tmp->right;
		}
	}

}

template<typename T>
inline void BTree<T>::print() const
{
	if (isEmpty()) {
		cout << "Empty" << endl;
		return;
	} 
	cout << "Binary Tree:\t";
	helperPrint(root);
	cout << endl;
}

template<typename T>
inline bool BTree<T>::isEmpty() const
{
	return root == nullptr;
}

template<typename T>
inline T BTree<T>::min() const
{
	auto tmp = root;
	while (tmp->left != nullptr)
	{
		tmp = tmp->left;
	} return tmp->data;
}

template<typename T>
inline T BTree<T>::max() const
{
	auto tmp = root;
	while (tmp->right != nullptr)
	{
		tmp = tmp->right;
	} return tmp->data;
}

template<typename T>
inline bool BTree<T>::find(const T& data) const
{
	auto tmp = root;
	while (tmp != nullptr)
	{
		if (tmp->data == data) {
			return true;
		}
		if (tmp->data > data) {
			tmp = tmp->left;
		}
		else {
			tmp = tmp->right;
		}
	}
	return false;
}

template<typename T>
inline void BTree<T>::removeSubTree(const T& data)
{
	Node<T>* parent = nullptr;
	Node<T>* ptr = findPtr(data);
	if (ptr != nullptr) {
		parent = ptr->parent;
		helperClear(ptr);
		if (parent) {
			if (parent->left == ptr) parent->left = nullptr;
			else if (parent->right == ptr) parent->right = nullptr;
		}
		else root = nullptr;
	}
}

template<typename T>
inline void BTree<T>::clear()
{
	helperClear(root);
	root = nullptr;
}

template<typename T>
inline void BTree<T>::printRange(const T& left, const T& right)
{
	printRangeHelper(root, left, right);
	cout << endl;
}


template<typename T>
inline void BTree<T>::printRangeHelper(Node<T>* node, const T& left, const T& right) const
{
	if (node != nullptr) {
		printRangeHelper(node->left, left, right);
		if(node->data > left && node->data < right) cout << node->data << "\t";
		printRangeHelper(node->right, left, right);
	}
}

template<typename T>
inline void BTree<T>::helperPrint(Node<T>* node) const
{
	if (node != nullptr)
	{
		helperPrint(node->left);
		cout << node->data << "\t";
		helperPrint(node->right);
	}
}

template<typename T>
inline void BTree<T>::helperClear(Node<T>* node)
{
	if (node != nullptr)
	{
		helperClear(node->left);
		helperClear(node->right);
		delete node;
		--size;
	}
}

template<typename T>
inline Node<T>* BTree<T>::findPtr(const T& data) const
{
	auto tmp = root;
	while (tmp != nullptr)
	{
		if (tmp->data == data) {
			return tmp;
		}
		if (tmp->data > data) {
			tmp = tmp->left;
		}
		else {
			tmp = tmp->right;
		}
	}
	return nullptr;
}


