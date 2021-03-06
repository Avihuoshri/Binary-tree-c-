#include<iostream>
#include<stdexcept>
#include<exception>
#include"Tree.hpp"


using namespace std;

using  ariel::Tree;
using ariel::Node;

/*ariel::Node::~Node(){
	if(left!=nullptr){delete left; left=nullptr;}
	if(right!=nullptr){delete right; right=nullptr;}
}*/

	ariel::Node::Node():Node(0) {}
	ariel::Node::Node(int num) :key(num),left(NULL),right(NULL) {}
	ariel::Tree::Tree()
	{
		_root = nullptr;
	}

		/* Tree::~Tree()
		{
			destroy_tree(_root);
		}
	
	
		
		void ariel::Tree::destroy_tree(Node* leaf)
			{
				if (leaf != nullptr)
				{
					destroy_tree(leaf->left);
					destroy_tree(leaf->right);
					delete leaf;
				}
			}
		*/
		void ariel::Tree::insert(int key)
		{
		if(contains(key))
		{
		  throw std::invalid_argument("insert exception(value already on the tree)");
		}
		else if(_root!=nullptr)		
		{
			insert_value(key,_root);
		}
		else{_root=new Node(key);}
		}


		void Tree::insert_value(int key, Node* leaf)
		{
			if(leaf==nullptr)
			{
				
				 leaf=new Node(key);
				 leaf->left = leaf->right = nullptr ;
			
			}
			else if (key < leaf->key)
			{						
				
				if (leaf->left != nullptr)
				{
					
					insert_value(key, leaf->left);
				}
				else
				{
					
					leaf->left = new Node(key);
					      //Sets the right child of the node to NULL
				}
			}

			else if (key > leaf->key)
			{
				if (leaf->right != NULL)
				{
					insert_value(key, leaf->right);
				}
				
				else
				{
					leaf->right = new Node(key);
					   //Sets the right child of the child node to NULL
				}

			}

		}



		int ariel::Tree::size()
		{
			return Tree_size(_root);
		}

		int ariel::Tree::Tree_size(Node* node)
		{
			int treeSize = 0 ;

			if (node == NULL)
				return 0;
			else
			{
				return Tree_size(node->left) + 1 + Tree_size(node->right);
				
			}
		}

		 Node* ariel::Tree::minValueNode(Node* node)
		{
			 Node* current = node;

			/* Loop down to find the leftmost leaf */
			while (current->left != NULL)
				current = current->left;

			return current;
		}

		bool ariel::Tree::contains(int key)
		{
			return contain_value( _root ,  key);
		}

		bool ariel::Tree::contain_value(Node* node , int key)
		{
			if (node == NULL)
				return false;

			else
			{
				if (key == node->key)
					return true;

				else if (key < node->key)
					return contain_value(node->left, key);

				else
					return contain_value(node->right, key);

			}
		}

		 void ariel::Tree::remove( int key )
		{
			if(!contains(key))
			{
		     throw std::invalid_argument("the value is not exist");

			}
			else	
			{
				remove_value(_root, key);
			}	
		}

//		 Function to delete node from a BST. Note that root is passed by
 //      reference to the function
void ariel::Tree::remove_value(Node* &root, int key)
{
	// base case: key not found in tree
	if (root == nullptr)
	{
		cout<<"tree is empty/n" ;
		return;
	}
	

	// if given key is smaller than the root node, recurse for left subtree
	if (key < root->key)
		remove_value(root->left, key);

	// if given key is bigger than the root node, recurse for right subtree
	else if (key > root->key)
		remove_value(root->right, key);

	// key found
	else
	{
		// Case 1: node to be removed has no children 
		if (root->left == nullptr && root->right == nullptr)
		{
			// deallocate the memory and update root to null
			delete root;
			root = nullptr;
		}

		// Case 2: node to be removed has two children
		else if (root->left && root->right)
		{
			// find its in-order predecessor node
			Node *predecessor = minValueNode(root->right);

			// Copy the value of predecessor to current node
			root->key = predecessor->key;

			// recursively delete the predecessor. Note that the
			// predecessor will have at-most one child (left child)
			remove_value(root->right, predecessor->key);

		}

		// Case 3: node to be deleted has only one child
		else
		{
			// find child node
			Node* child = (root->left)? root->left: root->right;
			Node* curr = root;

			root = child;

			// deallocate the memory
			delete curr;
			
		}
	}
}


		int ariel::Tree::root()
		{
			if (_root == NULL)
			{
				
					throw std::invalid_argument("ERROR : value NOT found!");
				
			}

			return _root->key;
		}

		int Tree::left(int key)
		{
			if(!contains(key))
			{
				try
				{
					throw std::invalid_argument("ERROR : Left child does not exist!");	
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
				
			}
			else if((key == _root->key) && _root->left ==NULL)
			{

				try
				{
					throw std::invalid_argument("ERROR : Left child does not exist!");	
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
			}
					
			else
			{
				int ans = getLeftChild(_root, key);
				return ans;
			}
			
		
		}

		int  ariel::Tree::getLeftChild(Node* node , int key)
		{
			if (node == NULL)
			{

				        throw std::invalid_argument("the root is not exist");

								
			}
			else if (key < node->key)
			{
				if (node->left != NULL)
					return getLeftChild(node->left, key);
				else
				{
					        throw std::invalid_argument("ERROR : left child is not exist");

				
				}
					
			}

			else if (key > node->key)
			{
				if (node->right != NULL)
					return getLeftChild(node->right, key);
				else
				{
                  throw std::invalid_argument("ERROR : right child is not exist");
 				}
					
			}
			else
			{
				if(node->left != NULL)
					return node->left->key;

				else
				{
					        throw std::invalid_argument("ERROR : left child is not exist");

					
				}
			}
		}
			int Tree:: right(int key)
			{
				
				int ans = getRightChild(_root, key);
				return ans;
			}

			int ariel::Tree:: getRightChild(Node * node , int key)
			{
				if (node == nullptr)
				{
				    throw std::invalid_argument("the root is not exist");
					
				}
				else if (key < node->key)
				{
					if (node->left != nullptr)
						return getRightChild(node->left, key);
					
					else
					{
					        throw std::invalid_argument("ERROR : left child is not exist");


					}
			
				}

				else if (key > node->key)
				{
					if (node->right != nullptr)
						return getRightChild(node->right, key);

					else
					{
						        throw std::invalid_argument("ERROR : right child is not exist");

					
					}				
				}
				
					if (node->right != NULL)
						return node->right->key;

					else 
					{
						        throw std::invalid_argument("ERROR : right child is not exist");

					}
				
			}

			int Tree:: parent(int key)
			{
				if(contains(key)==false)
				
				        throw std::invalid_argument("ERROR : the given number is not in the tree's values");

				return getParent(_root, key);
			}

			int Tree:: getParent(Node * node, int key)
			{

				if(key == node->key)
				{
					      throw std::invalid_argument("ERROR : no parent to root");
				}	

				 if (key < node->key && node->left!= NULL)
						 {
               if(key == node->left->key)
							{
								return node->key;
							}
							return getParent(node->left, key);

					}

					if (key > node->key && node->right != NULL)
					 {
					  if(key == node->right->key)
					  {
						return node->key;
					  }
						return getParent(node->right, key);
				
        	}
					
					}


			
void ariel::Tree::print2DUtil(Node *root, int space)

{

    // Base case
    if (root == NULL)
        return;
    // Increase distance between levels
    space += COUNT;
    // Process right child first
    print2DUtil(root->right, space);
    // Print current node after space
    // count

    cout << endl;

    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->key << "\n";
    // Process left child
    print2DUtil(root->left, space);
}
void ariel::Tree::print()
{

    print2DUtil(_root, 0);
}
		

/*
int main()
{
ariel::Tree t ;
	int treeSize =  t.size();
cout<<"tree size is : "<<treeSize<<endl ;
	t.insert(20);
	t.insert(10);
	t.insert(15);
	t.insert(13);
	t.insert(17);
	t.insert(4);
	t.insert(30);
	t.insert(32);
	t.insert(40);
	t.insert(38);
	t.insert(19);
	t.insert(11);
	t.insert(16);
	t.insert(14);
	t.insert(18);
	t.insert(42);
	t.insert(2);
	t.insert(6);
	t.insert(9);
	t.insert(1);
	t.insert(7);
	t.insert(50);
	t.print() ;
	cout<<"TESTING SIZE()"<<endl ;
	treeSize =  t.size();
	cout<<"tree size is : "<<treeSize<<endl<<endl ;

	cout<<"TESTING CONTAINS() - TRUE "<<endl ;
	treeSize =  t.contains(5);
	cout<<"contains answer is : "<<treeSize<<endl<<endl ;

	cout<<"TESTING CONTAINS() - FALSE "<<endl ;
	treeSize =  t.contains(100);
	cout<<"contains answer is : "<<treeSize<<endl<<endl ;

	cout<<"TESTING REMOVE()  "<<endl ;
	t.remove(100);
	treeSize =  t.contains(100);
	cout<<"contains answer is : "<<treeSize<<endl<<endl ;

	cout<<"TESTING LEFT()  "<<endl ;
	int left_child ;
	left_child = t.left(10) ;
	cout<<"left child is : " << left_child<<endl;
	


}

	*/	
