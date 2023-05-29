class ParkingSystem {
private:
    int big, medium, small;
public:
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }
    
    bool addCar(int carType) {
        switch (carType)
        {
            case 1:
                if (big <= 0)
                    break;
                big--;
                return true;
            case 2:
                if (medium <= 0)
                    break;
                medium--;
                return true;
            case 3:
                if (small <= 0)
                    break;
                small--;
                return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */