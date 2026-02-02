#pragma once
#include <vector>

using Vector2D = std::vector<std::vector<double>>;
using Vector3D = std::vector<std::vector<std::vector<double>>>;
using Vector4D = std::vector<std::vector<std::vector<std::vector<double>>>>;

class Layer{
    public:
        Layer(){}

        virtual Vector2D forward(Vector2D input){
            Vector2D holder;
            return holder;
        };
    
        virtual Vector2D backward(Vector2D output_gradient, double learning_rate){
            Vector2D holder;
            return holder;
        }

        //4D functions(for Convolution)
        
        virtual Vector4D forward(Vector4D input){
            Vector4D holder;
            return holder;
        };
    
        virtual Vector4D backward(Vector4D output_gradient, double learning_rate){
            Vector4D holder;
            return holder;
        }

        virtual std::string getName() { return "Generic Layer"; }
        virtual ~Layer() {}
};
