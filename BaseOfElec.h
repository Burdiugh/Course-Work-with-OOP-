#pragma once
#include"TV.h"
#include"Recorder.h"

class BaseOfElectronic {
	vector<TV>tv;
	vector<Recorder>rec;
	int totalDevices;
	int totalTV;
	int totalREC;
	friend ofstream& operator <<(ofstream& out, BaseOfElectronic& b);
	friend ifstream& operator>>(ifstream& in, BaseOfElectronic& b);
public:
	BaseOfElectronic();
	void AddTv(TV& tv);
	void AddRec(Recorder& rec);
	void PrintAllList()const;
	void PrintStat() const;
	void EraseByModel(string model);
	void ClearBase();
	void SortTVByPrice_UP();
	void SortTVByPrice_Down();
	void SortRecByPrice_UP();
	void SortRecByPrice_Down();
	void SortTVByName();
	void SortRECByName();
	void SearchByFirm(string firm)const;
	void SearchByType(string type)const;
	void FiltrPrice(int start, int end);
	void FiltrPriceByType(string type, int start, int end);
	void DeleteInfoByModel(string model);
	void GiveDiscount(string type, string name, int discount);
	void ChangePriceByModel(string model, int value);
	void ChangeNameByModel(string model, string name);
	void ChangeModelByModel(string model, string changeModel);
	void ChangeDiagonalOfTV(string model, float value);
	void ChangeBrightnessOfTV(string model, int value);
	void ChangeSmartTVOfTV(string model, bool value);
	void ChangeLoudneesOfRec(string model, float value);
	void ChangeFrequencyRangeOfRec(string model, int value);
	void ChangeWateResistance(string model, bool value);
	void  Save();
	void Load();
	void SaveStat()const;
	void LoadStat();
};
