#include <iostream>
#include "item.h"

int main()
{
  Item *butter = new Item("butter", 3.68, 25);
  Item *cheese = new Item("cheese", 5.34, 21);

  butter->get_product_details();
  cheese->get_product_details();

  delete butter;
  delete cheese;

  return 0;
}