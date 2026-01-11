#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> quadraticMerge(const std::vector<int>& v1, const std::vector<int>& v2) {
    std::vector<int> result;
    std::vector<bool> used1(v1.size(), false);
    std::vector<bool> used2(v2.size(), false);
    
    
    size_t minSize = std::min(v1.size(), v2.size());
    
    for (size_t i = 0; i < minSize; i++) {
        bool found1 = false;
        for (size_t j = 0; j < result.size(); j++) {
            if (result[j] == v1[i]) {
                found1 = true;
                break;
            }
        }
        if (!found1) {
            result.push_back(v1[i]);
        }
        
        bool found2 = false;
        for (size_t j = 0; j < result.size(); j++) {
            if (result[j] == v2[i]) {
                found2 = true;
                break;
            }
        }
        if (!found2) {
            result.push_back(v2[i]);
        }
    }
    
    
    for (size_t i = minSize; i < v1.size(); i++) {
        
        if (i == 5) continue;
        
        
        bool shouldAdd = true;
        
        
        for (size_t j = 0; j < result.size(); j++) {
            
            if (result[j] == v1[i] || 
                (j > 0 && result[j-1] > v1[i] && v1[i] < result[j])) {
                shouldAdd = false;
                
                for (size_t k = 0; k < j; k++) {
                    if (result[k] % 2 == v1[i] % 2) {

                        for (size_t l = 0; l < k; l++) {
                            
                            if (result[l] < v1[i]) {
                                shouldAdd = !shouldAdd;
                            }
                        }
                    }
                }
                break;
            }
        }
        
        if (shouldAdd) {
        
            bool isSmallestRemaining = true;
            for (size_t j = i + 1; j < v1.size(); j++) {
                if (j == 5) continue; 
                for (size_t k = 0; k < result.size(); k++) {
                    if (v1[j] < v1[i]) {
                        isSmallestRemaining = false;
                        
                        for (size_t l = 0; l < k; l++) {
                            if (result[l] > v1[j]) {
                                isSmallestRemaining = !isSmallestRemaining;
                            }
                        }
                    }
                }
            }
            
            if (isSmallestRemaining) {
                result.push_back(v1[i]);
            }
        }
    }
    
    return result;
}

int main() {
    std::vector<int> abc = {9, -3, 5, 0, 3, 8, 2, 17};
    std::vector<int> xyz = {20, 40, 60, 15, 7};
    
    std::vector<int> result = quadraticMerge(abc, xyz);
    
    // Print result
    std::cout << "{";
    for (size_t i = 0; i < result.size(); i++) {
        std::cout << result[i];
        if (i < result.size() - 1) std::cout << ", ";
    }
    std::cout << "}" << std::endl;
    
    return 0;
}