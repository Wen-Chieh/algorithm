class sales_item{
    int foodPrice;
    int drinkPrice;
public:
    sales_item():foodPrice(0), drinkPrice(0){}
    sales_item(int food, int drink): foodPrice(food), drinkPrice(drink){}
    sales_item(istream& is){
        cout<<"Enter food price: ";
        is>>this->foodPrice;
        cout<<"Enter drink price: ";
        is>>this->drinkPrice;
    }
    sales_item operator+(const sales_item& item2){
        sales_item item;
        item.foodPrice = this->foodPrice + item2.foodPrice;
        item.drinkPrice = this->drinkPrice + item2.drinkPrice;
        return item;
    }
    
    sales_item operator>>(int shiftNum){
        sales_item item;
        item.foodPrice  = this->foodPrice >> shiftNum;
        item.drinkPrice = this->drinkPrice >> shiftNum;
        return item;
    }
    
    bool operator==(const sales_item& item){
        if((drinkPrice == item.drinkPrice) && (foodPrice == item.foodPrice))  return true;
        else return false;
    }
    /*
    sales_item& operator=(const sales_item& item2){
        this->foodPrice = item2.foodPrice;
        this->drinkPrice = item2.drinkPrice;
        return *this;
    }*/
    
    friend ostream& operator<<(ostream& os, const sales_item& item);
    friend istream& operator>>(istream& is, sales_item& item);
};

ostream& operator<<(ostream& os, const sales_item& item){
    os<<"Food price: "<<item.foodPrice<<", Drink price: "<<item.drinkPrice<<endl;
    return os;
}

istream& operator>>(istream& is, sales_item& item){
    is >> item.foodPrice >> item.drinkPrice;
    return is;
}