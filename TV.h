#pragma once
#include"Electronics.h"


class TV :public Electronics {
	float diagonal;
	int brightness;
	bool smartTv;
public:
	TV();
	TV(string n, string m, int p, float d, int b, bool s);
	void Print()const override;
	void RemoveInfo();
	void SetDiagonal(float d);
	void SetBrightness(int b);
	void SetSmartTv(bool s);
	virtual ifstream& Load(ifstream& in);
	ofstream& Save(ofstream& out);
};
