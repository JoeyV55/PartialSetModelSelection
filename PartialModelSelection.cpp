#include <iostream>
#include <map>
#include "PartialModelSelection.hpp"
#include <stdbool.h>
#include <stdexcept>
#include <vector>
#include <math.h>


/*MODEL SELECTION MAP IMPLEMENTATIONS*/

//Default contructor for model selection map, sets max models to std of 3.
ModelSelectionMap::ModelSelectionMap() : maxModels(ModelCapMessages::STD_MODEL_CAP)
{}

//Initialization constructor for a ModelSelectionMap with passed cap value.
ModelSelectionMap::ModelSelectionMap(ModelCapMessages cap) : maxModels(cap) {}

/*
Function name: insert
Algorithm: Inserts a new model into our partial set (map) data structure with a penalty modeling FPOP
Precondition: The model is formatted correctly and the
   penalty is a valid double.
Postcondition: Inserts the model into the data structure.
   No return type, maybe return success code eventually.
Exceptions: correctly and appropriately (without program failure)
    responds to and reports failure to insert the model.
Note: none
*/
void ModelSelectionMap::insert(double penalty, Model currentModel)
{
   //Insert into our TestedPair map in the ModelSelectionMap
   TestedPair newTestedPair = TestedPair(penalty, currentModel);
   //Insert into the MinimizeResult Vector to update ranges to test next.
   //std::pair <double,double> modelRange; 
   //modelRange = std::make_pair(penalty, penalty);
   //TestedPairs.insert(newTestedPair);
   modelCount++;

   //Insert a minimized result based on what we know.
   
   //Update the resultList to reflect the current path.
}

/*
Function name: insert
Algorithm: Inserts a new model into our partial set (map) without a penalty, modeling
   binary segmentation and other constrained style solvers. 
Precondition: The model is formatted correctly and the
   penalty is a valid double.
Postcondition: Inserts the model into the data structure.
   No return type, maybe return success code eventually.
Exceptions: correctly and appropriately (without program failure)
    responds to and reports failure to insert the model.
Note: none
*/
void ModelSelectionMap::insert(Model currentModel)
{
   //Runs solver for penalty to insert
   std::cout << "Adding model without penalty \n";

   //Insert pair with created TestedPair from solver.
}

/*
Function name: getNewPenalty
Algorithm: Acquires a penalty value lambda and returns a minimization result consisting of:
   (the k value corresponding to the selected model, a boolean showing its accuracy)
   Boolean values consist of: F for unsure, and T for a sure pairing.
Precondition: for correct operation, the passed penalty is a valid
   float value.
Postcondition: in correct operation, computes what model is optimal
   for the passed penalty, and gives a boolean signifying its accuracy.
   Both these values are passed back as a struct.
Exceptions: none?
Note: none
*/
double ModelSelectionMap::getNewPenaltyList()
{

   MinimizeResult *currentResult;
   //Search through the minimizeResult list, seeing where we have "certain" values to query next with solver.
   //Use loop (for?) and an iterator of the map. Start at the head. 
   //while(currentResult != NULL) {
   //Traverse and check for useful penalty ranges to query.

   //}
   return 0;
}

/*
Function name: Minimize
Algorithm: Acquires a penalty value lambda and returns a minimization result consisting of:
   (the k value corresponding to the selected model, a boolean showing its accuracy)
   Boolean values consist of: F for unsure, and T for a sure pairing.
Precondition: for correct operation, the passed penalty is a valid
   float value.
Postcondition: in correct operation, computes what model is optimal
   for the passed penalty, and gives a boolean signifying its accuracy.
   Both these values are passed back as a struct.
Exceptions: none?
Note: none
*/
MinimizeResult ModelSelectionMap::minimize(double penalty)
{
   //Temporary stub result to return and compile.
   MinimizeResult queryResult = MinimizeResult();
   

   //Temporary stub return
   return queryResult;
}

//Add minimize result function for LL?
void ModelSelectionMap::addResult(MinimizeResult toAdd)
{
 std::cout << "Adding result to vector\n";
}



//MinimizeResult Methods
MinimizeResult::MinimizeResult(){
 //Initialize a default result, which has 1 selected, but unsure.
 optimalModels.first = 1;
 optimalModels.second = INFINITY;
 certain = false;

}

MinimizeResult::MinimizeResult(std::pair<double, double> modelRange, int model_size)
   {
       if(!isValidRange(modelRange))
          {
           throw "Invalid range inputted to MinimizeResult creation.";
          }

       else
          {
           //Check if our penaltyRange is a solved point (Where the beginning and end are identical.)
           if(modelRange.first == modelRange.second)
              {
               certain = true;
              }
            modelRange.first

          }
       
      
   }


bool MinimizeResult::isValidRange(std::pair<double,double> modelRange)
   {
    //Tie a model size and pairing to a penalty range.
    if(modelRange.first < 0 || modelRange.first > modelRange.second)
       {
        return false;   
       }
    return true;
   }


/*
Function name: Solver
Algorithm:

Precondition: for correct operation, the passed penalty is a valid
   float value.
Postcondition:
Exceptions: none yet. 
Note: none
*/
std::pair<int, int> ModelSelectionMap::solver(double penalty)
{
   auto tempPair = std::make_pair<int, bool>(4, true);
   std::cout << "Testing solver!\n";
   //Temporary stub return
   return tempPair;
}



//Basic getters/setters
int ModelSelectionMap::getModelCount()
{
 return modelCount;

}

