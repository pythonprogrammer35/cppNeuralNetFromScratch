#pragma once 
class Layer{
    public:
        Layer(){}

        

        virtual std::string getName() { return "Generic Layer"; }
        virtual ~Layer() {}
};
