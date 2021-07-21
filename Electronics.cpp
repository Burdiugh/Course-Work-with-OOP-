#include "Electronics.h"

Electronics::Electronics() : name("no name"), model("no model"), price(0), type("no type") {}
Electronics::Electronics(string n, string m, string t, int p) : name(n), model(m), price(p), type(t) {
	price = p < 0 ? 0 : p;
}
 void Electronics::Print() const{
	cout << "Name: " << name << endl;
	cout << "Model: " << model << endl;
	cout << "Price: " << price << "$" << endl;
}
 void Electronics::SetModel(string model) {
	 this->model = model;
 }void Electronics::SetName(string name) {
	 this->name = name;
 }
 void Electronics::SetPrice(int price) {
	 this->price = price;
 }
 void  Electronics::SetPriceForDiscount(int value) {
	 price -= value;
 }
 void  Electronics::RemoveInfoExeptModel() {
	 name = "No name";
	 price = 0;
 }
  ifstream& Electronics::Load(ifstream& in) {
	 in >> name >> model >> type >> price;
	 return in;
 }
   ofstream& Electronics::Save(ofstream& out) {
	  out << name << endl << model << endl << type << endl << price;
	  return out;
  }
   bool  Electronics::operator<(Electronics& e) {
	   return price < e.price;
   }


 








