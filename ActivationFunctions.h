#include <functional>
#include <cmath>

class ActivationFunctions
{
public:
  // std::function<double(double)> linear [](double value) {return value;};
  static double linear(double value);
  static double sigmoid(double value);
  static double relu(double value);
  static constexpr double E = 2.7182818284590452353602874713527;
};