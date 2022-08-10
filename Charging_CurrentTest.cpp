#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "Charging_Current.h"
using namespace std;

TEST_CASE("Analysing Multiple Samples")
{
  generateRangeAndPrintOutput({4, 5, 10});
  generateRangeAndPrintOutput({1, 4, 6, 7, 8, 10});
  generateRangeAndPrintOutput({1, 2, 3, 4, 5, 7, 8, 9, 13, 14, 15, 16, 17});
  generateRangeAndPrintOutput({});
}
