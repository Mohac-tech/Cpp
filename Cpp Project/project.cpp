
#include<iostream>
#include<string>
#include<fstream>
#include<ctype.h>

using namespace std;

string condition(int a, int t)
{
	int element = t;
	int T[10] = { 0 };
	int i = t - 1;
	string conv;

	while (a != 0 && i >= 0)
	{
		int c = a % 2;
		T[i] = a;
		a /= 2;
		i--;
	}

	for (int i = 0; i < t; i++)
	{
		conv = conv + to_string(T[i]);
	}
	return conv;
}

void fichier(string tab[], int n)
{
	string data;
	int x = 0;
	int b = 0;
	int t = 3;
	string c;
	int a;
	tab[n];

	ifstream entree("input.txt", ios::in);

	if (entree.is_open())
	{
		while (getline(entree, data))
		{
			for (unsigned int i = 0; i < data.size(); i++)
			{


				if (data[i] == 'i' || data[i] == 'I')
				{
					while (data[i] != ' ')
					{
						if (data[i] == ';')break;
						c = c + data[i];
						i++;
					}
					if (c == "if" || c == "If")
					{
						tab[x] = condition(++b, t);
						break;
					}
				}

				if (data[i] == 'g' || data[i] == 'G')
				{
					while (data[i] != ' ')
					{
						if (data[i] == ';')break;
						c = c + data[i];
						i++;
					}
					if (c == "go" || c == "Go")
					{
						tab[x] = condition(4, t);
						break;
					}
				}
				tab[x] = condition(0, t);
				if (data[i] == ';')break;
			}
			x++;
		}
	}
	entree.close();
}

void lecture2 (string T[])
{
	T[20];
	string data;
	string a;
	int n = 0;
	ifstream entree("input.txt", ios::in);
	if (entree.is_open())
	{
		while (getline(entree, data))
		{
			for (unsigned int i = 0; i < 7; i++)
			{
				if (data[i] == '$')
				{
					while (data[i] != '\t')
					{
						a += data[i];
						i++;
					}
					T[n] = a;
					a = "";
					n++;
					break;
				}
				else
				{
					T[n] = "Vide";
					n++;
					break;
				}
			}

		}
	}
	entree.close();
}



void lecture1(string tab2[])
{
	string a;
	tab2[20];
	string tab1[20];
	string B;
	int num1 = 0;

	lecture2(tab1);

	ifstream entree("input.txt", ios::in);
	if (entree.is_open())
	{
		while (getline(entree, B))
		{
			for (unsigned int i = 4; i < B.size(); i++)
			{
				if (B[i] == ';')break;
				if (B[i] == '$')
				{
					while (B[i] != ';')
					{
						a = a + B[i];
						i++;
					}
					for (int i = 0; i < 14; i++)
					{
						if (a == tab1[i])
						{
							tab2[num1] = condition(i, 4);
							break;
						}
					}
					a = "";
					break;
				}
				else
				{
					tab2[num1] = condition(0, 4);
				}
			}
			++num1;
		}
	}
	entree.close();
}



void Instruction(string T[])
{
	char z;
	int n = 25;
	T[n];
	string data;
	string donnee;
	int compteur = 0;

	ifstream entree("jeu-inst.txt", ios::in);
	if (entree.is_open())
	{
		while (getline(entree, data))
		{
			for (int i = 0; i < data.size(); i++)
			{
				if (data[i] == ':')
				{
					i++;
					while (data[i] != ';')
					{
						while (data[i] == ' ' || data[i] == '\t')i++;
						if (data[i] == ';')break;
						
						z = tolower(data[i]); // mettre en miniscule
						donnee = donnee +z;
						i++;
					}
					T[compteur] = donnee;
					donnee = "";
					compteur++;
					break;
				}
			}
		}
	}
	entree.close();
}


void controle(string T[])
{
	char z;
	int n = 25;
	string tab1[25];
	T[15];
	int a = 0;
		int j = 0;
	string A;
	string B;
	string tab2[25] = { "0" };
	string data;
	int compt = 0;

	Instruction(tab1);

	ifstream inst("jeu-inst.txt", ios::in);
	if (inst.is_open())
	{
		while (getline(inst, data))
		{
			compt++;
		}
	}
	inst.close();

	for (int i = 0; i < n; i++)
	{
		tab2[i] = '0';
	}

	ifstream entree1("input.txt", ios::in);
	if (entree1.is_open())
	{

		while (getline(entree1, A))
		{
			for (int i = 0; i < A.size(); i++)
			{
				if (A[i] == '$')
				{
					while (A[i] != '\t' && A[i] != ' ') { i++; }
				}

				while (A[i] != ';')
				{
					while (A[i] == ' ' || A[i] == '\t')i++;

					if (B.compare("If") == 0 || B.compare("if") == 0)break;
					if (B.compare("Go") == 0 || B.compare("go") == 0)break;


					if (A[i] == '!')
					{
						for (int i = 0; i < 25; i++)
						{
							if (tab1[i].compare(B) == 0)
							{
								if (i < 4)
								{
									tab2[i] = '1';
								}

								if (i == 4)
								{
									tab2[4] = '0';
									tab2[5] = '0';
								}
								if (i == 5)
								{
									tab2[4] = '0';
									tab2[5] = '1';
								}
								if (i == 6)
								{
									tab2[4] = '1';
									tab2[5] = '0';
								}
								if (i == 7)
								{
									tab2[4] = '1';
									tab2[5] = '1';
								}
								if (i > 7)
								{
									tab2[i - 2] = '1';
								}

								B = "";
								break;
							}
						}

						i++;
						if (A[i] == ' ')i++;

					}

					if (A[i] == ';') {}
					else
					{
						z = tolower(A[i]);
						B += z;
					}

					if (A[i] == ';')break;
					else i++;
				}

				if (A[i] == ';')
				{
					for (int i = 0; i < 25; i++)
					{
						if (tab1[i].compare(B) == 0)
						{

							if (i < 4)
							{
								tab2[i] = '1';
							}

							if (i == 4)
							{
								tab2[4] = '0';
								tab2[5] = '0';
							}
							if (i == 5)
							{
								tab2[4] = '0';
								tab2[5] = '1';
							}
							if (i == 6)
							{
								tab2[4] = '1';
								tab2[5] = '0';
							}
							if (i == 7)
							{
								tab2[4] = '1';
								tab2[5] = '1';
							}
							if (i > 7)
							{
								tab2[i - 2] = '1';
							}

							B = "";
							break;
						}
					}
				}

				if (A[i] == ';')
				{
					B = "";
					break;
				}
			}

			string x;
			for (int i = 0; i < compt; i++)
			{
				x += tab2[i];
				x = x + ' ';
			}
			for (int i = 0; i < compt ;i++)
			{
				tab2[i] = '0';
			}
			T[n] = x;
			j++;

			a++;
		}
	}
}


int main()
{

	int const taille = 20;
	int i = 0;
	int compt = 0;

	string tab[taille];
	string tab1[taille];
	string tab2[taille];
	string data;

	Instruction(tab);

	for (i = 0; i < 20; i++)
	{
		cout << tab[i];
	}

	ifstream entree("input.txt", ios::in);
	if (entree.is_open())
	{
		while (getline(entree, data))
		{
			cout << data;
		}
    }

	ofstream output("sortie.txt", ios::out);

	output << "--------------------------------------------------------------------------------------------"<<endl;
	output << "|DEC" << '\t' << "|COND" << '\t' << "|BRANCH" << '\t' << '\t' << "|CONTROLE" << '\t' << '\t' << "|COMMENTAIRE|" << endl;
	output << "|C   " << "\t" << "|012" << "\t" << "|0123" << "\t" << '\t'<<"|0 1 2 3 4 5 6 7 8 9 |" << endl;

	output << endl;
	output << "------------------------------------------------------------------------------------------------";
	output << endl;



	ifstream inst("input.txt", ios::in);
		while (getline(inst, data))
		{
			compt++;	//compte le nombre d'instruction
		}
		fichier(tab, taille);
		Instruction(tab1);
		controle(tab2);

		cout<<
		if (output.is_open()) {
			for (i = 0; i < compt; i++)
			{
				output << '\t' << i;
				output << '\t' << '\t' << tab[i];
				output << '\t' << '\t' << tab1;
				output << '\t' << '\t' << '\t' << '\v' << tab2;
				output << "\n";
			}

		}
	

	cout << endl;
	return 0;

}
