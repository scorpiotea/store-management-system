#include <iostream>
#include <vector>
#include <algorithm>
#include "client.h"
#include "item.h"

void Client::put_in_basket(Item *item, int amount)
{
  basket.push_back(*item);
  amount_in_basket.push_back(amount);
}

int Client::get_item_position(Item item)
{
  int index{};
  for (std::vector<Item>::iterator itr = basket.begin(); itr != basket.end(); ++itr)
  {
    index++;
    if (itr->get_name() == item.get_name())
    {
      break;
    }
  }
  return index - 1;
}

void Client::take_out_product(Item target, int amount)
{
  if (amount_in_basket[get_item_position(target)] == amount)
  {
    for (std::vector<Item>::iterator it = basket.begin(); it != basket.end(); ++it)
    {
      if (it->get_name() == target.get_name())
      {
        basket.erase(it);
        break;
      }
    }
  }
  else if (amount_in_basket[0] > amount)
  {
    amount_in_basket[0] -= amount;
  }
  else
  {
    std::cerr << "You don't have given amount of product";
  }
}

void Client::pay()
{
  std::cout << std::endl
            << "Items in your basket \n";

  double total{};

  for (int i{}; i < basket.size(); i++)
  {
    std::cout << "\t" << basket[i].product_name << " " << amount_in_basket[i] << " " << basket[i].price * amount_in_basket[i] << std::endl;
    total += basket[i].price * amount_in_basket[i];
  }
  std::cout << std::endl
            << "\t"
            << "- Total - " << total;
}
