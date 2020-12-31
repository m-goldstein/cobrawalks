#include "tree.h"
int main()
{
    Tree* tree = new Tree();
    tree->make_root();
    tree->root->infect_neighbor();
    tree->add_levels();
    tree->print_tree();
    return 0;
}
