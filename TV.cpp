#include"TV.h"

TV::TV() : diagonal(0), brightness(0), smartTv(false), Electronics() {}
TV::TV(string n, string m, int p, float d, int b, bool s) : diagonal(d), brightness(b), smartTv(s), Electronics(n, m, "TV", p) {
	diagonal = d < 0 ? 0 : d;
	brightness = b < 0 ? 0 : b;
}
void TV::Print()const {
	Electronics::Print();
	cout << "Diagonal: " << diagonal << endl;
	cout << "Brightness: " << brightness << endl;
	cout << "Type:" << Electronics::GetType() << endl;
	if (smartTv == true) { cout << "SmartTv: Yes" << endl; }
	if (smartTv == false) { cout << "SmartTv: No" << endl; }
}
void TV::RemoveInfo() {
	Electronics::RemoveInfoExeptModel();
	diagonal = 0;
	brightness = 0;
	smartTv = false;
}
void TV::SetDiagonal(float d) {
	diagonal = d;
}
void  TV::SetBrightness(int b) {
	brightness = b;
}
void TV::SetSmartTv(bool s) {
	smartTv = s;
}
 ifstream& TV::Load(ifstream& in) {
	Electronics::Load(in);
	in >> diagonal >> brightness >> smartTv;
	return in;
}

ofstream& TV::Save(ofstream& out) {
	Electronics::Save(out);
	out << endl << diagonal << endl << brightness << endl << smartTv;
	return out;
}
