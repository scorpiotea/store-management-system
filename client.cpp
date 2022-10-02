#include <iostream>
#include <vector>
#include <algorithm>
#include "client.h"
#include "item.h"

void Client::put_in_basket(Item *item, int amount)
{
  if (item->is_in_stock == true)
  {
    basket.push_back(*item);
    amount_in_basket.push_back(amount);
    if (item->in_stock > amount)
    {
      item->in_stock -= amount;
    }
    else if (item->in_stock == amount)
    {
      item->in_stock -= amount;
      item->is_in_stock = false;
    }
    else
    {
      std::cerr << "There isn't enough of the product in stock";
    }
  }
  else
  {
    std::cerr << "The product is out of stock";
  }
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

void Client::take_out_product(Item *item, int amount)
{
  if (amount_in_basket[get_item_position(*item)] == amount)
  {
    for (std::vector<Item>::iterator it = basket.begin(); it != basket.end(); ++it)
    {
      if (it->get_name() == item->get_name())
      {
        basket.erase(it);
        auto remove = std::remove(amount_in_basket.begin(), amount_in_basket.end(), amount_in_basket[get_item_position(*item)]);

        if (item->in_stock == 0)
        {
          item->is_in_stock = true;
        }
        item->in_stock += amount;
        break;
      }
    }
  }
  else if (amount_in_basket[get_item_position(*item)] > amount)
  {
    if (item->in_stock == 0)
    {
      item->is_in_stock = true;
    }
    amount_in_basket[0] -= amount;
    item->in_stock += amount;
  }
  else
  {
    std::cerr << "You don't have given amount of product or the product it self";
  }
}

void Client::pay(Owner *owner)
{
  std::cout << std::endl
            << "Items in your basket \n";

  double total{};

  for (int i{}; i < basket.size(); i++)
  {
    std::cout << "\t" << basket[i].product_name << " " << amount_in_basket[i] << " " << basket[i].price * amount_in_basket[i] << std::endl;

    total += basket[i].price * amount_in_basket[i];

    owner->amount_bought += amount_in_basket[i];
    owner->profit += amount_in_basket[i] * basket[i].price;
  }
  std::cout << "\t"
            << "- Total - " << total;
}
