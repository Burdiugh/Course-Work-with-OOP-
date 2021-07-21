#pragma once
#include "Electronics.h"

class Recorder :public Electronics {
	float loudness;
	int FrequencyRange;
	bool WateResistance;
public:
	Recorder();
	Recorder(string n, string m, int p, float l, int f, bool w);
	void Print()const override;
	void RemoveInfo();
	void SetLoudnees(float l);
	void SetFrequencyRange(int f);
	void SetWateResistance(bool w);
	virtual ifstream& Load(ifstream& in);
	ofstream& Save(ofstream& out) override;
	
};