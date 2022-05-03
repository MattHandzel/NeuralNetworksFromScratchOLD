#include <functional>
#include <cmath>

class ActivationFunctions{
  //std::function<double(double)> linear [](double value) {return value;};

  static double linear(double value);
  static double sigmoid(double value);
  static std::function<double(double)> tanh = tanh; 
  static double relu(double value);
  double E = 2.71828183;
};