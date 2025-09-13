#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

using namespace std;

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

void ULListStr::push_back (const std::string& val) {

  const std::string value = val;
  if (tail_ == nullptr) {
    Item* newItem = new Item();
    newItem->first = 0;
    newItem->last = 1;
    newItem->val[0] = value;
    newItem->prev = nullptr;
    newItem->next = nullptr;
    head_ = newItem;
    tail_ = newItem;
    size_ = 1;
    return;
  }

  if (tail_->last < ARRSIZE) {
    tail_->val[tail_->last] = value;
    tail_->last += 1;
    size_ += 1;
    return;
  }

  Item* newItem = new Item();
  newItem->first = 0;
  newItem->last = 1;
  newItem->val[0] = value;
  newItem->prev = tail_;
  newItem->next = nullptr;
  tail_->next = newItem;
  tail_ = newItem;
  size_ += 1;

}

void ULListStr::push_front(const std::string& val) {
  const std::string value = val; // did this because I was getting lost with the two val's
  if (head_ == nullptr) {
    Item* newItem = new Item();
    newItem->last = ARRSIZE;
    newItem->first = ARRSIZE - 1;
    newItem->val[newItem->first] = value;
    newItem->prev = nullptr;
    newItem->next = nullptr;
    head_ = newItem;
    tail_ = newItem;
    size_ = 1;
    return;
  }

  if (head_->first > 0) {
    head_->first -= 1;
    head_->val[head_->first] = value;
    size_ += 1;
    return;
  }

  Item* newItem = new Item();
  newItem->last = ARRSIZE;
  newItem->first = ARRSIZE - 1;
  newItem->val[newItem->first] = value;
  newItem->next = head_;
  newItem->prev = nullptr;
  head_->prev = newItem;
  head_ = newItem;
  size_ += 1;

}

void ULListStr::pop_back() {
  if (tail_ == nullptr) {
    return;
  }
  size_t validEle = tail_->last - tail_->first;
  if (validEle > 1) {
    tail_->last -= 1;
    size_ -= 1;
    return;
  }

  if (validEle == 1) {
    Item* deleteItem = tail_;
    tail_ = tail_->prev;
    if (tail_ != nullptr) {
      tail_->next = nullptr;
    }
    else {
      head_ = nullptr;
    }
    delete deleteItem;
    size_ -= 1;
    return;
  }

  Item* deleteItem = tail_;
  tail_ = tail_->prev;
  if (tail_ != nullptr) {
    tail_->next = nullptr;
  }
  else {
    head_ = nullptr;
  }
  delete deleteItem;

}

void ULListStr::pop_front() {
  if (head_ == nullptr) {
    return;
  }

  size_t validEle = head_->last - head_->first;

  if (validEle > 1) {
    head_->first += 1;
    size_ -= 1;
    return;
  }

  if (validEle == 1) {
    Item* deleteItem = head_;
    head_ = head_->next;
    if (head_ != nullptr) {
      head_->prev = nullptr;
    }
    else {
      tail_ = nullptr;
    }
    delete deleteItem;
    size_ -= 1;
    return;
  }

  Item* deleteItem = head_;
  head_ = head_->next;
  if (head_ != nullptr) {
    head_->prev = nullptr;
  }
  else {
    tail_ = nullptr;
  }
  delete deleteItem;

}

string const& ULListStr::back() const {
  return tail_->val[tail_->last - 1];
}

string const& ULListStr::front() const {
  return head_->val[head_->first];
}


string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc >= size_) {
    return NULL;
  }

  Item* temp = head_;
  while (temp != NULL) {
    size_t validEle = temp->last - temp->first;
    if (loc < validEle) {
      return &temp->val[temp->first + loc];
    }
    loc -= validEle;
    temp = temp->next;
  }
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
