#ifndef VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H
#define VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H

#include <iostream>
#include <string>
#include <regex>
#include <future>

#include "../../gen-cpp/BeveragePreferenceService.h"

#include "../ClientPool.h"
#include "../ThriftClient.h"
#include "../logger.h"

namespace vending_machine{

  class BeveragePreferenceServiceHandler : public BeveragePreferenceServiceIf {
  public:
    BeveragePreferenceServiceHandler();
    ~BeveragePreferenceServiceHandler() override=default;

    void GetBeverage(std::string& _return, const BeverageType::type btype) override;
  };

  // Constructor
  BeveragePreferenceServiceHandler::BeveragePreferenceServiceHandler() {

  }

  void BeveragePreferenceServiceHandler::GetBeverage(std::string& _return, const BeverageType::type btype) {
    const int selection = rand() % 3;

    if (btype == BeverageType::type::HOT)
      if (selection == 0)
        _return = "cappuccino";
      else if (selection == 1)
        _return = "latte";
      else
        _return = "espresso";
    else
      if (selection == 0)
        _return = "lemonade";
      else if (selection == 1)
        _return = "iced tea";
      else
        _return = "soda";
  }

} // namespace vending_machine


#endif //VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H

