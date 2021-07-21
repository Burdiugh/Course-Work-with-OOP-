#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include"BaseOfElec.h"
using namespace std;

ofstream& operator <<(ofstream& out, BaseOfElectronic& b) {
	out << b.totalDevices << endl << b.totalTV << endl << b.totalREC;
	return out;
}
ifstream& operator>>(ifstream& in, BaseOfElectronic& b) {
	in >> b.totalDevices >> b.totalTV >> b.totalREC;
	return in;
}
int main()
{
	BaseOfElectronic base;
	int select = 0;
	string name="no name";
	string model="no model";
	int price = 0;
	int diagonal = 0;
	int brightness = 0;
	bool smartTV = false;
	float loudness = 0;
	int FrequencyRange = 0;
	bool WateResistance = false;
	base.LoadStat();
	base.Load();
	cout << "You in console of ADMIN, please choose option! " << endl;
	do
	{
		cout << "\n";
		cout << "1. Add devices to DB\n2. Show all devices\n3. Delete device by model\n4. Edit device by model\n5. Sort\n6. Search device by name or type\n7. Get all statistics\n8. Delete info about Device\n9. Give Discount\n10. Price filter by type\n0. Exit\n" << endl;
		cin >> select;
		switch (select)
		{
		case 1: {
			system("cls");
			cout << "How many devices do you want to add to DB?: ";
			int value = 0;
			cin >> value;
			system("cls");
			cout << "Which device do you want to add [TV(1) or REC(2)] ?\n ";
			int choose = 0;
			do {
				cout << "[Choose]: ";
				cin >> choose;
				if (choose != 1 && choose != 2) {
					cout << "Try again! Your choose must be 1(TV) of 2(Rec)!" << endl;
				}
			} while (choose != 1 && choose != 2);
			system("cls");
			switch (choose)
			{
			case 1: {
				system("cls");
				for (size_t i = 0; i < value; i++)
				{
					system("cls");
					cout << "Device #" << i+1 << "\n\n";
					cout << "Input name of TV: "; cin >> name;
					cout << "Input model of TV: "; cin >> model;
					cout << "Input price of TV in USD: ";
					do {
						cin >> price;
						if (price <= 0) {
							cout << "Price must be more than 0." << endl;
						}
					} while (price <= 0);
					cout << "Input diagonal of TV: ";
					do {
						cin >> diagonal;
						if (diagonal <= 0) {
							cout << "Diagonal must be more than 0." << endl;
						}
					} while (diagonal <= 0);
					cout << "Input brightness of TV: ";
					do {
						cin >> brightness;
						if (brightness <= 0) {
							cout << "Brightness must be more than 0." << endl;
						}
					} while (brightness <= 0);
					int temp = 0;
					cout << "Does this TV have \"smart TV\"? : 1(yes) / 0(no) : ";
					do {
						cin >> temp;
						if (temp != 1 && temp != 0) {
							cout << "Input 1(Have smart tv) / 0(Does not have) ." << endl;
						}
					} while (temp != 1 && temp != 0);
					smartTV = temp;
					TV tv(name, model, price, diagonal, brightness, smartTV);
					base.AddTv(tv);
				}
				system("cls");
				break;
			}
			case 2: {
				system("cls");
				for (size_t i = 0; i < value; i++)
				{
					system("cls");
					cout << "Device #" << i + 1 << "\n\n";
					cout << "Input name of recorder: "; cin >> name;
					cout << "Input model of recorder: "; cin >> model;
					cout << "Input price of recorder in USD: ";
					do {
						cin >> price;
						if (price <= 0) {
							cout << "Price must be more than 0." << endl;
						}
					} while (price <= 0);
					cout << "Input loudness of Recorder: ";
					do {
						cin >> loudness;
						if (loudness <= 0) {
							cout << "Loudness must be more than 0." << endl;
						}
					} while (loudness <= 0);
					cout << "Input Frequency Range of recorder: ";
					do {
						cin >> FrequencyRange;
						if (FrequencyRange <= 0) {
							cout << "Frequency Range must be more than 0." << endl;
						}
					} while (FrequencyRange <= 0);
					cout << "Does this recorder have \"Water esistance\"? : 1(yes) / 0(no) : ";
					int temp = 0;
					do {
						cin >> temp;
						if (temp != 1 && temp != 0) {
							cout << "Input 1(Water esistance) / 0(Does not have) ." << endl;
						}
					} while (temp != 1 && temp != 0);
					WateResistance = temp;
					Recorder rec(name, model, price, loudness, FrequencyRange, WateResistance);
					base.AddRec(rec);
				}
				system("cls");
				break;
			}
			}
			break; }
		case 2: {
			system("cls");
			base.PrintAllList();
			break;
		}
		case 3: {
			system("cls");
			cout << "Input model of device which do you want to delete: ";
			cin >> model;
			try
			{
				system("cls");
				base.EraseByModel(model);
			}
			catch (const std::exception& ex)
			{
				system("cls");
				cout << ex.what() << endl;
			}
			break;
		}
		case 4: {
			system("cls");
			cout << "Whitch type of electronic do you want to edit? : 1(TV) / 2(REC) : ";
			int choose = 0;
			do
			{
				cin >> choose;
				if (choose != 1 && choose != 2)
				{
					cout << "Try again! 1(TV) / 2(REC)";
				}

			} while (choose != 1 && choose != 2);
			switch (choose)
			{
			case 1: {
				system("cls");
				cout << "Input model of device which do you want to edit: ";
				cin >> model;
				int edit = 0;
				cout << "\n";
				cout << "What do you want to edit?\n\n1. Name\n2. Model\n3. Price\n4. Diagonal\n5. Brightness\n6. smart TV\n";
				cin >> edit;
				switch (edit)
				{
				case 1: {
					system("cls");
					cout << "Input new name: "; cin >> name;
					try
					{
						base.ChangeNameByModel(model, name);
					}
					catch (const std::exception& ex)
					{
						cout << ex.what() << endl;
					}
					break;
				}
				case 2: {
					system("cls");
					cout << "Input new model: "; cin >> name;
					try
					{
						base.ChangeModelByModel(model, name);

					}
					catch (const std::exception& ex)
					{
						cout << ex.what() << endl;
					}
					break;
				}
				case 3: {
					system("cls");
					cout << "Input new price: ";
					do {
						cin >> price;
						if (price <= 0) {
							cout << "Price must be more than 0." << endl;
						}
					} while (price <= 0);
					try
					{
						base.ChangePriceByModel(model, price);

					}
					catch (const std::exception& ex)
					{
						cout << ex.what() << endl;
					}
					break;
				}
				case 4: {
					system("cls");
					cout << "Input new diagonal: ";
					do {
						cin >> diagonal;
						if (diagonal <= 0) {
							cout << "Diagonal must be more than 0." << endl;
						}
					} while (diagonal <= 0);
					try
					{
						base.ChangeDiagonalOfTV(model, diagonal);

					}
					catch (const std::exception& ex)
					{
						cout << ex.what() << endl;
					}
					break;
				}
				case 5: {
					system("cls");
					cout << "Input new brightness: ";
					do {
						cin >> brightness;
						if (brightness <= 0) {
							cout << "Brightness must be more than 0." << endl;
						}
					} while (brightness <= 0);
					try
					{
						base.ChangeDiagonalOfTV(model, brightness);

					}
					catch (const std::exception& ex)
					{
						cout << ex.what() << endl;
					}
					break;
				}
				case 6: {
					system("cls");
					int temp = 0;
					cout << "Input new smart TV: ";
					do {
						cin >> temp;
						if (temp != 1 && temp != 0) {
							cout << "Input 1(Have smart tv) / 0(Does not have) ." << endl;
						}
					} while (temp != 1 && temp != 0);
					smartTV = temp;
					try
					{
						base.ChangeSmartTVOfTV(model, smartTV);

					}
					catch (const std::exception& ex)
					{
						cout << ex.what() << endl;
					}
					break;
				}
				default:cout << "Case not found! Select true options! " << endl;
					break;
				}
				break;
			}
			case 2: {
				system("cls");
				cout << "Input model of device which do you want to edit: ";
				cin >> model;
				int edit = 0;
				cout << "\n";
				cout << "What do you want to edit?\n\n1. Name\n2. Model\n3. Price\n4. Loudness\n5. Frequency Range\n6. Water asistance\n";
				cin >> edit;
				switch (edit)
				{
				case 1: {
					system("cls");
					cout << "Input new name: "; cin >> name;
					try
					{
						base.ChangeNameByModel(model, name);
					}
					catch (const std::exception& ex)
					{
						cout << ex.what() << endl;
					}
					break;
				}
				case 2: {
					system("cls");
					cout << "Input new model: "; cin >> name;
					try
					{
						base.ChangeModelByModel(model, name);

					}
					catch (const std::exception& ex)
					{
						cout << ex.what() << endl;
					}
					break;
				}
				case 3: {
					system("cls");
					cout << "Input new loudness: ";
					do {
						cin >> loudness;
						if (loudness <= 0) {
							cout << "Loudness must be more than 0." << endl;
						}
					} while (loudness <= 0);
					try
					{
						base.ChangeLoudneesOfRec(model, loudness);

					}
					catch (const std::exception& ex)
					{
						cout << ex.what() << endl;
					}
					break;
				}
				case 4: {
					system("cls");
					cout << "Input new Frequency Range: ";
					do {
						cin >> FrequencyRange;
						if (FrequencyRange <= 0) {
							cout << "Frequency Range must be more than 0." << endl;
						}
					} while (FrequencyRange <= 0);
					try
					{
						base.ChangeFrequencyRangeOfRec(model, FrequencyRange);

					}
					catch (const std::exception& ex)
					{
						cout << ex.what() << endl;
					}
					break;
				}
				case 5: {
					system("cls");
					cout << "Input new water esistance: ";
					int temp = 0;
					do {
						cin >> temp;
						if (temp != 1 && temp != 0) {
							cout << "Input 1(Water esistance) / 0(Does not have) ." << endl;
						}
					} while (temp != 1 && temp != 0);
					WateResistance = temp;
					try
					{
						base.ChangeWateResistance(model, WateResistance);

					}
					catch (const std::exception& ex)
					{
						cout << ex.what() << endl;
					}
					break;
				}
				default:cout << "Select true option! " << endl;
					break;
				}
				break;
			}
			default:cout << "Case not found! Tru again!" << endl;
				break;
			}
			break;
		}
		case 5: {
			system("cls");
			cout << "Whitch type of devices do you want to sort? " << endl;
			cout << "(1) TV / (2) Recorder / (3)All Sort : ";
			int choose = 0;
			do
			{
				cin >> choose;
				if (choose < 1 || choose > 3) { cout << "(1)TV / (2)Recorder / (3)All Sort" << endl; }
			} while (choose < 1 || choose > 3);
			switch (choose)
			{
			case 1: {
				system("cls");
				cout << "How we will sort devices?\n1. By name\n2. By price" << endl;
				int select = 0;
				do
				{
					cin >> select;
					if (select != 1 && select != 2)
					{
						cout << "(1) Sort by name / (2) Sort by price" << endl;
					}
				} while (select != 1 && select != 2);
				switch (select)
				{
				case 1: {
					system("cls");
					base.SortTVByName();
					base.PrintAllList();
					break;
				}
				case 2: {
					system("cls");
					cout << "How dou you want to sort by price?\n(1)Sort by ascending / (2)Sort  by descending : ";
					int select = 0;
					do
					{
						cin >> select;
						if (select != 1 && select != 2) { cout << "(1)Sort by ascending / (2)Sort  by descending " << endl; }
					} while (select != 1 && select != 2);
					switch (select)
					{
					case 1: {
						system("cls");
						base.SortTVByPrice_UP();
						base.PrintAllList();
						break;
					}
					case 2: {
						base.SortTVByPrice_Down();
						base.PrintAllList();
						break;
					}
					default:cout << "Select true option! " << endl;
						break;
					}
					break;
				}
				default:cout << "Select true option! " << endl;
					break;
				}
				break; }
			case 2: {
				system("cls");
				cout << "How we will sort devices?\n1. By name\n2. By price" << endl;
				int select = 0;
				do
				{
					cin >> select;
					if (select != 1 && select != 2)
					{
						cout << "(1) Sort by name / (2) Sort by price" << endl;
					}
				} while (select != 1 && select != 2);
				switch (select)
				{
				case 1: {
					system("cls");
					base.SortRECByName();
					base.PrintAllList();
					break;
				}
				case 2: {
					system("cls");
					cout << "How dou you want to sort by price?\n(1)Sort by ascending / (2)Sort  by descending : ";
					int select = 0;
					do
					{
						cin >> select;
						if (select != 1 && select != 2) { cout << "(1)Sort by ascending / (2)Sort  by descending " << endl; }
					} while (select != 1 && select != 2);
					switch (select)
					{
					case 1: {
						system("cls");
						base.SortRecByPrice_UP();
						base.PrintAllList();
						break;
					}
					case 2: {
						system("cls");
						base.SortRecByPrice_Down();
						base.PrintAllList();
						break;
					}
					default:cout << "Select true option! " << endl;
						break;
					}
					break;
				}
				default:cout << "Select true option! " << endl;
					break;
				}
				break;
			}
			case 3: {
				system("cls");
				cout << "How do you want to sort devices?\n (1)By Name / (2)By Price: ";
				int select = 0;
				do
				{
					cin >> select;
					if (select != 1 && select != 2)
					{
						cout << "(1)By Name / (2)By Price : " << endl;
					}
				} while (select != 1 && select != 2);
				switch (select)
				{
				case 1: {
					system("cls");
					base.SortTVByName();
					base.SortRECByName();
					base.PrintAllList();
					break;
				}
				case 2: {
					system("cls");
					cout << "How do you want to sort by price?\n(1)Sort by ascending / (2)Sort  by descending : ";
					int select = 0;
					do
					{
						cin >> select;
						if (select != 1 && select != 2)
						{
							cout << "(1)Sort by ascending / (2)Sort  by descending " << endl;
						}
					} while (select != 1 && select != 2);
					switch (select)
					{
					case 1: {
						system("cls");
						base.SortRecByPrice_UP();
						base.SortTVByPrice_UP();
						base.PrintAllList();
						break;
					}
					case 2: {
						system("cls");
						base.SortRecByPrice_Down();
						base.SortTVByPrice_Down();
						base.PrintAllList();
						break;
					}
					default:cout << "Select true option! " << endl;
						break;
					}
					break;
				}
				default:cout << "Select true option! " << endl;
					break;
				}
				break;
			}
			default: cout << "Select true option! " << endl;
				break;
			}
			break;
		}
		case 6: {
			system("cls");
			cout << "How do you want to search? (1)By type / (2)By name : ";
			int select = 0;
			do
			{
				cin >> select;
				if (select != 1 && select != 2)
				{
					cout << "(1)By type / (2)By name" << endl;
				}
			} while (select != 1 && select != 2);
			switch (select)
			{
			case 1: {
				system("cls");
				cout << "Choose type of devices:  (1)TV / 2(REC) : ";
				int select = 0;
				do
				{
					cin >> select;
					if (select != 1 && select != 2)
					{
						cout << "(1)TV / (2)REC" << endl;
					}
				} while (select != 1 && select != 2);
				if (select == 1) { base.SearchByType("TV"); }
				else if (select == 2) { base.SearchByType("Recorder"); }
				break;
			}
			case 2: {
				system("cls");
				cout << "Input name of devices to search: ";
				cin >> name;
				try
				{
					base.SearchByFirm(name);

				}
				catch (const std::exception& ex)
				{
					cout << ex.what() << endl;
				}
				break;
			}
			default: cout << "Select true option! " << endl;
				break;
			}
			break;
		}
		case 7: {
			system("cls");
			base.PrintStat();
			break;
		}
		case 8: {
			system("cls");
			cout << "Input model of device to remove info: ";
			cin >> model;
			try
			{
				base.DeleteInfoByModel(model);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}
			break;
		}
		case 9: {
			system("cls");
			cout << "Choose type of devices which do you want to give discount: (1)TV / (2)REC : ";
			int select = 0;
			do
			{
				cin >> select;
				if (select != 1 && select != 2)
				{
					cout << "(1)TV / (2)REC" << endl;
				}
			} while (select != 1 && select != 2);
			switch (select)
			{
			case 1: {
				cout << "Input name of TVs whitch will get discount: ";
				cin >> name;
				cout << "Input discount in %" << endl;
				int disc = 0;
				do
				{
					cin >> disc;
					if (disc < 1 || disc>100) { cout << "Discount must be between 1 and 100 range!" << endl; }
				} while (disc < 1 || disc>100);
				try
				{
					base.GiveDiscount("TV", name, disc);
				}
				catch (const std::exception& ex)
				{
					cout << ex.what() << endl;
				}
				break;
			}
			case 2: {
				cout << "Input name of Recorders whitch will get discount: ";
				cin >> name;
				cout << "Input discount in %" << endl;
				int disc = 0;
				do
				{
					cin >> disc;
					if (disc < 1 || disc>100) { cout << "Discount must be between 1 and 100 range!" << endl; }
				} while (disc < 1 || disc>100);
				try
				{
					base.GiveDiscount("Recorder", name, disc);
				}
				catch (const std::exception& ex)
				{
					cout << ex.what() << endl;
				}
				break;
			}
			default: cout << "Select true option! " << endl;
				break;
			}
			break;
		}
		case 10: {
			system("cls");
			cout << "How do you want to filter? By price (1)[start -> end] / (2)By type + [start->end]? ";
			int select = 0;
			do
			{
				cin >> select;
				if (select != 1 && select != 2)
				{
					cout << " (1)[start -> end] / (2)By type + [start->end]" << endl;
				}
			} while (select != 1 && select != 2);
			switch (select)
			{
			case 1: {
				system("cls");
				int start = 0;
				int end = 0;
				cout << "Input start of range: ";
				do
				{
					cin >> start;
					if (start < 1) { cout << "Start of range must be more than 0! " << endl; }

				} while (start < 0);
				cout << "Input end of range: ";
				cin >> end;
				system("cls");
				cout << "Result: \n\n";
				base.FiltrPrice(start, end);
				break;
			}
			case 2: {
				system("cls");
				int start = 0;
				int end = 0;
				int select = 0;
				cout << "Choose type: (1)TV / (2)Rec : ";
				do
				{
					cin >> select;
					if (select != 1 && select != 2) { cout << "(1)TV / (2)Rec" << endl; }
				} while (select != 1 && select != 2);
				switch (select)
				{
				case 1: {
					system("cls");
					cout << "Input start of range: ";
					do
					{
						cin >> start;
						if (start < 1) { cout << "Start of range must be more than 0! " << endl; }

					} while (start < 0);
					cout << "Input end of range: ";
					cin >> end;
					base.FiltrPriceByType("TV", start, end);
					break;
				}
				case 2: {
					system("cls");
					cout << "Input start of range: ";
					do
					{
						cin >> start;
						if (start < 1) { cout << "Start of range must be more than 0! " << endl; }

					} while (start < 0);
					cout << "Input end of range: ";
					cin >> end;
					base.FiltrPriceByType("Rec", start, end);
					break;
				}
				default: cout << "Select true option! " << endl;
					break;
				}

				break;
			}
			default: cout << "Select true option! " << endl;
				break;
			}
			break;
		}
		case 0: {
			select = 0;
			break; }
		default: cout << "Select true option! " << endl;
			break;
		}
	} while (select != 0);
	base.Save();
	base.SaveStat();
}


