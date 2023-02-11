//#include <iostream>
//#include <memory>
//
//using std::make_unique;
//using std::unique_ptr;
//
//template <typename T>
//class Tree {
//
//    struct Node {
//        Node(const T& value)
//            : value(value), left(nullptr), right(nullptr) {}
//
//        T value;
//        unique_ptr<Node> left;
//        unique_ptr<Node> right;
//    };
//
//public:
//    Tree() : root_(nullptr) {}
//
//    // Insert a value into the tree
//    void Insert(const T& value) {
//        Insert(root_, value);
//    }
//
//    // Delete a value from the tree
//    bool Delete(const T& value) {
//        return Delete(root_, value);
//    }
//
//    // Search the tree for a node and return true if it is found
//    bool Contains(const T& value) const {
//        return Contains(root_, value);
//    }
//
//private:
//    void Insert(unique_ptr<Node>& node, const T& value) {
//        if (not node) {
//            node = make_unique<Node>(value);
//        }
//        else {
//            value < node->value
//                ? Insert(node->left, value)
//                : Insert(node->right, value);
//        }
//    }
//
//    bool Delete(unique_ptr<Node>& node, const T& value) {
//        if (not node) {
//            return false;
//        }
//        else if (value == node->value) {
//            if (node->left) {
//                unique_ptr<Node>& right = node->right;
//                node = move(node->left);
//                if (right) {
//
//                    // Need to use a raw pointer because I can't assign to a std::unique_ptr
//                    Node* n = node.get();
//                    while (n->right) {
//
//                        // Using a reference to a unique_ptr instead of a raw pointer will cause this line to fail to compile
//                        n = n->right.get();
//                    }
//                    n->right = move(right);
//                }
//            }
//            else {
//                node = move(node->right);
//            }
//            return true;
//        }
//        else {
//            return value < node->value
//                ? Delete(node->left, value)
//                : Delete(node->right, value);
//        }
//    }
//
//    bool Contains(const unique_ptr<Node>& node, const T& value) const {
//        if (not node) {
//            return false;
//        }
//        else if (node->value == value) {
//            return true;
//        }
//        else {
//            return value < node->value
//                ? Contains(node->left, value)
//                : Contains(node->right, value);
//        }
//    }
//
//    unique_ptr<Node> root_;
//};