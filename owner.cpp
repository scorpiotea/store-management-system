#include <iostream>
#include <ctime>
#include <chrono>
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
  auto start = std::chrono::system_clock::now();
  auto end = std::chrono::system_clock::now();

  std::chrono::duration<double> elapsed_seconds = end - start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);

  std::cout << "\n"
            << "\t"
            << "Store statistics"
            << "\n"
            << std::ctime(&end_time)
            << "\n"
            << "Products sold " << amount_bought << "\n"
            << "Profit " << profit << std::endl;
}