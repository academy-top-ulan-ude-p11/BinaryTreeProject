#include <iostream>
#include "BinaryTree.h"

int main()
{
    BinaryTree tree;
    tree.AddLoop(6);
    tree.AddLoop(9);
    tree.AddLoop(12);
    tree.AddLoop(10);
    tree.AddLoop(15);
    tree.AddLoop(4);
    tree.AddLoop(3);
    tree.AddLoop(5);
    tree.AddLoop(8);

    tree.Print();
    std::cout << "\n";

    
    tree.Delete(tree.Search(6));

    tree.Print();
    std::cout << "\n";
    //std::cout << tree.Value(tree.Min(tree.Search(7))) << "\n";
}
