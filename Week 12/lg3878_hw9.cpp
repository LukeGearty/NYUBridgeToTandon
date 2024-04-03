#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

//consts
const int WORLD_SIZE = 20; 
const char ANT_CHAR = 'o';
const char BUG_CHAR = 'X';
const char EMPTY_CHAR = '-';
const int ANT_AMOUNT = 100;
const int BUG_AMOUNT = 8;
const int ANT_STEPS_BREED = 3;
const int BUG_STEPS_TO_BREED = 8;
const int BUG_STEPS_TO_STARVE = 3;


const int UP = 0;
const int DOWN = 1;
const int RIGHT = 2;
const int LEFT = 3;

struct Position {
    int row, column;
};

class World;

class Organism {
private:
    char BreedChar;
    int StepsAlive;
    int StepsToBreed;
    Position Pos;
    bool RecentlyMoved;
public:
    Organism(char breed, int stepsBreed, Position pos);
    void setBreed(char breed);
    char getBreed() const;
    void setStepsBreed(int steps);
    int getStepsBreed() const;
    void setStepsAlive(int stepsAlive);
    int getStepsAlive() const;
    void setPos(Position& pos);
    Position getDirection(World& world);
    vector <Position> availablePositions(Position &currPos);
    Position getPos() const;
    bool canBreed();
    void setRecentlyMoved(bool moveValue);
    bool getRecentMoved() const;
    bool validMove(Position &pos) const;
    bool checkSteps(int &steps) const;
    virtual void move(World &world) {}
    void breed(World &world, Position &currPos);
};

class Ant : public Organism {
public:
    Ant(Position pos);
    void move(World &world);
};

class Doodlebug : public Organism {
private:
    int StepsSinceEaten;
public:
    Doodlebug(Position pos);
    void setStepsStarve(int stepsStarve);
    void setRecentlyEaten(int stepsSinceEaten);
    int getRecentlyEaten() const;
    void move(World &world);
};


class World {
private:
    int TimePassed;
    Organism* grid[WORLD_SIZE][WORLD_SIZE]; //a grid of organisms
public:
    World();
    ~World();
    World(const World &other);
    World& operator=(const World &other);
    bool spaceIsEmpty(Position &pos);
    void printWorld();
    void setTime(int time);
    int getTime() const;
    void setOrganism(Organism& org, Position &currPos);
    void antDies(Position &pos);
    void bugDies(Organism& org);
    void hasMoved(Position &newPos, Position &formerPos);
    bool thereIsAnAnt(Position &pos) const;
    void timePasses();
};

int main() {
    srand(time(0));
    World world;
    do {
        cout << "World at Time: " << world.getTime() << endl;
        world.printWorld();
        world.timePasses();
        cout << "Press ENTER to continue, or press any other key and then enter to exit: ";
    } while (cin.get() == '\n');

    return 0;
}

Organism::Organism(char breed, int stepsBreed, Position pos) {
    BreedChar = breed;
    StepsToBreed = stepsBreed;
    Pos = pos;
    StepsAlive = 0;
    RecentlyMoved = false;
}

void Organism::setBreed(char breed) {
    BreedChar = breed;
}

char Organism::getBreed() const {
    return BreedChar;
}

void Organism::setStepsBreed(int steps) {
    StepsToBreed = steps;
}

int Organism::getStepsBreed() const {
    return StepsToBreed;
}

void Organism::setStepsAlive(int stepsAlive) {
    StepsAlive = stepsAlive;
}

int Organism::getStepsAlive() const {
    return StepsAlive;
}

void Organism::setPos(Position& pos) {
    Pos = pos;
}

Position Organism::getPos() const {
    return Pos;
}

Position Organism::getDirection(World& world) {
    Position currPos = getPos();
    vector <Position> candidates = availablePositions(currPos);
    vector <Position> emptySpaceCandidates;
    if (!candidates.empty()) {
        for (int i = 0; i < candidates.size(); i++) {
            if (world.spaceIsEmpty(candidates[i])) {
                emptySpaceCandidates.push_back(candidates[i]);
            }
        }

        if (!emptySpaceCandidates.empty()) {
            int randPick = (rand() % emptySpaceCandidates.size());
            return emptySpaceCandidates[randPick];
        }
        else {
            return currPos;
        }
    }
    else {
        return currPos;
    }
}

vector <Position> Organism::availablePositions(Position &currPos) {
    Position up, down, left, right;
    vector <Position> available;
    up.row = currPos.row - 1, up.column = currPos.column;
    if (validMove(up)) {
        available.push_back(up);
    }
    down.row = currPos.row + 1, down.column = currPos.column;
    if (validMove(down)) {
        available.push_back(down);
    }
    left.row = currPos.row, left.column = currPos.column - 1;
    if (validMove(left)) {
        available.push_back(left);
    }
    
    right.row = currPos.row, right.column = currPos.column + 1;
    if (validMove(right)) {
        available.push_back(right);
    }
    return available;
}

bool Organism::validMove(Position &pos) const {
    if (pos.row < 0 || pos.row > WORLD_SIZE - 1) {
        return false;
    } 
    else if (pos.column < 0 || pos.column > WORLD_SIZE - 1) {
        return false;
    }
    else {
        return true;
    }
}

void Organism::setRecentlyMoved(bool moveValue) {
    RecentlyMoved = moveValue;
}

bool Organism::getRecentMoved() const {
    return RecentlyMoved;
}

bool Organism::canBreed() {
    int stepsAlive = getStepsAlive();
    int breed = getStepsBreed();

    if (stepsAlive >= breed) {
        stepsAlive = 0;
        setStepsAlive(stepsAlive);
        return true;
        
    }
    else {
        return false;
    }
}

void Organism::breed(World &world, Position& currPos) {
    vector <Position> candidates = availablePositions(currPos);
    if (!candidates.empty()) {
        for (int i = 0; i < candidates.size(); i++) {
            if (validMove(candidates[i]) && world.spaceIsEmpty(candidates[i])) {
                world.setOrganism(*this, candidates[i]);
            }
        }
    }
}

Ant::Ant(Position pos) :Organism(ANT_CHAR, ANT_STEPS_BREED, pos) {}

void Ant::move(World &world) {
    int stepsAlive = getStepsAlive();
    stepsAlive++;
    Position currPos = getPos();

    Position newPos = getDirection(world);
    if (validMove(newPos) && world.spaceIsEmpty(newPos)) {
        world.hasMoved(newPos, currPos);
        setPos(newPos);
        setStepsAlive(stepsAlive);
        setRecentlyMoved(true);
    }
} 


Doodlebug::Doodlebug(Position pos) :Organism(BUG_CHAR, BUG_STEPS_TO_BREED, pos) { 
    StepsSinceEaten = 0;
}

void Doodlebug::setRecentlyEaten(int stepsSinceEaten) {
    StepsSinceEaten = stepsSinceEaten;
}

int Doodlebug::getRecentlyEaten() const {
    return StepsSinceEaten;
}

void Doodlebug::move(World& world) {
    bool willEat = false;
    int stepsAlive = getStepsAlive();
    stepsAlive++;
    int stepsSinceEaten = getRecentlyEaten();
    stepsSinceEaten++;
    Position currPos = getPos();
    Position newPos;
    vector <Position> allAround = availablePositions(currPos);
    if (!allAround.empty()) {
        Position antPos;
        for (int i = 0; i < allAround.size(); i++) {
            if (world.thereIsAnAnt(allAround[i])) {
                antPos = allAround[i];
                willEat = true;
            }
        }
        if (willEat == true) {
            stepsSinceEaten = 0;
            world.antDies(antPos);
            world.hasMoved(antPos, currPos);
            setPos(antPos);
            setStepsAlive(stepsAlive);
            setRecentlyMoved(true);
            setRecentlyEaten(stepsSinceEaten);
            return;
        }
    }

    newPos = getDirection(world);
    if (validMove(newPos) && world.spaceIsEmpty(newPos)) {
        world.hasMoved(newPos, currPos);
        setPos(newPos);
        setStepsAlive(stepsAlive);
        setRecentlyMoved(true);
    }
    if (stepsSinceEaten > BUG_STEPS_TO_STARVE) {
        world.bugDies(*this);
    }
    else {
        setRecentlyEaten(stepsSinceEaten);
    }
}

World::World() {
    TimePassed = 0;
    for (int i = 0; i < WORLD_SIZE; i++) {
        for (int j = 0; j < WORLD_SIZE; j++) {
            grid[i][j] = nullptr;
        }
    }
    for (int i = 0; i < ANT_AMOUNT; i++) {
        Position currPos;
        currPos.row = (rand() % WORLD_SIZE);
        currPos.column = (rand() % WORLD_SIZE);
        while (!spaceIsEmpty(currPos)) {
            currPos.row = (rand() % WORLD_SIZE);
            currPos.column = (rand() % WORLD_SIZE);
        }
        grid[currPos.row][currPos.column] = new Ant(currPos);
    }
    for (int i = 0; i < BUG_AMOUNT; i++) {
        Position currPos;
        currPos.row = (rand() % WORLD_SIZE);
        currPos.column = (rand() % WORLD_SIZE);
        while (!spaceIsEmpty(currPos)) {
            currPos.row = (rand() % WORLD_SIZE);
            currPos.column = (rand() % WORLD_SIZE);
        }
        grid[currPos.row][currPos.column] = new Doodlebug(currPos);
    }
}

World::~World() {
    for (int i = 0; i < WORLD_SIZE; i++) {
        for (int j = 0; j < WORLD_SIZE; j++) {
            delete grid[i][j];
        }
    }
}

World::World(const World &other) {
    this->TimePassed = other.TimePassed;
    for (int i = 0; i < WORLD_SIZE; i++) {
        for (int j = 0; j < WORLD_SIZE; j++) {
            grid[i][j] = other.grid[i][j];
        }
    } 
}

World& World::operator=(const World &other) {
    return *this;
}

bool World::spaceIsEmpty(Position &pos) {
    if (grid[pos.row][pos.column] == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

void World::printWorld() {
    for (int i = 0; i < WORLD_SIZE; i++) {
        for (int j = 0; j < WORLD_SIZE; j++) {
            if (grid[i][j] == nullptr) {
                cout << EMPTY_CHAR << " ";
            }
            else {
                cout << grid[i][j]->getBreed() << " ";
            }
        }
        cout << endl;
    }
}

void World::setTime(int time) {
    TimePassed = time;
}

int World::getTime() const {
    return TimePassed;
}

void World::setOrganism(Organism& org, Position &newPos) {
    if (org.getBreed() == ANT_CHAR) {
        grid[newPos.row][newPos.column] = new Ant(newPos);
    }
    else if (org.getBreed() == BUG_CHAR) {
        grid[newPos.row][newPos.column] = new Doodlebug(newPos);
    }
}

void World::hasMoved(Position &newPos, Position &formerPos) {
    grid[newPos.row][newPos.column] = grid[formerPos.row][formerPos.column];
    grid[formerPos.row][formerPos.column] = nullptr;
}

void World::bugDies(Organism& org) {
    Position bugPos = org.getPos();
    delete [] grid[bugPos.row][bugPos.column];
    grid[bugPos.row][bugPos.column] = nullptr;
}

bool World::thereIsAnAnt(Position &pos) const {
    if (grid[pos.row][pos.column] != nullptr && grid[pos.row][pos.column]->getBreed() == ANT_CHAR) {
        return true;
    }
    else {
        return false;
    }
}

void World::antDies(Position &pos) {
    delete [] grid[pos.row][pos.column];
    grid[pos.row][pos.column] = nullptr;
}

void World::timePasses() {
    TimePassed++;
    //Doodlebugs first
    for (int i = 0; i < WORLD_SIZE; i++) {
        for (int j = 0; j < WORLD_SIZE; j++) {
            if (grid[i][j] != nullptr && grid[i][j]->getBreed() == BUG_CHAR) {
                if (grid[i][j]->getRecentMoved() == false) { 
                    grid[i][j]->move(*this);
                }
            }
        }
    }
    //now the ants
    for (int i = 0; i < WORLD_SIZE; i++) {
        for (int j = 0; j < WORLD_SIZE; j++) {
            if (grid[i][j] != nullptr && grid[i][j]->getBreed() == ANT_CHAR) {
                if (grid[i][j]->getRecentMoved() == false) {
                    grid[i][j]->move(*this);
                        
                }
            }
        }
    }
    //reset the recently moved variable
    for (int i = 0; i < WORLD_SIZE; i++) {
        for (int j = 0; j < WORLD_SIZE; j++) {
            if (grid[i][j] != nullptr) {
                grid[i][j]->setRecentlyMoved(false);
            }
        }
    }
    //and check if they can breed
    for (int i = 0; i < WORLD_SIZE; i++) {
        for (int j = 0; j < WORLD_SIZE; j++) {
            if (grid[i][j] != nullptr) {
                if (grid[i][j]->canBreed()) {
                    Position currPos = grid[i][j]->getPos();
                    grid[i][j]->breed(*this, currPos);
                }
            }
        }
    }
}
