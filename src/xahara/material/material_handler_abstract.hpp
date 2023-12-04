#pragma once
#include "../utils/utils.h"
#include <vector>

/// @brief: Material handles handles things like
///            - Returning the color of a material, which could be from many materials 
///            - What to do next from a current position
///            - Transformations into another material 
class MaterialHandler {
    private: 
        // Material color 
        std::vector<Color> materialColors;

    public:
        // Methods 
        void setMaterialColor(std::vector<Color> colors);
        Color getMaterialColor();
};

/// @brief Set the material color 
void MaterialHandler::setMaterialColor(std::vector<Color> colors){
    this->materialColors = colors;
}

/// @brief Returns a single color from the colors list
/// @todo return a random selection
/// @return Color  
Color MaterialHandler::getMaterialColor(){
    return this->materialColors.front();
}
