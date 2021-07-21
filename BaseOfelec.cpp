#include"BaseOfElec.h"

BaseOfElectronic::BaseOfElectronic() { totalDevices = totalREC = totalTV = 0; } // присвоюємо по дефолту 0.
void BaseOfElectronic::AddTv(TV& tv) {
	this->tv.insert(this->tv.begin(), tv); // добавляємо в початок вектора телевізор
	totalDevices++; // плюсуємо загальну кількість девайсів
	totalTV++; // плюсуємо кількість телевізорів
}
void BaseOfElectronic::AddRec(Recorder& rec) {
	this->rec.insert(this->rec.begin(), rec);  // добавляємо в початок вектора магнітофон
	totalDevices++; // плюсуємо загальну кількість девайсів
	totalREC++; // плюсуємо кількість магнітофонів
	

}
void BaseOfElectronic::PrintAllList()const { // показуюємо весь список девайсів
	for (size_t i = 0; i < tv.size(); i++)
	{
		cout << "TV #" << i + 1 << endl;
		tv[i].Print(); cout << "\n";
	}
	cout << "\n";
	for (size_t i = 0; i < rec.size(); i++)
	{
		cout << "Recorder #" << i + 1 << endl;
		rec[i].Print(); cout << "\n";
	}

}
void BaseOfElectronic::PrintStat() const { // показуємо статистику магазину
	cout << "Total devices: " << totalDevices << endl;
	cout << "Number of TVs: " << totalTV << endl;
	cout << "Number of Recorders: " << totalREC << endl;
	int totalTv = 0;
	int counter1 = 0;
	int counter2 = 0;
	for (size_t i = 0; i < tv.size(); i++)
	{
		totalTv += tv[i].GetPrice();
		counter1++;
	}
	cout << "Total cost of TVs: " << totalTv << "$" << endl;
	int totalRec = 0;
	for (size_t i = 0; i < rec.size(); i++)
	{
		totalRec += rec[i].GetPrice();
		counter2++;
	}
	cout << "Total cost of Recorders: " << totalRec << "$" << endl;
	cout << "Total cost of all devices: " << totalTv + totalRec << "$" << endl;
	cout << "Average cost of TV: " << float(totalTv) / counter1 << "$" << endl;
	cout << "Average cost of Recorders: " << float(totalRec) / counter2 << "$" << endl;
	cout << "Average cost of all devices: " << (float(totalTv) / counter1) + (float(totalRec) / counter2) << "$" << endl;


}
void BaseOfElectronic::EraseByModel(string model) {
	bool check = false; // створюємо змінну для перевірки на навність товару по моделі
	for (size_t i = 0; i < rec.size(); i++)
	{
		if (rec[i].GetModel() == model) { // знаходимо товар по моделі
			cout << "---------------" << endl;
			cout << "\t\tWas Deleted!\n";
			rec[i].Print(); // показуємо товар який видалили
			cout << "---------------" << endl;
			rec.erase(rec.begin() + i); // видалили товар
			totalDevices--; // зменшуємо кількість загальну кількість товарів
			totalREC--; // зменгшуємо кількість магнітофонів
			check = true; // переключаємо змінну на правдиву
		}
	} // все ідентично й до телевізорів у наступному циклі
	for (size_t i = 0; i < tv.size(); i++)
	{
		if (tv[i].GetModel() == model) {
			cout << "---------------" << endl;
			cout << "\t\tWas Deleted!\n";
			tv[i].Print();
			cout << "---------------" << endl;
			tv.erase(tv.begin() + i);
			totalTV--;
			totalDevices--;
			check = true;
		}
	}
	if (check == false) { throw exception("Model not found, try again!"); } // якщо ми не знайшли та не видалили девайс, кидаємо exception!
}
void BaseOfElectronic::ClearBase() { // Метод видаляє всі девайси з бази
	rec.erase(rec.begin(), rec.end());
	tv.erase(tv.begin(), tv.end());
}
void BaseOfElectronic::SortTVByPrice_UP() { // сортує телевізори  від меншого до більшого
	sort(rec.begin(), rec.end());
}
void BaseOfElectronic::SortTVByPrice_Down() { // сортує телевізори від більшого до меншого
	sort(tv.rbegin(), tv.rend());
}

// Точно те саме стосується сортувань магнітофонів
void BaseOfElectronic::SortRecByPrice_UP() {
	sort(rec.begin(), rec.end());
}
void BaseOfElectronic::SortRecByPrice_Down() {
	sort(rec.rbegin(),rec.rend());
}
void BaseOfElectronic::SortTVByName() { // сортування телевізорів по імені (Фірмі)
	for (size_t i = 0; i < tv.size() - 1; i++)
	{
		for (size_t j = 0; j < tv.size() - 1 - i; j++)
		{
			if (strcmp(tv[j].GetName().c_str(), tv[j + 1].GetName().c_str()) == 1) // використовую вбудовані функції з бібліотеки string
			{
				swap(tv[j], tv[j + 1]);
			}
		}
	}
}
// Теж саме з магнітофонами
void BaseOfElectronic::SortRECByName() {
	for (size_t i = 0; i < rec.size() - 1; i++)
	{
		for (size_t j = 0; j < rec.size() - 1 - i; j++)
		{
			if (strcmp(rec[j].GetName().c_str(), rec[j + 1].GetName().c_str()) == 1)
			{
				swap(rec[j], rec[j + 1]);
			}
		}
	}
}


void BaseOfElectronic::SearchByFirm(string firm)const { // Шукаємо девайси по назві фірми
	bool check = false; // змінна для перевірки наявності таких девайсів
	for (size_t i = 0; i < tv.size(); i++) // проходимся по масиву телевізорів застосувавши .size()
	{
		if (tv[i].GetName() == firm) // перевіряємо збіг 
		{
			tv[i].Print(); // показуємо знайдені девайси
			cout << "\n";
			check = true; // переключаємо на правдиву
		}
	}
	// теж саме з магнітофонами
	for (size_t i = 0; i < rec.size(); i++)
	{
		if (rec[i].GetName() == firm)
		{
			rec[i].Print();
			cout << "\n";
			check = true;
		}
	}
	if (check == false) { throw exception("Firm not found! Try again!"); }// якщо ми не знайшли ні одного девайса з відповідною фірмою яку прийняли в метод, тоді кидаємо виключення
}
void BaseOfElectronic::SearchByType(string type)const { // Шукаємо та показуємо всі девайси відповідного типу,принцип такий же як пошук по фірмі
	bool check = false;
	for (size_t i = 0; i < tv.size(); i++)
	{
		if (tv[i].GetType() == type)
		{
			tv[i].Print();
			cout << "\n";
			check = true;
		}
	}
	for (size_t i = 0; i < rec.size(); i++)
	{
		if (rec[i].GetType() == type)
		{
			rec[i].Print();
			cout << "\n";
			check = true;
		}
	}
	if (check == false) { throw exception("Invalid type! Type must be TV or REC"); }
}


void BaseOfElectronic::FiltrPrice(int start, int end) {
	for (size_t i = 0; i < tv.size(); i++)
	{
		if (tv[i].GetPrice() >= start && tv[i].GetPrice() <= end) {
			tv[i].Print(); cout << "\n";
		}

	}
	cout << "\n";
	for (size_t i = 0; i < rec.size(); i++)
	{
		if (rec[i].GetPrice() >= start && rec[i].GetPrice() <= end) {
			rec[i].Print(); cout << "\n";
		}
	}
}
void BaseOfElectronic::FiltrPriceByType(string type, int start, int end) {
	if (type != "TV" && type != "Rec") { throw exception("Invalid type"); }
	else if (start < 1 && end < 1) { throw exception("Invalid value! Value must be more than 0! "); }
	else {
		if (type == "TV") {
			for (size_t i = 0; i < tv.size(); i++)
			{
				if (tv[i].GetPrice() >= start && tv[i].GetPrice() <= end) { tv[i].Print(); cout << "\n"; }
			}
		}
		cout << "\n";
		if (type == "Rec") {
			for (size_t i = 0; i < rec.size(); i++)
			{
				if (rec[i].GetPrice() >= start && rec[i].GetPrice() <= end) {
					rec[i].Print(); cout << "\n";
				}
			}
		}
	}
}

void BaseOfElectronic::DeleteInfoByModel(string model) {// видаляємо ІНФОРМАЦІЮ про девайс (збиваємо значення до дефолту), окрім моделі, для того щоб ми могли по чомусь доступитися і редагувати інфу про девайс
	bool check = false;
	for (size_t i = 0; i < tv.size(); i++)
	{
		if (tv[i].GetModel() == model) { tv[i].RemoveInfo(); } // RemoveInfo() - Метод класа телевізор який збиває значення до дефолту, окрім моделі!
		check = true;
	}
	for (size_t i = 0; i < rec.size(); i++)
	{
		if (rec[i].GetModel() == model) { rec[i].RemoveInfo(); }// RemoveInfo() - Метод класа магнітофон який збиває значення до дефолту, окрім моделі!
		check = true;
	}
	if (check == false) { throw exception("Model not found! Try again!"); }
}
void BaseOfElectronic::GiveDiscount(string type, string name, int discount) {// застосовуємо скидку у відсотках приймаючи тип, фірму, та відсоток
	int res;
	int proc;
	bool check = false;
	if (type != "TV" && type != "Rec") { throw exception("Invalid type"); }
	else
	{
		if (type == "TV") {
			for (size_t i = 0; i < tv.size(); i++)
			{
				if (tv[i].GetName() == name) {
					proc = tv[i].GetPrice() / 100;
					res = proc * discount;
					tv[i].SetPriceForDiscount(res); // цей метод є як у класі телевозор, так і у магнітовону, це по суті сетер, який виконує операцію -= до змінної price.
					check = true;
				}
			}
		}
		if (type == "Recorder") {
			for (size_t i = 0; i < rec.size(); i++)
			{
				if (rec[i].GetName() == name) {
					proc = rec[i].GetPrice() / 100;
					res = proc * discount;
					rec[i].SetPriceForDiscount(res);
					check = true;
				}
			}
		}
	}
	if (check == false) { throw exception("Name of devices not found! Try again!"); }
}
// далі йдуть тільки зміни певного параметру, там все елементарно і не цікаво, методи приймають модель, та нові значення для зміни параметру.
void BaseOfElectronic::ChangePriceByModel(string model, int value) {
	bool check = false;
	for (size_t i = 0; i < tv.size(); i++)
	{
		if (tv[i].GetModel() == model) {
			tv[i].SetPrice(value);
			check = true;
		}
	}
	for (size_t i = 0; i < rec.size(); i++)
	{
		if (rec[i].GetModel() == model) {
			rec[i].SetPrice(value);
			check = true;
		}
	}
	if (check == false) { throw exception("Model not found! Try again!"); }
	else
	{
		cout << "Price was changed!" << endl;
	}
}
void BaseOfElectronic::ChangeNameByModel(string model, string name) {
	bool check = false;
	for (size_t i = 0; i < tv.size(); i++)
	{
		if (tv[i].GetModel() == model) {
			tv[i].SetName(name);
			check = true;
		}
	}
	for (size_t i = 0; i < rec.size(); i++)
	{
		if (rec[i].GetModel() == model) {
			rec[i].SetName(name);
			check = true;
		}
	}
	if (check == false) { throw exception("Model not found! Try again!"); }
	else
	{
		cout << "Name was changed!" << endl;
	}
}
void BaseOfElectronic::ChangeModelByModel(string model, string changeModel) {
	bool check = false;
	for (size_t i = 0; i < tv.size(); i++)
	{
		if (tv[i].GetModel() == model) {
			tv[i].SetModel(changeModel);
			check = true;
		}
	}
	for (size_t i = 0; i < rec.size(); i++)
	{
		if (rec[i].GetModel() == model) {
			rec[i].SetModel(changeModel);
			check = true;
		}
	}
	if (check == false) { throw exception("Model not found! Try again!"); }
	else
	{
		cout << "Model was changed!" << endl;

	}
}
void BaseOfElectronic::ChangeDiagonalOfTV(string model, float value) {
	int check = false;
	int index = 0;
	for (size_t i = 0; i < tv.size(); i++)
	{
		if (tv[i].GetModel() == model) {
			tv[i].SetDiagonal(value);
			index = i;
			check = true;
		}
	}
	if (check == false) { throw exception("Model not found! Try again!"); }
	else
	{
		cout << "Diagonal was changed!\n\n";
		tv[index].Print();
	}
}
void BaseOfElectronic::ChangeBrightnessOfTV(string model, int value) {
	int check = false;
	int index = 0;
	for (size_t i = 0; i < tv.size(); i++)
	{
		if (tv[i].GetModel() == model) {
			tv[i].SetBrightness(value);
			index = i;
			check = true;
		}
	}
	if (check == false) { throw exception("Model not found! Try again!"); }
	else
	{
		cout << "Brightness was changed!\n\n";
		tv[index].Print();
	}
}
void BaseOfElectronic::ChangeSmartTVOfTV(string model, bool value) {
	int check = false;
	int index = 0;
	for (size_t i = 0; i < tv.size(); i++)
	{
		if (tv[i].GetModel() == model) {
			tv[i].SetSmartTv(value);
			index = i;
			check = true;
		}
	}
	if (check == false) { throw exception("Model not found! Try again!"); }
	else
	{
		cout << "Smart TV was changed!\n\n";
		tv[index].Print();
	}
}
void BaseOfElectronic::ChangeLoudneesOfRec(string model, float value) {
	int check = false;
	int index = 0;
	for (size_t i = 0; i < rec.size(); i++)
	{
		if (rec[i].GetModel() == model) {
			rec[i].SetLoudnees(value);
			index = i;
			check = true;
		}
	}
	if (check == false) { throw exception("Model not found! Try again!"); }
	else
	{
		cout << "Loudnees of Recorder was changed!\n\n";
		rec[index].Print();
	}
}
void BaseOfElectronic::ChangeFrequencyRangeOfRec(string model, int value) {
	int check = false;
	int index = 0;
	for (size_t i = 0; i < rec.size(); i++)
	{
		if (rec[i].GetModel() == model) {
			rec[i].SetFrequencyRange(value);
			index = i;
			check = true;
		}
	}
	if (check == false) { throw exception("Model not found! Try again!"); }
	else
	{
		cout << "Frequency Range of Recorder was changed!\n\n";
		rec[index].Print();
	}
}
void BaseOfElectronic::ChangeWateResistance(string model, bool value) {
	int check = false;
	int index = 0;
	for (size_t i = 0; i < rec.size(); i++)
	{
		if (rec[i].GetModel() == model) {
			rec[i].SetWateResistance(value);
			index = i;
			check = true;
		}
	}
	if (check == false) { throw exception("Model not found! Try again!"); }
	else
	{
		cout << "Water esistance was changed!\n\n";
		rec[index].Print();
	}
}

void BaseOfElectronic::Save() {
	ofstream out("TV.txt");
	for (size_t i = 0; i < tv.size(); i++)
	{
		tv[i].Save(out);
	}
	out.close();
	out.open("Rec.txt");
	for (size_t i = 0; i < rec.size(); i++)
	{
		rec[i].Save(out);
	}
	out.close();
	out.open("Base.txt");
	for (size_t i = 0; i < rec.size(); i++)
	{
		rec[i].Save(out);
	}
	out.close();
}
void BaseOfElectronic::Load() {
	ifstream in("TV.txt");
	while (!in.eof())
	{
		TV item;
		item.Load(in);
		tv.push_back(item);
	}
	in.close();
	in.open("Rec.txt");
	while (!in.eof())
	{
		Recorder item;
		item.Load(in);
		rec.push_back(item);
	}
	in.close();
}
void  BaseOfElectronic::SaveStat()const  {
	ofstream out("Base.txt", ios_base::out | ios_base::binary);
	out.write((char*)&totalDevices, sizeof(totalDevices));
	out.write((char*)&totalTV, sizeof(totalTV));
	out.write((char*)&totalREC, sizeof(totalREC));
	out.close();
}
void  BaseOfElectronic::LoadStat() {
	ifstream in("Base.txt", ios_base::in| ios_base::binary);
	in.read((char*)&totalDevices, sizeof(totalDevices));
	in.read((char*)&totalTV, sizeof(totalTV));
	in.read((char*)&totalREC, sizeof(totalREC));
	in.close();
}