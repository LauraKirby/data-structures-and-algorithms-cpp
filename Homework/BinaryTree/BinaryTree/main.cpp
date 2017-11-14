//
//  main.cpp
//  BinaryTree
//
//  Created by Laura Kirby on 10/25/17.
//  Copyright © 2017 LK. All rights reserved.
//

#include <iostream>
#include "BST.h"
#include "BinNode.h"
#include "BSTNode.h"
#include "dictionary.h"
#include "book.h"

using namespace std;

int main(int argc, const char * argv[]) {

    BST<int, Int*> tree;

    cout << "Size: " << tree.size() << "\n";

    tree.insert(100, new Int(100));

    tree.print();

    cout << "Size: " << tree.size() << "\n";

//    int height = tree.height();
//    cout << "Height: " << tree.height() << "\n";

    tree.postOrder();
    return 0;
}
