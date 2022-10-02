#include <iostream>
#include "item.h"

Item::Item(std::string name, double price, int amount)
    : product_name(name), price(price), in_stock(amount)
{
  is_in_stock = true;
}

const std::string Item::get_name()
{
  return product_name;
}

void Item::get_product_details()
{
  std::cout << "Product name " << product_name << "\n"
            << "Price " << price << "\n"
            << std::boolalpha << "Is in stock " << is_in_stock << "\n"
            << "Amount in stock " << in_stock << std::endl;
}