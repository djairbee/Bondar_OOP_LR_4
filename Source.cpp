#include <iostream>
#include <cstdio>
#define N 25
using namespace ::std;

class participant {
protected:
	char competition[N];
	char school[N];
	char name[N];
	int age;

public:
	string school_c;
	string name_c;
	string competition_c;

	~participant()
	{
		//cout << "Destructor" << endl << endl;
	}

	void input_data()
	{
		cout << " Input name of competition" << endl << " ";
		cin >> competition;
		competition_c = competition;
		cout << endl << " Input name of school" << endl << " ";
		cin >> school;
		school_c = school;
		cout << endl << " Input name of participant" << endl << " ";
		cin >> name;
		name_c = name;
		cout << endl << " Input age of participant" << endl << " ";
		cin >> age;
		getchar();
	}
	void output_data()
	{
		cout << "\n\n\n____________________________________________________________________________________";
		cout << "\n Output data about participant" << endl;
		cout << endl << " Name of competition" << endl;
		cout << " " << competition << endl;
		cout << endl << " Name of school" << endl;
		cout << " " << school;
		cout << endl << endl << " Name of participant" << endl;
		cout << " " << name;
		cout << endl << endl << " Age of participant" << endl;
		cout << " " << age << endl;
	}
};

class medalist : public participant
{
private:
	string medal[N];
public:
	int count_m = 0;
	int intput_medals()
	{
		int i;
		cout << endl << "Input medals (input 'stop' in new string if you want to stop)" << endl;
		for (i = 0; ; i++)
		{
			cout << " ";
			cin >> medal[i];
			if (medal[i] == "gold")
			{
				//medal[i] = "gold";
				continue;
			}
			else if (medal[i] == "silver")
			{
				//medal[i] = "silver";
				continue;
			}
			else if (medal[i] == "bronze")
			{
				//medal[i] = "bronze";
				continue;
			}
			else if (medal[i] == "stop")
			{
				break;
			}
			else
			{
				printf("wrong medal\n");
				cin >> medal[i];
				//continue;
			}
		}
		count_m = i;
		cout << endl << endl;
		return i;
	}
	int output_medals(int n)
	{
		printf("\n Medals: \n");
		int j;
		for (j = 0; j < n; j++)
		{
			if (medal[j] != "stop")
			{
				cout << " " << medal[j] << " ";
			}
			else
			{
				break;
			}
		}
		return j;
	}
};

void sorting(medalist* arr, int n)
{
	int i, k, k2, ch;
	k = n, k2 = n - 1;
	double max;
	medalist maxx;
	medalist temp;

	do
	{
		max = arr[0].count_m;
		maxx = arr[0];
		for (i = 0, ch = 0; i < k; i++)
		{
			if (arr[i].count_m < max)
			{
				max = arr[i].count_m;
				ch = i;
			}
		}
		if ((max != arr[n - 1].count_m))
		{
			temp = arr[k2];
			arr[k2] = arr[ch];
			arr[ch] = temp;
			arr[k2].count_m = max;
		}
		k--;
		k2--;
	} while (k > 0);

	for (int i = 0; i < max; i++)
	{
		cout << " | "<<arr[i].name_c << " = "<< arr[i].count_m << " | " << endl;
	}
}

void Info(medalist* arr, int n, int m)
{
	string s_copy, n_copy;
skip:cout << "\n\n\n___________________________________________";
	cout << "\n Input name of school and name of participant" << endl << " ";
	cin >> s_copy;
	cout << " ";
	cin >> n_copy;
	int check = 0;
	int i;
	for (i = 0; i < m; i++)
	{
		if (s_copy == arr[i].school_c)
		{
		
			break;
		}
	}
	
	int j;
	for (j = 0; j < m; j++)
	{
		if (n_copy == arr[j].name_c)
		{
			
			break;
		}
	}
	

	if (i != j)
	{
		puts(" Mistake, name of school or name of participant is incorrect");
		goto skip;
	}
	else
	{
		cout << "\n Name of the competition: " << arr[i].competition_c;
		printf("\n Participant's awards: \n");
		cout << "\n Quantity of awards = " << arr[i].output_medals(n);

	}
}

int main()
{
	int count;
	cout << " input count of participant : ";
	cin >> count;
	medalist* Participants = new medalist[count];
	int max = 0;
	for (int i = 0; i < count; i++)
	{
		Participants[i].input_data();
		int n = Participants[i].intput_medals();
		if (n > max)
		{
			max = n;
		}
	}
	sorting(Participants, count);
	for (int i = 0; i < count; i++)
	{
		Participants[i].output_data();
		Participants[i].output_medals(max);
	}
	Info(Participants, max, count);

	getchar();
	getchar();
	
	delete[] Participants;
	return 0;
}

//Створити базовий клас УЧАСНИК УЧНІВСЬКИХ ЗМАГАНЬ(задаються назва змагання, дані про учня).
//Створити похідний клас МЕДАЛІСТ(задається ранг медалі : золота, срібна чи бронзова).
//Для введених даних про здобуті медалі відсортувати учнів за спаданням сумарної кількості нагород
//і вивести дані про нагороди, здобуті заданим учнем школи.