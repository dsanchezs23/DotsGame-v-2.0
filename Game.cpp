#include "Game.h"

bool Game::isGameOver(){
    return thereIsAvailableSpaces();
}

bool Game::isSquareMade(){
    return false;
}

bool Game::thereIsAvailableSpaces(){
    return false;
}

Game::Game(){
    this->gameField = new GameField();
    this->user = nullptr;
    this->opponent = nullptr;
}

Game::~Game(){
    delete this->gameField;
    delete this->user;
    delete this->opponent;
}

void Game::start(){
    this->user = View::createUserPlayer();
    this->user->setStrategy(new UserStrategy());
    buildTheField();
    chooseTheOpponent();
    if (this->opponent->getName() == "Machine") {
        chooseStrategy();
    }
    else {
        this->opponent->setStrategy(new UserStrategy(true));
    }
    play();
}

void Game::chooseTheOpponent(){
    this->opponent = View::chooseTheOpponent();
}

void Game::vsMachine(){
    while (this->gameField->getAmountOfMovement() != 0) {
        View::showFieldAndPoints(this->gameField, this->user, this->opponent);
        this->user->setMoveDone(false);
        while (!this->user->isMoveDone()) {
            this->user->play(this->gameField, user);
            View::showFieldAndPoints(this->gameField, this->user, this->opponent);
        }
        this->gameField->addAmounOfMovement(-1); //to decrease the movement

        if (this->gameField->getAmountOfMovement() != 0) {
            this->opponent->play(this->gameField, opponent);
            this->gameField->addAmounOfMovement(-1); //to decrease the movement
        }
    }
}

void Game::vsPlayer(){
    while (this->gameField->getAmountOfMovement() != 0) {
        View::showFieldAndPoints(this->gameField, this->user, this->opponent);
        this->user->setMoveDone(false);
        while (!this->user->isMoveDone()) {
            this->user->play(this->gameField, user);
            View::showFieldAndPoints(this->gameField, this->user, this->opponent);
        }
        this->gameField->addAmounOfMovement(-1); //to decrease the movement

        if (this->gameField->getAmountOfMovement() != 0) {
            View::showFieldAndPoints(this->gameField, this->user, this->opponent);
            this->opponent->setMoveDone(false);
            while (!this->opponent->isMoveDone()) {
                this->opponent->play(this->gameField, opponent);
                View::showFieldAndPoints(this->gameField, this->user, this->opponent);
            }            
            this->gameField->addAmounOfMovement(-1); //to decrease the movement
        }
    }
}

void Game::play(){
    if (this->opponent->getName() == "Machine") {
        vsMachine();
    }
    else {
        vsPlayer();
    }

    View::gameOver(this->user, this->opponent);
}

void Game::chooseStrategy(){
    if (this->opponent->getName() == "Machine") {
        this->opponent->setStrategy(View::chooseStrategy());
    }
    else {
        this->opponent->setStrategy(new UserStrategy());
    }
}

void Game::buildTheField(){
    View::buildingField(this->gameField);
    this->gameField->createField();
}
