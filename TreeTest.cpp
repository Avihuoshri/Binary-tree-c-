/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;  
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  ariel::Tree mytree;  

  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_THROWS(threetree.left(6))
  .CHECK_OK    (threetree.print())
  .print()


.CHECK_EQUAL (mytree.size(),0) // check if the empty tree size is equal to zero
.CHECK_OK (mytree.insert(20))//insert 20 as the #1 value
.CHECK_OK (mytree.insert(10))//insert 10 as the #2 value
.CHECK_OK (mytree.insert(15))//insert 15 as the #3 value
.CHECK_OK (mytree.insert(13))//insert 13 as the #4 value
.CHECK_OK (mytree.insert(17))//insert 17 as the #5 value
.CHECK_OK (mytree.insert(4))//insert 16 as the #6 value
.CHECK_OK (mytree.insert(30))//insert 30 as the #7 value
.CHECK_OK (mytree.insert(32))//insert 32 as the #8 value
.CHECK_OK (mytree.insert(40))//insert 40 as the #9 value
.CHECK_OK (mytree.insert(38))//insert 38 as the #10 value
.CHECK_OK (mytree.insert(19))//insert 19 as the #11 value
.CHECK_OK (mytree.insert(11))//insert 11 as the #12 value
.CHECK_OK (mytree.insert(16))//insert 16 as the #13 value
.CHECK_OK (mytree.insert(14))//insert 14 as the #14 value
.CHECK_OK (mytree.insert(18))//insert 18 as the #15 value
.CHECK_OK (mytree.insert(42))//insert 42 as the #16 value
.CHECK_OK (mytree.insert(2))//insert 2 as the #17 value
.CHECK_OK (mytree.insert(6))//insert 6 as the #18 value
.CHECK_OK (mytree.insert(9))//insert 9 as the #19 value
.CHECK_OK (mytree.insert(1))//insert 1 as the #20 value
.CHECK_OK (mytree.insert(7))//insert 7 as the #21 value
.CHECK_OK (mytree.insert(50))//insert 50 as the #22 value


//TESTING size() FUNCTION AFTER BUILDING THE NEW TREE: 
.CHECK_EQUAL(mytree.size(),22)//Check if the tree size is equal to 23

//TESTING root() FUNCTION : 
.CHECK_EQUAL(mytree.root(),20)//Check if the root equal to 12

//TESTING parent() FUNCTION : 
.CHECK_EQUAL (mytree.parent(10),20)//Check if 10's parent is the tree root
.CHECK_EQUAL(mytree.parent(30),20)//Check if 30's parent is the tree root

//TESTING left() FUNCTION : 
.CHECK_EQUAL(mytree.left(20),10)//Check if the left Root's son is 10
.CHECK_EQUAL(mytree.left(10),4)//Check if the left 10's son is 2


//TESTING right() FUNCTION : 
.CHECK_EQUAL(mytree.right(20),30) //Check if the right Root's son is 30
.CHECK_EQUAL(mytree.right(30),32) // Check if the right son of 30 is 32 


//TESTING contains() FUNCTION : 
.CHECK_EQUAL(mytree.contains(20),true)   //Check if the tree contains the value 20
.CHECK_EQUAL(mytree.contains(10),true)   //Check if the tree contains the value 10 (left subtree of the root)
.CHECK_EQUAL(mytree.contains(30),true)   //Check if the tree contains the value 30 (right subtree of the root)
.CHECK_EQUAL(mytree.contains(2),true)    //Check if the tree contains the value 2 (middle of the left subtree)
.CHECK_EQUAL(mytree.contains(32),true)   //Check if the tree contains the value 32 (middle of the right subtree)
.CHECK_EQUAL(mytree.contains(7),true)    //Check if the tree contains the value 7 (leaf in the left subtree)
.CHECK_EQUAL(mytree.contains(50),true)   //Check if the tree contains the value 50 (leaf in the right subtree)
.CHECK_EQUAL(mytree.contains(0),false)   //Check if the tree dosn't contains the value 0 (smaller then the root)
.CHECK_EQUAL(mytree.contains(100),false) //Check if the tree dosn't contains the value 100 (bigger then the biggest value in the tree)




//EXCEPTIONS : 
.CHECK_THROWS(mytree.left(30))  //Should throw exception becouse there is no left son to 30
.CHECK_THROWS(mytree.parent(20))//Should throw exception becouse there is no parent to root





//TESTING remove() FUNCTION (+contains() + size() ) : 
//TIP : the original tree size was 22 : 
.CHECK_OK(mytree.remove(7))
.CHECK_EQUAL(mytree.contains(7),false) 
.CHECK_OK (mytree.insert(7))
.CHECK_EQUAL(mytree.contains(7),true) 
.CHECK_EQUAL(mytree.size() ,22) 
.CHECK_OK(mytree.remove(19))
.CHECK_EQUAL(mytree.contains(19),false) 
.CHECK_EQUAL(mytree.size(),21)
.CHECK_OK(mytree.remove(20))

//TESTING print() : 
.print()

;


/*
.CHECK_EQUAL (mytree.size(), 0)//size 0 now
.CHECK_OK (mytree.insert(12))
.CHECK_EQUAL (mytree.root(), 12)//inserted 12 and check if 12 is the root
.CHECK_OK (mytree.insert(13))
.CHECK_EQUAL (mytree.root(), 12)//inserted 13 and see if still 12 is the root
.CHECK_EQUAL (mytree.parent(13), 12)//check if 12 is the parent of 13
.CHECK_OK (mytree.insert(14))
.CHECK_EQUAL (mytree.root(), 12)//inserted 14 and check if 12 still the root
.CHECK_EQUAL (mytree.parent(14), 13)//check if 13 is the parent of 14
.CHECK_OK (mytree.insert(11))
.CHECK_OK (mytree.insert(8))
.CHECK_OK (mytree.insert(9))
.CHECK_EQUAL (mytree.parent(8), 11)//check if 11 is parent of 8
.CHECK_EQUAL (mytree.parent(9), 8)//check if 8 is parent of 9
.CHECK_EQUAL (mytree.root(), 12)//inserted 11 , 8 , 9 and check if 12 is the root;
.CHECK_EQUAL (mytree.size(), 6) //check the size (12 13 14 11 8 9 ) size is 6
.CHECK_EQUAL (mytree.contains(1), false)//check if not contains 1
.CHECK_EQUAL (mytree.contains(12), true)//check if contains 12
.CHECK_EQUAL (mytree.contains(13), true)//check if contain 13
.CHECK_EQUAL (mytree.right(12), 13)//check if 13 is right children of 12
.CHECK_EQUAL (mytree.left(12), 11)//check if 11 is left children of 12
.CHECK_EQUAL (mytree.left(11), 8)//check if 8 is right children of 11
.CHECK_EQUAL (mytree.contains(12), true)//check if contain 12
.CHECK_EQUAL (mytree.contains(13), true)//check if contain 13
.CHECK_EQUAL (mytree.contains(14), true)//check if contain 14
.CHECK_EQUAL (mytree.contains(11), true)//check if contain 11
.CHECK_EQUAL (mytree.contains(8), true)//check if contain 8
.CHECK_EQUAL (mytree.contains(9), true)//check if contain 9
.CHECK_EQUAL (mytree.contains(5), false)//check if contain 5 and answer is false
.CHECK_EQUAL (mytree.right(12), 13)//check if 14 is right children of 13
.CHECK_EQUAL (mytree.left(12), 11)//check if 11 is left children of 12
.CHECK_EQUAL (mytree.left(11), 8)//check if 8 is left children of 11
.CHECK_OK (mytree.insert(7)) //insert 7 
.CHECK_EQUAL (mytree.left(8), 7)//check if 7 is left children of 7
.CHECK_EQUAL (mytree.right(8), 9)//check if 9 is right children of 8
.CHECK_EQUAL (mytree.right(13), 14)//check if 14 is right children of 13
.CHECK_OK (mytree.insert(60)) //insert 60
.CHECK_OK (mytree.insert(54)) //insert  54
.CHECK_OK (mytree.insert(68)) //insert  68
.CHECK_OK (mytree.insert(50)) //insert  50
.CHECK_OK (mytree.insert(40)) //insert  40
.CHECK_OK (mytree.insert(51)) //insert  51
.CHECK_EQUAL (mytree.left(50), 40)//check 40 is left children of 50
.CHECK_EQUAL (mytree.right(50), 51)//check if 51 is right children of 50
.CHECK_EQUAL (mytree.parent(50), 54)//check if 54 parent of 50
.CHECK_OK    (mytree.print())
  .print()
.CHECK_OK(mytree.remove(12))
.CHECK_OK    (mytree.print())
  .print()
*/



  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
