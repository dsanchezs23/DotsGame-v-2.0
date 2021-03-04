#include "View.h"

void View::buildingField(GameField*& gameField){
    std::vector<AbstractField*> abstractFieldsVector = std::vector<AbstractField*>();
    menuForBuildingField(gameField);
}

void View::menuForBuildingField(GameField*& gameField){
    short int option = 0;
    while (option != 4) {
        system("cls");
        std::cout << "\t---Choose the amount of points to add to the field---\n";
        std::cout << "\n  1- Six points";
        std::cout << "\n  2- Nine points";
        std::cout << "\n  3- Fifteen points";
        std::cout << "\n  4- I'm ready!";
        std::cout << "\n\n  Option: ";
        try {
            if (std::cin >> option) {
                if (option > 0 && option < 5) {
                    //a correct option
                    switch (option){
                    case 1:
                        gameField->addAbstractField(new SixDots());
                        break;
                    case 2:
                        gameField->addAbstractField(new NineDots());
                        break;
                    case 3:
                        gameField->addAbstractField(new FifteenDots());
                        break;
                    case 4:
                        if (gameField->FieldsVectorIsEmpty()) {
                            option = 0;
                            throw std::out_of_range("Invalid option");
                        }
                        else{
                            break;
                        }                        
                    default:
                        break;
                    }                        
                }                   
                else {
                    throw std::out_of_range("Invalid option");
                }
            }
            else {
                throw std::bad_typeid();
            }
        }

        catch (std::out_of_range exception) {
            std::cout << "\n" << exception.what();
            Sleep(2000);
        }
        catch (std::bad_typeid exception) {
            std::cout << "\n" << exception.what();
            Sleep(2000);
            std::cin.clear();
            std::cin.ignore(255, '\n');
        }
    }

}

GenericPlayer* View::chooseTheOpponent(){
    short int option = 0;
    bool validation = true;
    while (validation) {
        system("cls");
        std::cout << "\t---Choose the opponent---\n";
        std::cout << "\n  1- Machine player";
        std::cout << "\n  2- User player";
        std::cout << "\n\n  Option: ";
        try {
            if (std::cin >> option) {
                if (option > 0 && option < 3) {
                    //a correct option
                    if (option == 1) {
                        return new MachinePlayer();
                    }
                    else {
                        return createUserPlayer();
                    }
                }
                else {
                    throw std::out_of_range("Invalid option");
                }
            }
            else {
                throw std::bad_typeid();
            }
        }

        catch (std::out_of_range exception) {
            std::cout << "\n" << exception.what();
            Sleep(2000);
        }
        catch (std::bad_typeid exception) {
            std::cout << "\n" << exception.what();
            Sleep(2000);
            std::cin.clear();
            std::cin.ignore(255, '\n');
        }
    }
    return nullptr;
}

Strategy* View::chooseStrategy(){
    short int option = 0;
    bool validation = true;
    while (validation) {
        system("cls");
        std::cout << "\t---Choose the machine's strategy---\n";
        std::cout << "\n  1- Random";
        std::cout << "\n  2- Close";
        std::cout << "\n  3- Island";
        std::cout << "\n  4- Core";
        std::cout << "\n  5- Peripheral";
        std::cout << "\n\n  Option: ";
        try {
            if (std::cin >> option) {
                if (option > 0 && option < 6) {
                    //a correct option
                    switch (option) {
                    case 1:
                        return new RandomStrategy();
                    case 2:
                        return new CloseStrategy();
                    case 3:
                        return new IslandStrategy();
                    case 4:
                        return new CoreStrategy();
                    case 5:
                        return new PeripheralStrategy();
                    default:
                        break;
                    }
                }
                else {
                    throw std::out_of_range("Invalid option");
                }
            }
            else {
                throw std::bad_typeid();
            }
        }

        catch (std::out_of_range exception) {
            std::cout << "\n" << exception.what();
            Sleep(2000);
        }
        catch (std::bad_typeid exception) {
            std::cout << "\n" << exception.what();
            Sleep(2000);
            std::cin.clear();
            std::cin.ignore(255, '\n');
        }
    }
    return nullptr;
}

void View::showFieldAndPoints(GameField*& gameField, GenericPlayer*& user, GenericPlayer*& opponent){
    system("cls");
    std::cout << gameField->toString();
    std::cout << "\n\n";
    std::cout << " \x1B[36m" + user->getName() + "\033[0m" << ": " << user->getPoints() << "\n";
    std::cout << " \x1B[31m" + opponent->getName() + "\033[0m" << ": " << opponent->getPoints() << "\n";
}

UserPlayer* View::createUserPlayer(){
    std::string name = "", id = "";
    std::cout << "\n- Write a name: ";
    std::cin >> name;
    std::cout << "\n\n- Write an id: ";
    std::cin >> id;
    if (name == "Machine") {
        name += "2";
    }
    return new UserPlayer(name, id);
}

void View::gameOver(GenericPlayer*& user, GenericPlayer*& opponent){
    std::cout << "\n\n---GAME OVER---";
    if (user->getPoints() > opponent->getPoints()) {
        std::cout << "\n\n" << user->getName() << " is the winner\n\n";
    }
    else if (opponent->getPoints() > user->getPoints()) {
        std::cout << "\n\n" << opponent->getName() << " is the winner\n\n";
    }
    else {
        std::cout << "\n\nIT'S A TIE!!!\n\n";
    }
}
