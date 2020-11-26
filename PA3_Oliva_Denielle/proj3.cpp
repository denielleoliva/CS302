#include "BinarySearchTree.h"

#include <iostream>

void generateVals(BinarySearchTree<int> bst){

    for(int i = 0; i<100; i++){
        bst.add(rand()%200);
    }

}

int main(){
    BinarySearchTree<int> bst_one;

    generateVals(bst_one);

    return 0;
}