//
// Created by lumiayasuo on 2019-08-20.
//

#ifndef INTERVIEW_DOGCATQUEUE_H
#define INTERVIEW_DOGCATQUEUE_H

#endif //INTERVIEW_DOGCATQUEUE_H

#include <iostream>
#include <queue>

using namespace std;

class Pet {
private:
    string type;
public:
    Pet(const string &type) {
        this->type = type;
    }

    ~Pet() {}

    string getPetType() {
        return this->type;
    }
};

class Dog : public Pet {
public:
    Dog(const Pet &type) : Pet("dog") {

    }

    ~Dog() {}
};

class Cat : public Pet {
public:
    Cat(const Pet &type) : Pet("cat") {

    }

    ~Cat() {}
};

class PetEnterQueue {
private:
    Pet pet;
    long count;
public:
    PetEnterQueue(long count, const Pet &pet) : count(count), pet(pet) {
        this->pet = pet;
        this->count = count;
    }

    Pet getPet() {
        return this->pet;
    }

    long getCount() {
        return this->count;
    }

    string getEnterPetType() {
        return this->pet.getPetType();
    }
};

class DogCatQueue {
private:
    queue<PetEnterQueue> dogQ;
    queue<PetEnterQueue> catQ;
    long count;
public:
    DogCatQueue() {
        this->dogQ = queue<PetEnterQueue>();
        this->catQ = queue<PetEnterQueue>();
        this->count = 0;
    }

    void add(Pet *pet) {
        if ("dog" == pet->getPetType()) {
            this->dogQ.push(PetEnterQueue(this->count++, *pet));
        } else if ("cat" == pet->getPetType()) {
            this->catQ.push(PetEnterQueue(this->count++, *pet));
        } else {
            throw new runtime_error("err, not dog or cat");
        }
    }

    Pet pollAll() {
        if (!this->dogQ.empty() && !this->catQ.empty()) {
            if (this->dogQ.front().getCount() < this->catQ.front().getCount()) {
                Pet pet = this->dogQ.front().getPet();
                this->dogQ.pop();
                return pet;
            } else {
                Pet pet = this->catQ.front().getPet();
                this->catQ.pop();
                return pet;
            }
        } else if (!this->dogQ.empty()) {
            Pet pet = this->dogQ.front().getPet();
            this->dogQ.pop();
            return pet;
        } else if (!this->catQ.empty()) {
            Pet pet = this->catQ.front().getPet();
            this->catQ.pop();
            return pet;
        } else {
            throw runtime_error("err,queue is empty");
        }

    }

    Dog pollDog() {
        if (!isDogQueueEmpty()) {
            Dog dog = this->dogQ.front().getPet();
            this->dogQ.pop();
            return dog;
        } else {
            throw runtime_error("err,dog queue is empty");
        }
    }

    Cat pollCat() {
        if (!isCatQueueEmpty()) {
            Cat cat = this->catQ.front().getPet();
            this->catQ.pop();
            return cat;
        } else {
            throw runtime_error("err,cat queue is empty");
        }

    }

    bool empty() {
        return this->dogQ.empty() && this->catQ.empty();
    }

    bool isDogQueueEmpty() {
        return this->dogQ.empty();
    }

    bool isCatQueueEmpty() {
        return this->catQ.empty();
    }
};

int main() {
    
    DogCatQueue test;

    Pet *dog1 = new Dog(Pet("dog"));
    Pet *cat1 = new Cat(Pet("cat"));
    Pet *dog2 = new Dog(Pet("dog"));
    Pet *cat2 = new Cat(Pet("cat"));
    Pet *dog3 = new Dog(Pet("dog"));
    Pet *cat3 = new Cat(Pet("cat"));

    test.add(dog1);
    test.add(cat1);
    test.add(dog2);
    test.add(cat2);
    test.add(dog3);
    test.add(cat3);

    test.add(dog1);
    test.add(cat1);
    test.add(dog2);
    test.add(cat2);
    test.add(dog3);
    test.add(cat3);

    test.add(dog1);
    test.add(cat1);
    test.add(dog2);
    test.add(cat2);
    test.add(dog3);
    test.add(cat3);
    while (!test.isDogQueueEmpty()) {
        cout << (test.pollDog().getPetType()) << endl;
    }
    while (!test.empty()) {
        cout << (test.pollAll().getPetType()) << endl;
    }

    return 0;
}
