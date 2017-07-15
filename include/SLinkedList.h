#include <cstddef>
#include <iostream>

template <typename T>
class SLinkedList
{
   public://inner types

      class Node
      {
         private:
            friend class SLinkedList;
            T key;
            Node* next;


         public:
            Node(const T& _key):key(_key), next(nullptr)
            {/*empty*/}

            T& getKey()
            {
               return  key;
            }

            Node* getNext()
            {
               return next;
            }
      };

   private://data members
      Node* head;
      Node* tail;
      size_t size;


   public:

      //-------------------------------------------------------------------------
      SLinkedList():head(nullptr), tail(nullptr), size(0)
      {/*empty*/}

      //-------------------------------------------------------------------------
      ~SLinkedList()
      {
         while(!empty())
         {
            popBack();
         }
      }

      //-------------------------------------------------------------------------
      size_t getSize() const
      {
         return size;
      }

      //-------------------------------------------------------------------------
      bool empty()
      {
         return head == nullptr;
      }

      //-------------------------------------------------------------------------
      Node* getHead()
      {
         return head;
      }

      //-------------------------------------------------------------------------
      Node* getTail()
      {
         return tail;
      }

      //-------------------------------------------------------------------------
      void pushFront(const T& key)
      {
         Node* node = new Node(key);
         node->next = head;
         head = node;
         if(tail == nullptr)
         {
            tail = head;
         }
         size++;
      }

      //-------------------------------------------------------------------------
      T& topFront()
      {
         return head->key;
      }

      //-------------------------------------------------------------------------
      void popFront()
      {
         if(head == nullptr)
         {
            return;//nothing to pop
         }
         Node* tmp = head;
         head = head->next;
         delete tmp;
         if(head == nullptr)
         {
            tail = nullptr;
         }
         size--;
      }

      //-------------------------------------------------------------------------
      void pushBack(const T& key)
      {
         Node* node = new Node(key);
         if(tail != nullptr)
         {
            tail->next = node;
            tail = node;
         }
         else
         {
            head = tail = node;
         }
         size++;
      }

      //-------------------------------------------------------------------------
      T& topBack()
      {
         return tail->key;
      }

      //-------------------------------------------------------------------------
      void popBack()
      {
         if(head == nullptr)
         {
            return;//nothing to pop
         }

         if(head == tail)//one element
         {
            delete head;
            head = tail = nullptr;
         }
         else
         {
            Node* currNode = head;
            while(currNode->next != tail)
            {
               currNode = currNode->next;
            }
            delete tail;
            tail = currNode;
            tail->next = nullptr;
         }
         size--;
      }

      //-------------------------------------------------------------------------
      bool find(const T& key)
      {
         for(Node* currNode = head;
             currNode != nullptr;
             currNode = currNode->next)
         {
            if(currNode->key == key)
            {
               return true;
            }
         }
         return false;
      }

      //-------------------------------------------------------------------------
      void addAfter(Node* node, const T& key)
      {
         Node* newNode = new Node(key);
         newNode->next = node->next;
         node->next = newNode;

         if(node == tail)
         {
            tail = node;
            tail->next = nullptr;
         }
         size++;
      }

      //-------------------------------------------------------------------------
      void addBefore(Node* node, const T& key)
      {
         Node* newNode =  new Node(key);
         Node* prevNode = nullptr;
         Node* currNode = head;
         while(currNode != node)
         {
            prevNode = currNode;
            currNode = currNode->next;
         }

         if(prevNode != nullptr)
         {
            prevNode->next = newNode;
         }
         else
         {
            head = newNode;
         }
         newNode->next = node;
         size++;
      }

      //-------------------------------------------------------------------------
      void erase(const T& key)
      {
         if(empty())
         {
            return;
         }

         Node* prevNode = nullptr, *currNode = head;
         while(currNode != nullptr && currNode->key != key)
         {
            prevNode = currNode;
            currNode = currNode->next;
         }

         if(currNode == nullptr)
         {
            return;//key not found
         }

         if(prevNode == nullptr)
         {
            head = currNode->next;
         }
         else
         {
            prevNode->next = currNode->next;
         }

         if(currNode == tail)
         {
            tail = prevNode;
            if(tail)
            {
               tail->next = nullptr;
            }
         }

         delete currNode;
         size--;
      }


      //-------------------------------------------------------------------------
      //Test purpose methods
      void print_all()
      {
         for(Node* currNode = head; currNode != nullptr; currNode = currNode->next)
         {
            std::cout<<currNode->key<<" ";
         }
      }


};
