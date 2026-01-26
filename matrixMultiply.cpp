#include <iostream>
#include <vector>


std::vector<std::vector<double>> matrixMult(std::vector<std::vector<double>> vector1, std::vector<std::vector<double>> vector2){
    std::vector<double> vect1;
    std::vector<double> vect2;
    double holder = 0;
    std::vector<std::vector<double>> result(vector1.size(), std::vector<double>(vector2[0].size(), 0));

    // for every row in vector1, go through every value in every column of vector2
    for(int i = 0; i<vector1.size(); i++){
        vect1 = vector1[i];
        for(int j = 0; j<vector2[0].size(); j++){
            //This part is where the calculation is run
            for(int k = 0; k < vector2.size(); k++){
                holder += vect1[k] * vector2[k][j];
            }
            result[i][j] = holder;
            holder = 0;
        }
    }
    return result;
}

std::vector<std::vector<double>> biasAdd(std::vector<std::vector<double>> vector1, std::vector<double> vector2){
    std::vector<std::vector<double>> result = vector1;

    for (int i = 0; i<vector1.size(); i++){
        for(int j = 0; j<vector1[0].size(); j++){
            vector1[i][j] += vector2[j];
        }
    }
    return result;
}
/*
int main(){
    std::vector<std::vector<double>> tester1 = {
        {3,2,1},
        {4,3,2}
        
    };
    std::vector<std::vector<double>> tester2 = {
        {1,4,2},
        {2,6,2},
        {3,3,2}
    };
    std::vector<std::vector<double>> output = matrixMult(tester1, tester2);

    std::string holder = "";
    std::string holder2 = "{";
    for (int i = 0; i<output.size(); i++){
        for(int j = 0; j<output[0].size(); j++){
            holder2 += std::to_string(output[i][j]);
            holder2 += ",";
        }
        holder += holder2;
        holder += "}";
        holder2 = "{";
    }
    std::cout << holder;
}*/
