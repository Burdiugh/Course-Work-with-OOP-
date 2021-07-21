#include"BaseOfElec.h"

BaseOfElectronic::BaseOfElectronic() { totalDevices = totalREC = totalTV = 0; } // ���������� �� ������� 0.
void BaseOfElectronic::AddTv(TV& tv) {
	this->tv.insert(this->tv.begin(), tv); // ���������� � ������� ������� ��������
	totalDevices++; // ������� �������� ������� �������
	totalTV++; // ������� ������� ���������
}
void BaseOfElectronic::AddRec(Recorder& rec) {
	this->rec.insert(this->rec.begin(), rec);  // ���������� � ������� ������� ���������
	totalDevices++; // ������� �������� ������� �������
	totalREC++; // ������� ������� ����������
	

}
void BaseOfElectronic::PrintAllList()const { // ���������� ���� ������ �������
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
void BaseOfElectronic::PrintStat() const { // �������� ���������� ��������
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
	bool check = false; // ��������� ����� ��� �������� �� ������� ������ �� �����
	for (size_t i = 0; i < rec.size(); i++)
	{
		if (rec[i].GetModel() == model) { // ��������� ����� �� �����
			cout << "---------------" << endl;
			cout << "\t\tWas Deleted!\n";
			rec[i].Print(); // �������� ����� ���� ��������
			cout << "---------------" << endl;
			rec.erase(rec.begin() + i); // �������� �����
			totalDevices--; // �������� ������� �������� ������� ������
			totalREC--; // ��������� ������� ����������
			check = true; // ����������� ����� �� ��������
		}
	} // ��� ��������� � �� ��������� � ���������� ����
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
	if (check == false) { throw exception("Model not found, try again!"); } // ���� �� �� ������� �� �� �������� ������, ������ exception!
}
void BaseOfElectronic::ClearBase() { // ����� ������� �� ������� � ����
	rec.erase(rec.begin(), rec.end());
	tv.erase(tv.begin(), tv.end());
}
void BaseOfElectronic::SortTVByPrice_UP() { // ����� ���������  �� ������� �� �������
	sort(rec.begin(), rec.end());
}
void BaseOfElectronic::SortTVByPrice_Down() { // ����� ��������� �� ������� �� �������
	sort(tv.rbegin(), tv.rend());
}

// ����� �� ���� ��������� ��������� ����������
void BaseOfElectronic::SortRecByPrice_UP() {
	sort(rec.begin(), rec.end());
}
void BaseOfElectronic::SortRecByPrice_Down() {
	sort(rec.rbegin(),rec.rend());
}
void BaseOfElectronic::SortTVByName() { // ���������� ��������� �� ���� (Գ��)
	for (size_t i = 0; i < tv.size() - 1; i++)
	{
		for (size_t j = 0; j < tv.size() - 1 - i; j++)
		{
			if (strcmp(tv[j].GetName().c_str(), tv[j + 1].GetName().c_str()) == 1) // ������������ �������� ������� � �������� string
			{
				swap(tv[j], tv[j + 1]);
			}
		}
	}
}
// ��� ���� � ������������
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


void BaseOfElectronic::SearchByFirm(string firm)const { // ������ ������� �� ���� �����
	bool check = false; // ����� ��� �������� �������� ����� �������
	for (size_t i = 0; i < tv.size(); i++) // ���������� �� ������ ��������� ������������ .size()
	{
		if (tv[i].GetName() == firm) // ���������� ��� 
		{
			tv[i].Print(); // �������� ������� �������
			cout << "\n";
			check = true; // ����������� �� ��������
		}
	}
	// ��� ���� � ������������
	for (size_t i = 0; i < rec.size(); i++)
	{
		if (rec[i].GetName() == firm)
		{
			rec[i].Print();
			cout << "\n";
			check = true;
		}
	}
	if (check == false) { throw exception("Firm not found! Try again!"); }// ���� �� �� ������� � ������ ������� � ��������� ������ ��� �������� � �����, ��� ������ ����������
}
void BaseOfElectronic::SearchByType(string type)const { // ������ �� �������� �� ������� ���������� ����,������� ����� �� �� ����� �� ����
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

void BaseOfElectronic::DeleteInfoByModel(string model) {// ��������� �������ֲ� ��� ������ (������� �������� �� �������), ���� �����, ��� ���� ��� �� ����� �� ������ ����������� � ���������� ���� ��� ������
	bool check = false;
	for (size_t i = 0; i < tv.size(); i++)
	{
		if (tv[i].GetModel() == model) { tv[i].RemoveInfo(); } // RemoveInfo() - ����� ����� �������� ���� ����� �������� �� �������, ���� �����!
		check = true;
	}
	for (size_t i = 0; i < rec.size(); i++)
	{
		if (rec[i].GetModel() == model) { rec[i].RemoveInfo(); }// RemoveInfo() - ����� ����� ��������� ���� ����� �������� �� �������, ���� �����!
		check = true;
	}
	if (check == false) { throw exception("Model not found! Try again!"); }
}
void BaseOfElectronic::GiveDiscount(string type, string name, int discount) {// ����������� ������ � �������� ��������� ���, �����, �� �������
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
					tv[i].SetPriceForDiscount(res); // ��� ����� � �� � ���� ���������, ��� � � ����������, �� �� ��� �����, ���� ������ �������� -= �� ����� price.
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
// ��� ����� ����� ���� ������� ���������, ��� ��� ����������� � �� ������, ������ ��������� ������, �� ��� �������� ��� ���� ���������.
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