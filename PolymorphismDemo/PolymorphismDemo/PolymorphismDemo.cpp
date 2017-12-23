// PolymorphismDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

//Ad-hoc Polymorphism (overloading)
int GetSize(int x) 
{
   return x;
}

int GetSize(std::string x)
{
   return x.length();
}

class Animal
{
public:
   virtual void MakeNoise()
   {
      std::cout << "Animal noise!" << std::endl;
   }
};

class Dog : public Animal
{
public:
   void MakeNoise() override
   {
      std::cout << "Woof, Bark-Yipe!" << std::endl;
   }
};

class Cat : public Animal
{
public:
   void MakeNoise() override
   {
      std::cout << "Meow!" << std::endl;
   }
};

//Subtype Polymorphism
void Stroke(Animal& animal)   //or Animal* animal
{
   animal.MakeNoise();        //or animal->MakeNoise()
}


int main()
{
   std::cout << GetSize(5) << std::endl;
   std::cout << GetSize("Hello World!") << std::endl;

   Dog dog;
   Cat cat;
   Stroke(dog);   //or &dog
   Stroke(cat);   //or &cat

    return 0;
}

