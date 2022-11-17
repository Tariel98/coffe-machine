#include <iostream>

struct Transaction{
    std::string name;
    int price;
};

class CoffeeMachine
{
    private:
       std::string coffeeNames[10];
       int coffeePrices[10];
    public:
        CoffeeMachine()
            :coffeeNames{"Dark Coffe", "Americano", "Kapuchino", "Mokachino", 
                        "Late", "Neskafe", "Hot Chocolade", "Jacobs", "Jacobs 3 in 1", "Glasse" },
            coffeePrices{100,200,200,200,250,250,200,250,300, 400}{};

        CoffeeMachine(std::string names[], int prices[]){
                for(int i=0; i<10; ++i){
                    coffeeNames[i] = names[i];
                    coffeePrices[i] = prices[i];
                }
        }

        void printPriceList(){
            for(int i=0; i<10; ++i){
                std::cout << "==================================================" << std::endl;
                std::cout << coffeeNames[i] << ":\t" << coffeePrices[i] << std::endl; 
            }
                std::cout << "==================================================" << std::endl;

        }

        Transaction input(Transaction order){
            for(int i=0; i<10; ++i){
                if (order.name == coffeeNames[i]){
                    if (order.price >= coffeePrices[i]){
                        order.price -= coffeePrices[i];
                        order.name += ": \nYour money: ";
                        return order;
                    }else {
                        order.name = "Transaction Failed։ Low Balance";
                        return order;
                    }
                }
            }
            order.name = "This product does not exist! Your balance is: ";
            return order;
        }
};

int main() {

    Transaction name{"Glasse", 1000};
    CoffeeMachine coffee;
    coffee.printPriceList();

    Transaction result = coffee.input(name);

    std::cout << result.name << " " << result.price << std::endl;

    std::string names[] = {"Espresso", 
                            "Doppio", 
                            "Americano", 
                            "Espereso Lungo", 
                            "Ristretto", 
                            "Cortado", 
                            "Late", 
                            "Cappuchino", 
                            "Macchiato", 
                            "Iced Coffe"};

    int prices[] = {100, 200, 200, 300, 500, 500, 500, 200, 350, 250};

    Transaction order{"Cortado", 800};

    CoffeeMachine coffeemachine(names, prices);

    coffeemachine.printPriceList();

    Transaction result2 = coffeemachine.input(order);

    std::cout << result2.name << " " << result2.price << std::endl;
     
}
