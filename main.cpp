#include "BinarySearchTree.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

template <typename T>
// normal sort function.
// i/o param:_data
// input the elments into BST and
// medium order traversal.
// print the sorted vertor.
void BST_sort(vector<T> &_data) {
    BinarySearchTree<T> tree;
    for (int i=0;i<_data.size();++i) {
        tree.insert(_data[i]);
    }
    _data.clear();
    cout<<"Now BST is like this :"<<endl;
    tree.printTree();
    while (!tree.isEmpty()) {
        _data.push_back(tree.findMin());
        tree.remove(tree.findMin());
    }
};

template <typename T>
// random sort function.
// i/o param:_data
// shuffle the vector initially.
// print the shuffled vector.
// input the elments into BST and
// medium order traversal.
// print the sorted vertor.
void Randomized_BST_sort(vector<T> &_data) {
    BinarySearchTree<T> tree;
    random_device rd;
    mt19937 generator(rd());
    shuffle(_data.begin(),_data.end(),generator);
    cout<<"After shuffler, the vector :"<<endl;
    for (int i=0;i<_data.size();++i) {
        cout<<(_data[i])<<" ";
        tree.insert(_data[i]);
    }
    cout<<endl;
    _data.clear();
    cout<<"Now BST is like this :"<<endl;
    tree.printTree();
    while (!tree.isEmpty()) {
        _data.push_back(tree.findMin());
        tree.remove(tree.findMin());
    }
};

template <typename T>
// print vector.
// i/o param:_data
void printVector(vector<T> &_data) {
    if (_data.size()==0) {
        cout<<"The vector is empty."<<endl;
    }
    else {
        cout<<"Now vector is like this :"<<endl;
        for (int i=0;i<_data.size();++i) {
            cout<<(_data[i])<<" ";
        }
        cout<<endl;
    }
};

int main() {
    int sys,n,ele,sort;vector<int> vec;
    cout<<"0:exit / 1:clear / 2:push / 3:sort / 4:print"<<endl;
    while (cin>>sys&&sys) {
        if (sys==1) {
            vec.clear();
        }
        else if (sys==2) {
            cout<<"Please input the number of elements waiting to be push_back:"<<endl;
            cin>>n;
            cout<<"now input elements :";
            while (n--) {
                cin>>ele;
                vec.push_back(ele);
            }
            printVector(vec);
        }
        else if (sys==3) {
            printVector(vec);
            cout<<"use normal sort or ramdom sort? input 1 or 2 :";
            cin>>sort;
            if (sort==1) {
                BST_sort(vec);
            }
            else {
                Randomized_BST_sort(vec);
            }
            printVector(vec);
        }
        else if (sys==4) {
            printVector(vec);
        }
    }
    cout<<"Thanks for testing."<<endl;
};
