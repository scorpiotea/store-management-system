#include <string>
#include <vector>
#include "item.h"
#ifndef client_h
#define client_h

class Client
{
private:
  std::string user_name;
  std::vector<Item> basket{};
  std::vector<int> amount_in_basket{};

public:
  void put_in_basket(Item *item, int amount);
  void take_out_product(Item *item, int amount);
  void pay();
};

#endif