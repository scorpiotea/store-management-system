#include <iostream>
#include <vector>
#include <algorithm>
#include "client.h"
#include "item.h"

void Client::put_in_basket(Item *item, int amount)
{
  Client::basket.push_back(*item);
  Client::amount_in_basket.push_back(amount);
}

void Client::take_out_product(Item *item, int amount)
{
  // std::string name = item->product_name;

  // std::cout<<it - basket.begin();
  // if (amount == amount_in_basket[])
  // Client::basket.push_back(*item);
}

void Client::pay()
{
  std::cout << "Items in your basket \n";

  double total{};

  for (int i{}; i < basket.size(); i++)
  {
    std::cout << "\t" << basket[i].product_name << " " << amount_in_basket[i] << " " << basket[i].price * amount_in_basket[i] << std::endl;
    total += basket[i].price * amount_in_basket[i];
  }
  std::cout<<"Total "<<total;
}
