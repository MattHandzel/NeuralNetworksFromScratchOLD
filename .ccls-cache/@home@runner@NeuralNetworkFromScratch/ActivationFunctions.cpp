#include "ActivationFunctions.h""
#include <functional>
#include <cmath>



double ActivationFunctions::linear(double value){
      return value;
    }

double ActivationFunctions::sigmoid(double value){
    return 1 / (1 + pow(E, -value));
}

double ActivationFunctions::tanh(double value){

double ActivationFunctions::relu(double value){
    return (((double)(-1) ^ value) < 0) * value;
}