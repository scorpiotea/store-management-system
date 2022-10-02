#include <vector>
#include "item.h"
#ifndef owner_h
#define owner_h

class Owner
{
private:
  int amount_bought{};
  double profit{};

public:
  void add_product(Item *item, int amount);
  void change_price(Item *item, double changed_price);
  void get_statistics();

  friend class Client;
};

#endif