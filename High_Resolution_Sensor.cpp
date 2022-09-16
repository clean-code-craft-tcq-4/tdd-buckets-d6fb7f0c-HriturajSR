#include "High_Resolution_Sensor.h"

using namespace std;

bool checkIf12BitArrayWithInRange(uint32_t *arrayForTest, uint32_t sizeOfArray)
{
  for (uint32_t counter = 0; counter < sizeOfArray; counter++)
  {
    if ((arrayForTest[counter] > ADC_12BIT_UPPER_LIMIT) || (arrayForTest[counter] < ADC_12BIT_LOWER_LIMIT))
    {
      return false;
    }
  }
  return true;
}

vector<uint32_t> adc12BitCurrentValueToAmpere(uint32_t *currentSensorValue, uint32_t sizeOfcurrentSensor)
{
  std::vector<uint32_t> currentInAmpereList;
  if ((sizeOfcurrentSensor != 0) && (checkIf12BitArrayWithInRange(currentSensorValue, sizeOfcurrentSensor)))
  {
    for (uint32_t counter = 0; counter < sizeOfcurrentSensor; counter++)
    {
      uint32_t roundOfValue = round(ADC_12BIT_MAX_CURRENT_IN_AMPS * static_cast<float>(currentSensorValue[counter]) / ADC_12BIT_UPPER_LIMIT);
      currentInAmpereList.push_back(static_cast<uint32_t>(roundOfValue));
    }
  }
  return currentInAmpereList;
}
