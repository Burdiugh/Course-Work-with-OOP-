#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class Electronics {
	string name;
	string model;
	string type;
	int price;
public:
	Electronics();
	Electronics(string n, string m, string t, int p);
	virtual void Print()const; 
	string GetName()const;
	string GetModel()const;
	string GetType()const;
	int GetPrice()const;
	void SetModel(string model);
	void SetName(string name);
	void SetPrice(int price);
	void SetPriceForDiscount(int value);
	void RemoveInfoExeptModel();
	virtual ifstream& Load(ifstream& in);
	virtual ofstream& Save(ofstream& out);
	bool operator<(Electronics& e);
};
inline string Electronics::GetName()const { return name; }
inline string Electronics::GetModel()const { return model; }
inline string Electronics::GetType()const { return type; }
inline int Electronics::GetPrice()const { return price; }




