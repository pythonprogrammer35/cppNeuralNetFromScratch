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

// matrix1 is the "input matrix" and matrix2 is the "kernel"
std::vector<std::vector<double>> fullConvolution(std::vector<std::vector<double>> matrix1, std::vector<std::vector<double>> matrix2){
    //This controls how and when the kernel moves down rows.
    int outputSize = matrix1.size() + (matrix2.size() + 1.0);
    std::vector<std::vector<double>> result(outputSize, std::vector<double>(outputSize, 0));
    std::vector<std::vector<double>> moddifiedInputMatrix = matrix1;

    double paddingFactorX = (matrix2[0].size()-1);
    double paddingFactorY = (matrix2.size()-1);

    

    double tempKernelResult = 0.0;

    int desiredSize = (paddingFactorX*2)+(matrix1[0].size());

    std::cout << "ehhh" << std::endl;
    std::cout << desiredSize;

    //Zero Padding step

    //Todo:

    //Step 1, insert the top rows
    for(int i = 0; i < paddingFactorY; i++){
        //Step 2, fill the top rows with zeros equalling the amount of (Padding Factor*2+(matrix1[0].size()))
        std::vector<double> zeroRow((desiredSize), 0.0);
        moddifiedInputMatrix.insert(moddifiedInputMatrix.begin(), zeroRow);
    }

    

    //Step 3, fill the existing rows with zeros equal to Padding Factor on both sides of the matrix1
    std::cout << "mtest" << std::endl;
    printMatrix(matrix1);
    std::cout << matrix1.size() << std::endl;

    for(int i = 0; i < matrix1.size(); i++){
        if(moddifiedInputMatrix[i+paddingFactorY].size() != desiredSize){
            std::cout << "i test" << std::endl;
            std::cout << i << std::endl;
            for(int j = 0; j < paddingFactorX; j++){
                moddifiedInputMatrix[i+paddingFactorY].insert(moddifiedInputMatrix[i+paddingFactorY].begin(), 0.0);
                moddifiedInputMatrix[i+paddingFactorY].push_back(0.0);
            }
        }
    }
    
    //Step 4, fill bottom rows with zeros using the same equation from Step 2
    for(int i = 0; i < paddingFactorY; i++){
        //Step 2, fill the top rows with zeros equalling the amount of (Padding Factor*2+(matrix1[0].size()))
        std::vector<double> zeroRow((desiredSize), 0.0);
        moddifiedInputMatrix.push_back(zeroRow);
    }
    
    //Convolution step:
    //Simply cross-correlate between matrix1 and 2 using previous function with bias set to 0
    double bias = 0.0;
    
    std::cout << "Heey" << std::endl;
    printMatrix(moddifiedInputMatrix);
    std::vector<std::vector<double>> output = crossCorrelation(moddifiedInputMatrix, matrix2, bias);

    //Final step: Simply return the step.
    std::vector<std::vector<double>> inputOne = {
        {1,2},
        {3,4}
    };
    return output;
}
//Matrixes must be the same size
std::vector<std::vector<double>> matrixElementAdd(std::vector<std::vector<double>> matrix1, std::vector<std::vector<double>> matrix2){
    std::vector<std::vector<double>> result(matrix1.size(), std::vector(matrix1[0].size(), 0.0));

    for(int i = 0; i < matrix1.size(); i++){
        for(int j = 0; j < matrix1[i].size(); j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}



int main(){
    std::vector<std::vector<double>> inputOne = {
        {1,2},
        {3,4}
    };

    std::vector<std::vector<double>> inputTwo = {
        {1,2},
        {3,4}
    };
    //double bias = 7.0;

    std::vector<std::vector<double>> output = matrixElementAdd(inputOne, inputTwo);

    std::cout << "Result " << std::endl;
    printMatrix(output);

    return 0;
}
