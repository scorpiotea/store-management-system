#include <iostream>
#include <vector>
#include "item.h"
#include "client.h"

int main()
{
  Item *butter = new Item("butter", 3.68, 25);
  Item *cheese = new Item("cheese", 5.34, 21);
  Item *bread = new Item("bread", 2.50, 40);


  Client *one = new Client();

  butter->get_product_details();
  cheese->get_product_details();

  one->put_in_basket(cheese, 2);
  one->put_in_basket(butter, 1);

  // one->take_out_product(cheese, 2);
  one->put_in_basket(bread, 1);

  one->pay();

  delete butter;
  delete cheese;

  delete one;

  return 0;
}