#include <iostream>
#include "owner.h"
#include "item.h"
#include "client.h"

void Owner::add_product(Item *item, int amount)
{
  item->in_stock += amount;
}

void Owner::change_price(Item *item, double changed_price)
{
  item->price = changed_price;
}

void Owner::get_statistics()
{
  std::cout << "\n"
            << "\t"
            << "Store statistics"
            << "\n"
            << "Products sold " << amount_bought << "\n"
            << "Profit " << profit << std::endl;
}