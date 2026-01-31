#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <chrono>
#include "vectorFunctions.cpp"
#include "Layer.cpp"

//for loop calc = size of matrix1 - kernel/matrix2
std::vector<std::vector<double>> crossCorrelation(std::vector<std::vector<double>> matrix1, std::vector<std::vector<double>> matrix2, double bias){
    //This controls how and when the kernel moves down rows.
    int outputSize = (matrix1.size() - matrix2.size()) + 1.0;
    std::vector<std::vector<double>> result(outputSize, std::vector<double>(outputSize, 0));

    double tempKernelResult = 0.0;

    for(int w = 0; w < (outputSize); w++){
        //This controls how the kernel moves laterally
        for(int i = 0; i < (outputSize); i++){
            //This controls which row of the matrix is being considered
            
            for(int j = 0; j < matrix2.size(); j++){
                //This controls which column of the row of the matrix is being considered
                for(int k = 0; k < matrix2[0].size(); k++){
                    tempKernelResult += (matrix1[w+j][i+k] * matrix2[j][k]);
                }
            }
            result[w][i] = tempKernelResult + bias;
            tempKernelResult = 0;
        }
    }
    return result;
}

int main(){
    std::vector<std::vector<double>> inputOne = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    std::vector<std::vector<double>> inputTwo = {
        {1,2},
        {3,4}
    };
    double bias = 7.0;

    std::vector<std::vector<double>> output = crossCorrelation(inputOne, inputTwo, bias);

    std::cout << "Result " << std::endl;
    printMatrix(output);

    return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> 9c7417a6bcd0e9c4bb680b155e50b46b37f7f042
