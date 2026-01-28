#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <chrono>
#include "vectorFunctions.cpp"
#include "activationLayer.cpp"
#include "denseLayer.cpp"
#include "Layer.cpp"

std::vector<std::vector<std::vector<double>>> trainingSetX = {
    {{1,0,0,0}},
    {{1,1,0,0}},
    {{0,1,0,0}},
    {{0,0,1,0}}
};

std::vector<std::vector<std::vector<double>>> trainingSetY = {
    {{1}},
    {{1}},
    {{0}},
    {{0}}
};

int epochs = 10000;
double learning_rate = 0.01;

std::vector<Layer*> neuralNet;



//training loop
