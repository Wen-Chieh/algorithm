class TOWER{
private:
    string name;
    vector<int> pile;
public:
    TOWER(string towerName): name(towerName){}
    void addToTower(int number){
        pile.push_back(number);
    }
    void removeFromTower(){
        pile.pop_back();
    }
    void printTower(){
        int size = pile.size();
        cout<< name<<": ";
        for(int i = 0; i < size; i++){
            cout<< pile[i]<<", ";
        }
        cout<<endl;
    }
    int getTop(){
        return pile.back();
    }
    size_t getSize(){
        return pile.size();
    }
    string getName(){
        return name;
    }
};

class HANOI{
private:
    void helper(TOWER& ori, TOWER& buf, TOWER& dest, size_t moveNum){
        if(moveNum == 0)    return;
        if(moveNum == 1){
            dest.addToTower(ori.getTop());
            ori.removeFromTower();
            return;
        }
        
        helper(ori, dest, buf, moveNum - 1);
        helper(ori, buf, dest, 1);
        helper(buf, ori, dest, moveNum - 1);
    }
public:
    void printHanoi(TOWER& ori, TOWER& buf, TOWER& dest){
        ori.printTower();
        buf.printTower();
        dest.printTower();
    }
    void moveHanoi(TOWER& ori, TOWER& buf, TOWER& dest){
        helper(ori, buf, dest, ori.getSize());
    }
};