#include<iostream>
#define COUNT 10

//I used this code from cprograming.com/tutorial/lesson18.html
namespace ariel
{


class Node{
            
            public:
                Node();
              //  ~Node();
                Node(int num);

            
                int key;
                Node* left;
                Node* right;

            };
    class Tree
    {

        public:
            Node* _root;
            Tree();
          //  ~Tree();
            void  insert(int key);
            void remove(int key);
            int   size();
            bool  contains(int key);
            int   root();
            int   left(int key);
            int   right(int key);
            int   parent(int key);
            void  print();
            /*Node search(int key);*/



        private:

                void   insert_value(int key, Node* leaf);
                void remove_value(Node* &node, int key);
                int    Tree_size(Node* node);
                 Node* minValueNode( Node* node); //Inner function
                bool   contain_value(Node* node , int key);
                int    getLeftChild(Node* node , int key);
                int    getRightChild(Node* node , int key);
                int    getParent(Node* node, int key);
               void print2DUtil(Node *_root, int space);

             //   void   print(Node* node) ;

                void   destroy_tree(Node* leaf);
                /* Node search__key(int key, Node* leaf);*/





    };
}

	
