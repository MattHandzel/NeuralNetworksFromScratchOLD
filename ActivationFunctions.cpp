#include "ActivationFunctions.h"
#include <functional>
#include <math.h>

double ActivationFunctions::linear(double value){
      return value;
    }

double ActivationFunctions::sigmoid(double value){
    return 1 / (1 + pow(E, -value));
}

double ActivationFunctions::relu(double value){
    /* -This function will return value if value is greater than 0, else
        it will return 0
        || max(value, 0) might be faster, idk
    */
    return ((value) > 0) * value;
}
