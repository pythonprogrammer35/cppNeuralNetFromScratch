#pragma once
class Layer{
    public:
        Layer(){}

        virtual std::vector<std::vector<double>> forward(std::vector<std::vector<double>> input) = 0;
    
        virtual std::vector<std::vector<double>> backward(std::vector<std::vector<double>> output_gradient, double learning_rate) = 0;

        virtual std::string getName() { return "Generic Layer"; }
        virtual ~Layer() {}
};
