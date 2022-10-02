#include <iostream>
#include <vector>
#include "item.h"
#include "client.h"
#include "owner.h"

int main()
{
  Item *butter = new Item("butter", 3.68, 25);
  Item *cheese = new Item("cheese", 5.34, 21);
  Item *bread = new Item("bread", 2.50, 40);

  Client *one = new Client();
  Client *two = new Client();

  Owner *owner = new Owner();

  owner->add_product(bread, 3);
  owner->change_price(bread, 3.10);

  bread->get_product_details();

  butter->get_product_details();
  cheese->get_product_details();

  one->put_in_basket(cheese, 21);
  two->put_in_basket(butter, 1);

  one->take_out_product(butter, 1);
  one->put_in_basket(bread, 1);
  one->take_out_product(cheese, 21);

  one->pay(owner);
  two->pay(owner);

  owner->get_statistics();

  cheese->get_product_details();

  delete butter;
  delete cheese;
  delete bread;

  delete one;
  delete owner;

  return 0;
}