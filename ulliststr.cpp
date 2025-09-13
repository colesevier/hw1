#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

// Returns a const reference to the back element
std::string const & ULListStr::back() const
{
  // don't need to worry about empty case
  return tail_->val[tail_->last - 1];
}

// Returns a const reference to the front element
std::string const & ULListStr::front() const
{
  // don't need to worry about empty case
  return head_->val[head_->first];
}

void ULListStr::push_back(const std::string& val)
{
  // handle base case
  if (empty())
  {
    head_ = tail_ = new Item();
    // val is the array we're storing stuff in right?
    tail_->val[0] = val;
    tail_->first = 0;
    tail_->last = 1;


  }
  // now another case if the size is too big
  else if (tail_->last == ARRSIZE)
  {
    Item* item = new Item();
    //initialize values
    item->first = 0;
    item->last = 1;
    item->val[0] = val;
    item->prev = tail_;
    tail_->next = item;
    item->next = NULL;
    tail_ = item;
    
  }
  else
  {
    // I feel like i'm supposed to use item. or something
    tail_->val[tail_->last] = val;
    tail_->last ++;

  }


  // increment size_
  size_ ++;
}


void ULListStr::push_front(const std::string& val)
{
  // handle base case
  if (empty())
  {
    head_ = tail_ = new Item();
    // val is the array we're storing stuff in right?
    head_->val[ARRSIZE - 1] = val;
    head_->last = ARRSIZE;
    head_->first = ARRSIZE - 1;

  }
  // now another case if the size is too big
  else if (head_->first == 0)
  {
    Item* item = new Item();
    // initialize values
    item->last = ARRSIZE;
    item->first = ARRSIZE - 1;
    item->val[ARRSIZE - 1] = val;

    item->next = head_;
    item->prev = NULL;
    head_->prev = item;
    head_ = item;

  }
  else
  {
    // I feel like i'm supposed to use item. or something
    head_->first --;
    head_->val[head_->first] = val;
  }

  // increment size_
  size_ ++;
}

void ULListStr::pop_back()
{
  // remove value
  // base case
  if (empty())
  {
    return;
  }
  // move the last value back
  tail_->last --;
  size_ --;
  // deallocate item if first-last == 0
  if (tail_->first == tail_->last)
  {
    // change up the pointers
    Item* temp = tail_;
    tail_ = tail_->prev;
    if (tail_ != NULL)
    {
      tail_->next = NULL;
    }
    else
    {
      head_ = NULL;
    }
    delete temp;
  }
}

void ULListStr::pop_front()
{
  // remove value
  // base case
  if (empty())
  {
    return;
  }
  // move the last value back
  head_->first ++;
  size_ --;
  if (head_->first == head_->last)
    {
      // change up the pointers
      Item* temp = head_;
      head_ = head_->next;
      if (head_ != NULL)
      {
        head_->prev = NULL;
      }
      else
      {
        tail_ = NULL;
      } 
      delete temp;
    }
  // deallocate item if first-last == 0
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  // maybe increment curr until it is equal to loc
  if (loc >= size_)
  {
    return NULL;
  }
  size_t curr = 0;
  Item* temp = head_;
  while(temp != NULL)
  {
    int block = temp->last - temp->first;
    // check to see if we're at the end of the list
    if (loc < curr + block)
    {

      return &temp->val[temp->first + loc - curr];
    }
    //increment count
    curr += block;
    temp = temp->next;
  }
  // go into temp and return the pointer to curr element
  return NULL;
}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
