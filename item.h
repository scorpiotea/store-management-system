#include <string>
#ifndef item_h
#define item_h

class Item
{
private:
  std::string product_name{};
  double price{};
  bool is_in_stock{};
  int in_stock{};

public:
  Item() = default;
  Item(std::string name, double price, int amount);

  void get_product_details();
};

#endif