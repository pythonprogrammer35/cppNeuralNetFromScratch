#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <chrono>
#include "vectorFunctions.cpp"
#include "Layer.cpp"

class convolutionalLayer: public Layer{
    public:
        convolutionalLayer(){}

        /*std::vector<std::vector<double>> forward(std::vector<std::vector<double>> input) {

        }
    
        std::vector<std::vector<double>> backward(std::vector<std::vector<double>> output_gradient, double learning_rate){

        }*/

        virtual std::string getName() { return "Convolutional Layer"; }
};
