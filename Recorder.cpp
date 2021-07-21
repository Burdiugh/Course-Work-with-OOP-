#include"Recorder.h"

Recorder::Recorder() :loudness(0), FrequencyRange(0), WateResistance(false), Electronics() {}
Recorder::Recorder(string n, string m, int p, float l, int f, bool w) : loudness(l), FrequencyRange(f), WateResistance(w), Electronics(n, m, "Recorder", p) {}

void Recorder::Print()const {
	Electronics::Print();
	cout << "Loudness: " << loudness << endl;
	cout << "Frequency Range: " << FrequencyRange << endl;
	cout << "Type: " << Electronics::GetType() << endl;
	if (WateResistance == true) { cout << "Water Esistance: Yes" << endl; }
	if (WateResistance == false) { cout << "Water Esistance: No" << endl; }
}
void Recorder::RemoveInfo() {
	Electronics::RemoveInfoExeptModel();
	loudness = 0;
	FrequencyRange = 0;
	WateResistance = false;
}
void Recorder::SetLoudnees(float l) {
	loudness = l;
}
void  Recorder::SetFrequencyRange(int f) {
	FrequencyRange = f;
}
void  Recorder::SetWateResistance(bool w) {
	WateResistance = w;
}
ifstream& Recorder::Load(ifstream& in) {
	Electronics::Load(in);
	in >> loudness >> FrequencyRange >> WateResistance;
	return in;
}
ofstream& Recorder::Save(ofstream& out)  {
	Electronics::Save(out);
	out << endl << loudness << endl << FrequencyRange << endl << WateResistance;
	return out;
}