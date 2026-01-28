#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <chrono>
#include "vectorFunctions.cpp"
#include "Layer.cpp"

class activationLayer{
    public:
        std::vector<std::vector<double>> input;
        activationLayer(){}

        std::vector<std::vector<double>> forward(std::vector<std::vector<double>> passedMatrix) override {
            this->input = passedMatrix;
            return(ReLU(passedMatrix));
        }

        std::vector<std::vector<double>> backward(std::vector<std::vector<double>> backwardsInput, double learning_rate) override {
            std::vector<std::vector<double>> holder = ReLUDeriv(this->input);
            holder = elementMatrixMulti(holder, backwardsInput);
            return holder;

        }
        //Might try to optimize this at a later date by passing input as a reference
        std::vector<std::vector<double>> ReLU(std::vector<std::vector<double>> input){
            for(int i = 0; i<input.size(); i++){
                for(int j = 0; j<input[0].size(); j++){
                    if(input[i][j] > 0){
                        input[i][j] *= 1;
                    } else if (input[i][j] <= 0){
                        input[i][j] *= 0;
                    }
                }
            }
            return input;
        }

        std::vector<std::vector<double>> ReLUDeriv(std::vector<std::vector<double>> input){
            for(int i = 0; i<input.size(); i++){
                for(int j = 0; j<input[0].size(); j++){
                    if(input[i][j] > 0){
                        input[i][j] == 1;
                    } else if (input[i][j] <= 0){
                        input[i][j] == 0;
                    }
                }
            }
            return input;
        }
};
