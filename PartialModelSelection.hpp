#pragma once
#include <iostream>
#include <map>
#include <vector>


enum class ModelCapMessages {NO_MODEL_CAP, STD_MODEL_CAP=3};



struct Model {
    Model(int model_size, double loss) : model_size(model_size), loss(loss) {}
    //Number of segments (k-value)
    int model_size = 0;
    //Loss associated with the given model 
    double loss = 0.0;
};


//Class to embody Model,Boolean pairs for model selection path records.
struct MinimizeResult {
    MinimizeResult();
    MinimizeResult(std::pair<double,double> inputRange, int model_size );
    bool isValidRange(std::pair<double,double> inputRange);
    int model_size = 0; //Not using currently, fulfilled by the modelPair
    bool certain = false;
    //Stores the potential models that could encompass a penalty query. Identical first and second value if certain (solved).
    std::pair<double, double> optimalModels;
};





//struct TestedPair may be better here for more readability
using TestedPair = std::pair<double, Model>;



class ModelSelectionMap {
public:
    //Method headers
    ModelSelectionMap();

    ModelSelectionMap(ModelCapMessages cap);

    void insert(double penalty, Model currentModel);

    void insert(Model currentModel);

    void addResult(MinimizeResult toAdd);

    double getNewPenaltyList();

    int getModelCount();
    
    std::pair<int, int> solver(double penalty);

    MinimizeResult minimize(double penalty);

    
    //Wrapper struct to contain a list of MinimizeResults
    std::vector<MinimizeResult> minResultVec; 

    ModelCapMessages maxModels = ModelCapMessages::NO_MODEL_CAP;
    std::map<double, Model> TestedPairs;
    int modelCount = 0;
};





