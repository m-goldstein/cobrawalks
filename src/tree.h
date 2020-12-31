#pragma once
#include <cmath>
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <chrono>    
#include <random>
#include <queue>
#define N 4 
#define K 30
#define MAX_TREE_DEPTH 2

using namespace std;
class Node {
    private:
     public:

	Node* parent;
	void print_node(Node* node);
	vector<Node*> children;
	bool infected;
	/* constructors and destructors */
	Node();
	int level;
	Node(bool _infected, int _level, Node* _parent);
	~Node();

	int infect_neighbor();
	bool is_infected();
	void infect();
	void set_parent(Node* parent);
	Node* get_parent();
	vector<Node*> get_children();
	void set_children(vector<Node*> _children);
};

class Tree {
    private:
    public:
	void print_tree_helper(Node* node);
	Tree();
	Node* root;
	Node* current;
	Tree(Node* root);
	~Tree();
	Node* make_root();
	int depth;
	void add_level();
	void add_levels();
	void print_tree();
};

class Simulation {
    private:
	int k;
	volatile int clk;

    public:
	Simulation();
	Simulation(Tree* _tree, int _k);
	Tree* tree;
	void do_timestep();
};
