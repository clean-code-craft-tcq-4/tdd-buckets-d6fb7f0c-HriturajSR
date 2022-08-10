#include "Charging_Current.h"
using namespace std;

void generateRangeAndPrintOutput(std::vector<int> input_sample)
{
  uint8_t i;
  int count = 0;
  std::vector<int> range;
  std::cout << "|   RANGE   |   READINGS   |" << std::endl;
  std::cout << "----------------------------------------" << std::endl;

  if (!input_sample.empty())
  {
    for (i = 0; i < input_sample.size(); ++i)
    {

      if (count == 0)
      {
        range.push_back(input_sample[i]);
      }

      if (input_sample[i + 1] == input_sample[i] + 1)
      {
        range.push_back(input_sample[i + 1]);
        count++;
      }
      else
      {
        std::cout << "|   " << *min_element(range.begin(), range.end()) << "-" << *max_element(range.begin(), range.end()) << ","
            << "\t " << count + 1 << std::endl;
        range.clear();
        count = 0;
      }
    }

    std::cout << "----------------------------------------" << std::endl;
  }
  else
  {
    std::cout << "Empty Input !!!" << std::endl;
  }
}
