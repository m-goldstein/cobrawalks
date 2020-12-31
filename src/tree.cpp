#include "tree.h"
/* Node class implementation */
Node::Node()
{
    parent = NULL;
    children.clear();
    infected = false;
}
Node::Node(bool _infected, int _level, Node* _parent)
{
    infected = _infected;
    this->level = _level;
    parent = _parent;
    children.clear();
}
Node::~Node()
{
    parent = NULL;
    children.clear();
    infected = false;
}
int Node::infect_neighbor() 
{
    /* choose a random child or parent and infect */
    for (int i = 0; i < K; i++) {

	unsigned int rand_seed = std::chrono::system_clock::now().time_since_epoch().count();
	int rand;
	std::minstd_rand0 generator(rand_seed);
	rand = generator() % (N +1);
	cout << rand << endl;
    }

}
bool Node::is_infected()
{
    return infected;
}
void Node::infect()
{
    infected = true;
}
void Node::set_parent(Node* _parent)
{
    if (_parent == NULL)
	return;
    parent = _parent;
}
Node* Node::get_parent() 
{
    if (parent == NULL)
	return NULL;
    return parent;
}
vector<Node*> Node::get_children()
{
    return children;
}
void Node::set_children(vector<Node*>_children)
{
    children = _children;
}


/* tree class implementation */
Tree::Tree()
{
    root = NULL;
    depth = 0;
}
Tree::Tree(Node* _root)
{
    root = _root;
    depth = 0;
}
Tree::~Tree()
{
    delete root;
}
Node* Tree::make_root()
{
    if (root == NULL) {
	root = new Node();
    }
    return root;
}

void Tree::add_levels()
{
    int count = 0;
    vector<Node*> visited;
    queue<Node*> frontier;
    if (root == NULL) {
	root = make_root();
	count++;
	depth = 0;
    }
    frontier.emplace(root);
    while (!frontier.empty() && depth < MAX_TREE_DEPTH) {	

	count++;
	Node* current = frontier.front();
	frontier.pop();
	for (int i = 0; i < N; i++) {
	    current->children.push_back(new Node(false, depth+1, NULL));
	}
	for (auto it : current->children) {
	    frontier.push(it);
	}
	if (count >= ((pow(N, depth+1))-1)/(N-1)) {
	    depth++;
	}
	visited.push_back(current);
    }
    cout << "Depth: "<< depth <<"# Nodes:" <<count << endl;
}


void Tree::add_level()
{ // add a level to the tree where its n^level-1 nodes in tree.
    if (this->root == NULL) {
	this->root = this->make_root();
	depth = 0;
	for (int i = 0; i < N; i++) {
	    root->children.push_back(new Node( false, depth+1, NULL));
	}
	current = root;
    } else {
	for (int i = 0; i < N; i++) {
	    current->children.push_back(new Node( false, depth+1, this->root));
	}

	this->depth++;
    }
}
void Node::print_node(Node* node)
{
    cout << infected << endl;
}
void Tree::print_tree_helper(Node* node) {
    if (node == NULL)
	return;

    for (auto it : node->children) {
	print_tree_helper(it);
    }
    node->print_node(node);
}
void Tree::print_tree()
{
    print_tree_helper(root);
    //prints tree. trivial.
}

Simulation::Simulation()
{
    k = 0;
    clk = 0;
    tree = NULL;
}
Simulation::Simulation(Tree* _tree, int _k)
{
    tree = _tree;
    k = _k;
    clk = 0;
}
void Simulation::do_timestep()
{
    clk += 1;
    // infect nodes. repeat. implement later. 
}
