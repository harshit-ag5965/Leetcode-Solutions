class Solution {
public:
    std::string destCity(std::vector<std::vector<std::string>>& paths) {
        std::unordered_set<std::string> startingCities;
        
        // Step 1: Collect all cities that have an outgoing path (cityA)
        for (const auto& path : paths) {
            startingCities.insert(path[0]);
        }
        
        // Step 2: Find the destination city (cityB) that never acts as a starting city
        for (const auto& path : paths) {
            std::string destination = path[1];
            if (startingCities.find(destination) == startingCities.end()) {
                return destination;
            }
        }
        
        return "";
    }
};