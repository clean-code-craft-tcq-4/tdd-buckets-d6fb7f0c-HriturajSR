#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "Charging_Current.h"
using namespace std;

TEST_CASE("Analysing Multiple Samples")
{
  generateRangeAndPrintOutput({4, 5, 10});
  generateRangeAndPrintOutput({1, 4, 6, 7, 8, 10});
  generateRangeAndPrintOutput({1, 2, 3, 4, 5, 7, 8, 9, 13, 14, 15, 16, 17});
  generateRangeAndPrintOutput({});
}
// Start : Test high_resolution_current_sensor
TEST_CASE("test checkIf12BitArrayWithInRange : value within boundary")
{
  uint32_t currentSensorValue[] = {0, 1000, 2000, 3000, 4094};
  uint32_t sizeofSensorValue = sizeof(currentSensorValue) / sizeof(currentSensorValue[0]);
  bool status = checkIf12BitArrayWithInRange(currentSensorValue, sizeofSensorValue);
  REQUIRE(status == true);
}

TEST_CASE("test checkIf12BitArrayWithInRange : value > boundary")
{
  uint32_t currentSensorValue[] = {0, 1000, 2000, 3000, 5000};
  uint32_t sizeofSensorValue = sizeof(currentSensorValue) / sizeof(currentSensorValue[0]);
  bool status = checkIf12BitArrayWithInRange(currentSensorValue, sizeofSensorValue);
  REQUIRE(status == false);
}

TEST_CASE("test adc12BitCurrentValueToAmpere : value within boundary")
{
  uint32_t currentSensorValue[] = {500, 1146, 1500, 2000, 2500, 3000, 3500, 4000};
  uint32_t expectedCurrentValueInAmpere[] = {1, 3, 4, 5, 6, 7, 9, 10};
  auto sizeOfcurrentSensor = sizeof(currentSensorValue) / sizeof(currentSensorValue[0]);
  auto actual12BitCurrentValueInAmpere = adc12BitCurrentValueToAmpere(currentSensorValue, sizeOfcurrentSensor);
  for (uint32_t counter = 0; counter < sizeOfcurrentSensor; counter++)
  {
    REQUIRE(actual12BitCurrentValueInAmpere[counter] == expectedCurrentValueInAmpere[counter]);
  }
}

TEST_CASE("test adc12BitCurrentValueToAmpere : value > boundary")
{
  uint32_t currentSensorValue[] = {4095};
  auto sizeOfcurrentSensor = sizeof(currentSensorValue) / sizeof(currentSensorValue[0]);
  auto actual12BitCurrentValueInAmpere = adc12BitCurrentValueToAmpere(currentSensorValue, sizeOfcurrentSensor);
  bool currentInAmpereStatus = actual12BitCurrentValueInAmpere.empty();
  REQUIRE(currentInAmpereStatus == true);
}
// End : Test high_resolution_current_sensor
