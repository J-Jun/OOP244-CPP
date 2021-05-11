#ifndef _244_SHOPPINGLIST_H
#define _244_SHOPPINGLIST_H

#include "ShoppingRec.h"

namespace sdds {
  const int MAX_NO_OF_RECS = 15;

  bool loadList();
  bool saveList();
  void removeItem(int index);
  void clearList();
  void toggleBought();
  void addItemToList();
  bool listIsEmpty();
  void removeItemfromList();
  void displayList();
  void removeBoughtItems();
}
#endif // !244_SHOPPINGLIST_H
