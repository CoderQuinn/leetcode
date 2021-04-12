//
//  1603 Design Parking System.cpp
//  Leetcode
//
//  Created by Quinn on 2021/3/20.
//  Copyright © 2021 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class ParkingSystem {
public:
    vector<int> tot;

    ParkingSystem(int big, int medium, int small) {
        tot = {0, big, medium, small};
    }
    
    bool addCar(int carType) {
        if(tot[carType] > 0) {
            tot[carType]--;
            return true;
        } else {
            return false;
        }
    }
};
