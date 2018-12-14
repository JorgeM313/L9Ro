//Jorge Martinez
//CPSC 121
//12/12/2018


#include "LinkedList.h" // Function Declarations
#include <iostream>
using namespace std;
template <class T>
int LinkedList<T>::recursiveSum(Node<T> * h)
{
if(h != NULL) 

	{
		return h->data+recursiveSum(h->next);
	} 
else 
	 {
		return 0;
	 }
}

template <class T>

int LinkedList<T>::size()
{
int count = 0;
Node<T> * curr = head;
while(curr != NULL) {
count++;
curr= curr->next;
}
return count;
}
template <class T>
void LinkedList<T>::display()
{
Node<T> * curr = head;
if(curr == NULL) {
cout << "List is empty" << endl;
}
while(curr!=NULL) {
cout << curr->data << " ";
curr = curr->next;
}
cout << endl;
}
template <class T>
void LinkedList<T>::insertItemSorted(T item)
{
Node<T> *newNode = new Node<T>();
newNode->data = item;
newNode->next = NULL;
if(head==NULL) {
//its the first node inserted
head = newNode;
return;
}
if(item<head->data) {
//insert at first

newNode->next = head;
head = newNode;
return;

}
Node<T> *curr = head;
Node<T> *prev;
while(curr!=NULL && curr->data < item) {
prev = curr;
curr = curr->next;
}
if(curr == NULL) {
//insert at last
prev->next = newNode;
} else {
//now curr->data is larger than the item, so it's inserted between prev and curr.
prev->next = newNode;
newNode->next = curr;
}
}
template <class T>
bool LinkedList<T>::findValue(T item)
{
Node<T> *curr = head;
while(curr !=NULL) {
if(curr->data == item) {
return true;
}
curr = curr->next;
}
return false;
}
template <class T>
void LinkedList<T>::remove(T item)
{
if(head == NULL) {
cout << "List is empty" << endl;
return;
}
if(head->data == item) {
//if first item has to be removed
head = head->next;
return;
}
Node<T> *curr = head;
Node<T> *prev;

while(curr!=NULL && curr->data!=item) {
prev = curr;
curr=curr->next;
}
if(curr == NULL) {
cout << "Item not found" << endl;
} else {
prev->next = curr->next;
curr->next = NULL;
}
}
template class LinkedList<int>;//Apparently the problem has to do with this, maybe?
