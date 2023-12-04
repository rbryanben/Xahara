#include "../utils/colors.hpp"
#include "./water_handler.cpp"
#include "./material_struct.hpp"

// This method manages materials 
class MaterialManager {
    private:
        WaterHandler waterHandler;
    public:
        // Constructor 
        MaterialManager(){
            // Instantiate handlers
            this->waterHandler = WaterHandler();
        }

        // Methods 
        Color getMaterialColor(Material material);
};

// Get the color of a material 
Color MaterialManager::getMaterialColor(Material material){
    // Water 
    if (material.material_id == 1){
        return this->waterHandler.getMaterialColor();
    }

    // Display red
    return {255,0,0};
}
