#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <chrono>
#include "vectorFunctions.cpp"

class Tensor {
    std::vector<double> tensor;
    int rows;
    int cols;
    public:
        Tensor(int rowInput, int colInput){
            this->rows = rowInput;
            this->cols = colInput;
            createTensor();
        }
        void createTensor(){
            std::vector<double> holder((this->rows * this->cols), 0.0);
            this->tensor = holder;
        }

        void alterIndex(int rowIndex, int colIndex, double input){
            //The equation should be cols * rowIndex + colIndex
            int realIndex = (this->cols * rowIndex) + colIndex;
            this->tensor[realIndex] = input;
        }
        double getIndex(int rowIndex, int colIndex){
            //The equation should be cols * rowIndex + colIndex
            int realIndex = (this->cols * rowIndex) + colIndex;
            return this->tensor[realIndex];
        }
        //This is to get the Rows and col position of a given index
        std::pair<int, int> getMatrixRC(int inputIndex){
            int rowIndex = std::floor(inputIndex / this->cols);
            int colIndex = inputIndex % this->cols;
            return std::make_pair(rowIndex, colIndex);
        }
        void printTensorMatrix(){
            std::string holder = "";
            std::string holder2 = "{";
            for (int i = 0; i < rows; i++){
                for (int j = 0; j < cols; j++){
                    holder2 += std::to_string(tensor[((i*cols) + j)]);
                    holder2 += ",";
                }
                holder = holder2;
                holder += "}";
                std::cout << holder << std::endl;
                holder2 = "{";
            }
            
        }
        void printTensorRaw(){
            std::string holder = "";
            std::string holder2 = "{";
            for (int i = 0; i < tensor.size(); i++){
                holder2 += std::to_string(tensor[i]);
                holder2 += ",";
            }
            holder = holder2;
            holder += "}";
            std::cout << holder << std::endl;
            holder2 = "{";
        }
};


int main(){
    Tensor tensor(4,3);
    tensor.printTensorMatrix();
    std::cout << "spacer" << std::endl;
    tensor.printTensorRaw();
    std::cout << "spacer" << std::endl;
    tensor.alterIndex(1,1,3);
    tensor.alterIndex(2,1,4);

    
    tensor.printTensorMatrix();
    std::cout << "spacer" << std::endl;
    tensor.printTensorRaw();
    std::cout << "spacer" << std::endl;
    auto [row, col] = tensor.getMatrixRC(4);
    std::cout << std::to_string(row) << " " << std::to_string(col);

}