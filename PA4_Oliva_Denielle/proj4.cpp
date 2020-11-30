#include <iostream>

#include "LeftLeaningRedBlack.h"

const int MIN_VAL = 1;
const int MAX_VAL = 100;

int randNumGenerator(const int min, const int max);

int main(){
    LeftLeaningRedBlack tree;

    for(int i = 0; i<10; i++){
        LLTB_t newNode;
        newNode.Ref.Key = randNumGenerator(MIN_VAL, MAX_VAL);

        if(i%4==0&&i!=0){
            tree.Delete(newNode.Ref.Key);
            std::cout<<"\nDelete Element "<<i<<": "<<newNode.Ref.Key;
            i++;
            newNode.Ref.Key = randNumGenerator(MIN_VAL, MAX_VAL);
        }

        tree.Insert(newNode.Ref);

        std::cout<<"\nInsert "<<i<<": "<<newNode.Ref.Key;

        if(newNode.IsRed){
            std::cout<<"::RED";
        }else{
            std::cout<<"::BLACK";
        }

        LLTB_t *parent = tree.findParent(newNode.Ref);

        if(parent!=nullptr){
            std::cout<<"\nParent: "<<parent->Ref.Key;

            if(!(parent->IsRed)){
                std::cout<<"::BLACK";
            }else{
                std::cout<<"::RED";
            }
        }

    }

}

int randNumGenerator(const int min, const int max){
    int difference = max - min;
    return (rand()%difference)+min;
}