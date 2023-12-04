#pragma once
#include "./material_handler_abstract.hpp"

/// @brief Water handler class. I am sure we are aware of what water does
class WaterHandler: public MaterialHandler {
    public:
        // Constructor 
        WaterHandler(): MaterialHandler(){
            // Water colors 
            std::vector<Color> colors;
            colors.push_back({0,0,155});
            colors.push_back({0,0,180});
            colors.push_back({0,0,200});
            // Set the water colors 
            this->setMaterialColor(colors);
        }
};
