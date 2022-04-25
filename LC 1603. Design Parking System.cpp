class ParkingSystem {
public:
    int b = 0, m = 0, s = 0;
    ParkingSystem(int big, int medium, int small) {
        b = big;
        m = medium;
        s = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
            if(b == 0){
                return false;
            }
            b--;
        }
        else if(carType == 2){
            if(m == 0){
                return false;
            }
            m--;
        }
        else{
            if(s == 0){
                return false;
            }
            s--;
        }
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
