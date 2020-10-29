#include <iostream>
#include <random>
#include <algorithm>

//#include "BinaryNode.h"
//#include "BinaryNodeTree.h"
#include "BinarySearchTree.h"
//#include "BinaryTreeInterface.h"

using namespace std;

void generateVals(BinarySearchTree<int> one, int maxVals);

int main(){
    BinarySearchTree<int> bst_one;

    generateVals(bst_one,  100);

    cout<<"Height of tree: "<<bst_one.getHeight()<<endl;
    cout<<endl;
    bst_one.inorderTraverse();
    cout<<endl<<endl;
    
    return 0;

}

void generateVals(BinarySearchTree<int> one, int maxVals){
    
    for(int i = 0; i<maxVals;i++){
        one.add(rand()%200);
    }

}