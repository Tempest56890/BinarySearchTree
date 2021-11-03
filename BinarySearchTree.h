// copyright:no copyright,use it if you like
// license boilerplate:maybe BSD
// filename:BinarySearchTree.h
// author:Tempest(https://gitee.com/Tempest56890)
// date:2021-11-01
// brief:implement the function of BinarySearchTree

#ifndef __TEMPEST_BINARYSEARCHTREE__
#define __TEMPEST_BINARYSEARCHTREE__

#include <iostream>

template <typename Comparable>
// implement the funciton of BinarySearchTree.
// example:
//    (Temporarily omitted.)
class BinarySearchTree {
public:
    // BST constructor.
    BinarySearchTree ()
    :root(nullptr) {};
    // deep copy to construct a BST.
    BinarySearchTree(const BinarySearchTree & rhs )
    :root(nullptr) {
        root=clone(rhs.root);
    };
    // BST destructor.
    ~BinarySearchTree () {
        makeEmpty();
    };
    // transmit the root pointer to private function of
    // same name,and give a minimum by recursion.
    const Comparable & findMin() const {
        return findMin(root)->element;
    };
    // transmit the root pointer to private function of
    // same name,and give a maximum by recursion.
    const Comparable & findMax() const {
        return findMax(root)->element;
    };
    // transmit the root pointer to private function of
    // same name,and give a bool result by recursion.
    bool contains(const Comparable & x) const {
        return contains(x,root);
    };
    // judge if the BST is empty.
    bool isEmpty() const {
        if (root==nullptr)
            return true;
        return false;
    };
    // transmit the root pointer to private function of
    // same name,and print BST by recursion.
    void printTree() const {
        if (isEmpty())
	    std::cout<<"It's empty."<<std::endl;
        else
            printTree(root,0);
    };
    // transmit the root pointer to private function of
    // same name,and delete BST's node by recursion.
    void makeEmpty () {
        makeEmpty(root);
    };
    // transmit the root pointer to private function of
    // same name,and insert x according to its relative
    // size by recursion.
    void insert(const Comparable & x) {
        insert(x,root);
    };
    // transmit the root pointer to private function of
    // same name,find and remove x according to its relative
    // size by recursion.
    void remove(const Comparable & x) {
        remove(x,root);
    };
    // overloads operator = for class object to deep copy.
    // return:a const pointer to the current object
    // the reference parameter rhs has to be maintained and
    // released when function ends.
    // the parameter can be a null pointer.
    const BinarySearchTree & operator=( const BinarySearchTree & rhs) {
        if (this!=&rhs) {
            makeEmpty();
            root=clone(rhs.root);
        }
        return *this;
    };
    
private:
    // construct a BST struct.
    // provide a funciton to initialize a node.
    struct BinaryNode {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;
        BinaryNode(const Comparable & theElement,BinaryNode*lt,BinaryNode*rt)
        : element(theElement),left(lt),right(rt) {}
    };
    BinaryNode *root;
    // i/o param:x/t
    // function call insert().
    void insert(const Comparable & x,BinaryNode * & t ) const {
        if (t==nullptr)
            t=new BinaryNode(x,nullptr,nullptr);
        else if (x<t->element)
            insert(x,t->left);
        else if (t->element<x)
            insert(x,t->right);
        else
            ;
    };
    // i/o param:x/t
    // function call remove().
    // the oldNode rhs has to be maintained and
    // released when function ends.
    void remove(const Comparable & x,BinaryNode* & t) const {
        if (t==nullptr) return;
        if (x<t->element) {
            remove(x,t->left);
        }
        else if (t->element<x) {
            remove(x,t->right);
        }
        else if (t->left!=nullptr && t->right!=nullptr) {
            t->element=findMin(t->right)->element;
            remove(t->element,t->right);
        }
        else {
            BinaryNode *oldNode=t;
            t=(t->left!=nullptr)?t->left : t->right;
            delete oldNode;
        }
    };
    // i/o param:t
    // function call findMin().
    BinaryNode * findMin(BinaryNode*t) const {
        if (t==nullptr)
            return nullptr;
        if (t->left==nullptr)
            return t;
        return findMin(t->left);
    };
    // i/o param:t
    // function call findMax().
    BinaryNode * findMax(BinaryNode*t) const {
        if (t!=nullptr)
            while (t->right!=nullptr)
                t=t->right;
        return t;
    };
    // i/o param:x/t
    // function call contains().
    bool contains(const Comparable & x,BinaryNode *t ) const {
        if (t==nullptr)
            return false;
        else if (x<t->element)
            return contains(x,t->left);
        else if (t->element<x)
            return contains(x,t->right);
        else
            return true;
    };
    // i/o param:t
    // function call makeEmpty().
    void makeEmpty( BinaryNode * & t ) {
        if (t!=nullptr) {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t=nullptr;
    };
    // i/o param:t/count(=0)
    // function call insert().
    // a node's depth would embodied the size
    // of space ahead of itself.
    void printTree(BinaryNode * t ,int count=0) const {
        int count1=count;
        if (t==nullptr)
            return;
        for(int i=0;i<count1;i++) {
            std::cout<<" ";
        }
        std::cout<<t->element<<std::endl;
        count1=count1+1;
        printTree(t->left,count1);
        printTree(t->right,count1);
    };
    // i/o param:x/t
    // return:a new cloned BST.
    // function call clone().
    BinaryNode * clone( BinaryNode * t) const {
        if (t==nullptr)
            return nullptr;
        return new BinaryNode(t->element,clone(t->left),clone(t->right));
    };
};

#else
#endif
