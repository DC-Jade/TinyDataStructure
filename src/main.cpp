#include <cstdio>

#include "../include/Vector.hpp"
#include "../include/List.hpp"
#include "../include/Stack.hpp"
#include "../include/Queue.hpp"
// #include "../include/BinTree.hpp"
#include "../include/BinNode.hpp"
#include "../include/Entry.hpp"
// #include "../include/BinarySearchTree.hpp"

using mydatastructure::BinNode;
// using mydatastructure::BinTree;
// using mydatastructure::BST;
using mydatastructure::Entry;
using mydatastructure::List;
using mydatastructure::ListNode;
using mydatastructure::Queue;
using mydatastructure::Stack;
// using mydatastructure::TraverseInIteration;
// using mydatastructure::TraverseInRecursive;
// using mydatastructure::TraversePreIteration;
using mydatastructure::Vector;
// using mydatastructure::VST;
using std::printf;

void Tranverse(Vector<int>& vec) {
  int vec_size = vec.Size();
  for (int i = 0; i < vec_size; ++i) {
    std::cout << vec[i] << "\t";
  }
}

void TestBinNode() {
	BinNode<int> bin_node = 2;
	BinNode<int> bin_node_two;
	printf("bin_node._data = %d\n", bin_node._data);
	printf("bin_node_two._data = %d\n", bin_node_two._data);

	/* test insert */
	bin_node.InsertAsLC(1);
	bin_node.InsertAsRC(3);
	HasLChild(bin_node) ?  printf("LChild = %d\n", bin_node._lc->_data) : 
		printf("LChild not exist\n");
	HasRChild(bin_node) ?  printf("RChild = %d\n", bin_node._rc->_data) : 
		printf("RChild not exist\n");
	HasChild(bin_node) ?  printf("Child exist\n") : printf("Child not exist\n");

	/* BinNode status */
	IsRoot(bin_node) ? printf("bin_node is Root\n") :
		printf("bin_node is not Root\n");
	IsLeaf(bin_node) ? printf("bin_node is Leaf\n") :
		printf("bin_node is not Leaf\n");
	IsRoot(*(bin_node._lc)) ? printf("bin_node._lc is Root\n") :
		printf("bin_node._lc is not Root\n");
	IsLeaf(*(bin_node._lc)) ? printf("bin_node._lc is Leaf\n") :
		printf("bin_node._lc is not Leaf\n");
	IsRoot(*(bin_node._rc)) ? printf("bin_node._rc is Root\n") :
		printf("bin_node._rc is not Root\n");
	IsLeaf(*(bin_node._rc)) ? printf("bin_node._rc is Leaf\n") :
		printf("bin_node._rc is not Leaf\n");
}

int main() {
	TestBinNode();
}
