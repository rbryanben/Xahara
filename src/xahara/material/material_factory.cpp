#include "./material_struct.hpp"

class MaterialFactory{
    //Public attributes 
    public:
        // Create Water 
        static Material createWater();

        // Create Air
        static Material createAir();
};

/// @brief Creates water
/// @return Water
Material MaterialFactory::createWater(){
    return {
        1, // Material id 
        0 // Velocity 
    };
}

/// @brief Creates air
/// @return Air
Material MaterialFactory::createAir(){
    return {
        0, // Material id 
        0 // Velocity 
    };
}