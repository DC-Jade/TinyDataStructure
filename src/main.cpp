#include <cstdio>

#include "../include/Vector.hpp"
#include "../include/List.hpp"
#include "../include/Stack.hpp"
#include "../include/Queue.hpp"
#include "../include/BinTree.hpp"
#include "../include/BinNode.hpp"
#include "../include/Entry.hpp"
// #include "../include/BinarySearchTree.hpp"

using mydatastructure::BinNode;
using mydatastructure::BinTree;
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
using mydatastructure::VST;
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

void TestBinTree() {
	BinTree<int> bin_tree;
	bin_tree.InsertAsRoot(10);
	bin_tree.InsertAsLC(bin_tree.Root(), 9);
	bin_tree.InsertAsRC(bin_tree.Root(), 11);
	bin_tree.InsertAsRC(bin_tree.Root()->_lc, 8);
	printf("%p\n", bin_tree.Root());
	printf("Before bin_tree._size = %d\n", bin_tree.Size());

	// bin_tree.Remove(bin_tree.Root());
	// printf("After bin_tree._size = %d\n", bin_tree.Size());

	BinTree<int> sub_tree;
	sub_tree.InsertAsRoot(20);
	sub_tree.InsertAsLC(sub_tree.Root(), 19);
	sub_tree.InsertAsRC(sub_tree.Root(), 21);
	BinTree<int> *ptree = &sub_tree;
	bin_tree.AttachAsRC(bin_tree.Root()->_rc, &ptree);
	// bin_tree.AttachAsRC(bin_tree.Root()->_rc, &&sub_tree);
	printf("After bin_tree._size = %d\n", bin_tree.Size());
	VST<int> visit;
	printf("TravelLevel\n");
	bin_tree.TravelLevel(visit);
	// printf("TravelPre\n");
	bin_tree.TravelPre(visit);
	// printf("TravelIn\n");
	bin_tree.TravelIn(visit);
	// printf("TravelPost\n");
	bin_tree.TravelPost(visit);
}

int main() {
	// TestBinNode();
	TestBinTree();
}
