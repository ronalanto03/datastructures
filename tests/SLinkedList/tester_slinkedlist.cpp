#include "tester_slinkedlist.h"
#include "SLinkedList.h"

//-----------------------------------------------------------------------------
TEST_F ( tester_slinkedlist, FrontOperations )
{
   SLinkedList<int> list;

   ASSERT_EQ(0, list.getSize());
   ASSERT_TRUE(list.empty());

   list.pushFront(12);
   ASSERT_EQ(12, list.topFront());
   ASSERT_EQ(1, list.getSize());
   ASSERT_FALSE(list.empty());


   list.pushFront(1);
   ASSERT_EQ(1, list.topFront());
   ASSERT_EQ(2, list.getSize());

   list.pushFront(13);
   ASSERT_EQ(13, list.topFront());
   ASSERT_EQ(3, list.getSize());

   list.popFront();
   ASSERT_EQ(1, list.topFront());
   ASSERT_EQ(2, list.getSize());

   list.popFront();
   ASSERT_EQ(12, list.topFront());
   ASSERT_EQ(1, list.getSize());

   list.popFront();
   ASSERT_EQ(0, list.getSize());
   ASSERT_TRUE(list.empty());
}


//-----------------------------------------------------------------------------
TEST_F ( tester_slinkedlist, PopOperations )
{
   SLinkedList<int> list;
   ASSERT_EQ(0, list.getSize());
   ASSERT_TRUE(list.empty());

   list.pushBack(12);
   ASSERT_EQ(1, list.getSize());
   ASSERT_EQ(12, list.topBack());
   ASSERT_EQ(12, list.topFront());
   ASSERT_FALSE(list.empty());

   list.pushBack(4);
   ASSERT_EQ(2, list.getSize());
   ASSERT_EQ(4, list.topBack());
   ASSERT_EQ(12, list.topFront());

   list.pushBack(40);
   ASSERT_EQ(3, list.getSize());
   ASSERT_EQ(40, list.topBack());
   ASSERT_EQ(12, list.topFront());

   list.popBack();
   ASSERT_EQ(2, list.getSize());
   ASSERT_EQ(4, list.topBack());

   list.popBack();
   ASSERT_EQ(1, list.getSize());
   ASSERT_EQ(12, list.topBack());
   ASSERT_EQ(12, list.topFront());


   list.popBack();
   ASSERT_EQ(0, list.getSize());
   ASSERT_TRUE(list.empty());
}


//-----------------------------------------------------------------------------
TEST_F ( tester_slinkedlist, Find )
{
   SLinkedList<int> list;

   for(int i = 0; i < 3; i++)
   {
      ASSERT_FALSE(list.find(i));
      list.pushBack(i);
   }

   for(int i = 0; i < 3; i++)
   {
      ASSERT_TRUE(list.find(i));
   }
}

//-----------------------------------------------------------------------------
TEST_F ( tester_slinkedlist, AddAfter )
{
   SLinkedList<int> list;
   SLinkedList<int>::Node* node = nullptr;
   list.pushBack(1);
   list.pushBack(2);
   node = list.getTail();
   ASSERT_EQ(2, node->getKey());
   list.pushBack(4);
   list.addAfter(node, 3);
   ASSERT_EQ(3, node->getNext()->getKey());
   ASSERT_EQ(4, list.topBack());
}

//-----------------------------------------------------------------------------
TEST_F ( tester_slinkedlist, AddBefore )
{
   SLinkedList<int> list;
   SLinkedList<int>::Node* node = nullptr;
   list.pushBack(1);
   list.pushBack(3);
   node = list.getTail();
   ASSERT_EQ(3, node->getKey());
   list.pushBack(4);
   list.addBefore(node, 2);
   ASSERT_EQ(2, list.getHead()->getNext()->getKey());

   ASSERT_EQ(1, list.getHead()->getKey());
   ASSERT_EQ(2, list.getHead()->getNext()->getKey());
   ASSERT_EQ(3, list.getHead()->getNext()->getNext()->getKey());
   ASSERT_EQ(4, list.getHead()->getNext()->getNext()->getNext()->getKey());
}

//-----------------------------------------------------------------------------
TEST_F ( tester_slinkedlist, Erase )
{
   SLinkedList<int> list;
   SLinkedList<int>::Node* node = nullptr;

   for(int i = 1; i <= 3; i++)
   {
      list.pushBack(i);
   }
   node = list.getHead();
   ASSERT_EQ(3, list.getSize());
   ASSERT_EQ(1, node->getKey());
   ASSERT_EQ(2, node->getNext()->getKey());
   ASSERT_EQ(3, node->getNext()->getNext()->getKey());

   list.erase(2);
   ASSERT_EQ(2, list.getSize());
   ASSERT_EQ(1, node->getKey());
   ASSERT_EQ(3, node->getNext()->getKey());

   list.addAfter(list.getHead(), 2);
   ASSERT_EQ(3, list.getSize());
   ASSERT_EQ(1, node->getKey());
   ASSERT_EQ(2, node->getNext()->getKey());
   ASSERT_EQ(3, node->getNext()->getNext()->getKey());

   list.erase(1);
   node = list.getHead();
   ASSERT_EQ(2, list.getSize());
   ASSERT_EQ(2, node->getKey());
   ASSERT_EQ(3, node->getNext()->getKey());

   list.pushFront(1);
   node = list.getHead();
   list.erase(3);
   ASSERT_EQ(2, list.getSize());
   ASSERT_EQ(1, node->getKey());
   ASSERT_EQ(2, node->getNext()->getKey());
   ASSERT_EQ(nullptr, node->getNext()->getNext());

   list.popBack();
   node = list.getHead();
   ASSERT_EQ(1, list.getSize());
   ASSERT_EQ(1, node->getKey());
   ASSERT_EQ(nullptr, node->getNext());
   list.erase(1);
   ASSERT_EQ(0, list.getSize());
   ASSERT_EQ(nullptr, list.getHead());
   ASSERT_EQ(nullptr, list.getTail());
   ASSERT_TRUE(list.empty());



}
