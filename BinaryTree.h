#ifndef BINARYTREE
#define BINARYTREE
#include<iostream>
#include<memory>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::make_unique;
using std::move;

namespace mpcs51044 {
    struct node
    {   
        /*node() :key_value(0), left(nullptr),right(nullptr) {};
        node(int i) :key_value(i), left(nullptr), right(nullptr) {};*/

        int key_value;
        unique_ptr<node> left;
        unique_ptr<node> right;
        void print() { cout << key_value << ". left: " << (left == nullptr) << ". right: " << (right == nullptr) <<endl; }
    };

    class btree
    {
    public:
        btree();
       /* ~btree();*/

        void insert(int key);
        unique_ptr<node> search(int key);
        /*void destroy_tree();*/
        int getRootValue() { return root->key_value; }

    private:
        /*void destroy_tree(unique_ptr<node> leaf);*/
        void insert(int key, unique_ptr<node>& leaf);
        unique_ptr<node> search(int key, unique_ptr<node>& leaf);

        unique_ptr<node> root;
    };

    btree::btree() { root = nullptr; }
   /* btree::~btree() { destroy_tree(); }*/


    //void btree::destroy_tree(unique_ptr<node> leaf)
    //{
    //    auto ele = move(leaf);
    //    if (ele != nullptr)
    //    {   
    //        cout << "deleting non-empty node.." << endl;
    //        destroy_tree(move(ele->left));
    //        destroy_tree(move(ele->right));
    //        //delete ele;
    //    }
    //    else {
    //        cout << "empty node reached" << endl;
    //    }
    //}

    //void btree::destroy_tree()
    //{
    //    destroy_tree(move(root));
    //}


    void btree::insert(int key, unique_ptr<node>& leaf)
    {
        cout << "inserting " << key << " at ";
        leaf->print();

        if (key < leaf->key_value)
        {
            if (leaf->left != nullptr)
                insert(key, leaf->left);
            else
            {
                leaf->left = make_unique<node>(); //new node;
                leaf->left->key_value = key;
                leaf->left->left = nullptr;    //Sets the left child of the child node to null
                leaf->left->right = nullptr;   //Sets the right child of the child node to null
            }
        }
        else if (key >= leaf->key_value)
        {
            if (leaf->right != nullptr)
                insert(key, leaf->right);
            else
            {
                leaf->right = make_unique<node>(); //new node;
                leaf->right->key_value = key;
                leaf->right->left = nullptr;  //Sets the left child of the child node to null
                leaf->right->right = nullptr; //Sets the right child of the child node to null
            }
        }
    }

    unique_ptr<node> btree::search(int key, unique_ptr<node>& leaf)
    {   
        cout << "searching for " << key << " at ";
        leaf->print();

        if (leaf != nullptr)
        {
            cout << "node is not nullptr" <<endl;
            if (key == leaf->key_value)
            {
                cout << "current node is what we were searching" << endl;
                return move(leaf);
            }
            else if (key < leaf->key_value)
            {
                cout << "current node has value bigger than what we were searching" << endl;
                return search(key, leaf->left);
            }
            else
            {   
                cout << "current node has value smaller than what we were searching" << endl;
                return search(key, leaf->right);
            }
        }
        else return nullptr;
    }


    void btree::insert(int key)
    {
        cout << "inserting " << key <<endl;

        if (root != nullptr) 
        {
            cout << "root is not nullptr" << endl;
            insert(key, root);
        }
        else
        {   
            cout << "root is nullptr" << endl;
            root = make_unique<node>();
            root->key_value = key;
            root->left = nullptr;
            root->right = nullptr;
        }
    }

    unique_ptr<node> btree::search(int key)
    {   
        cout << "searching for " << key <<endl;
        return search(key, root);
    }

    
}
#endif // !1

#pragma once
