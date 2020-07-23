#include <iostream>
#include <algorithm>
using namespace std;

struct nod
{
	int bal;
	int info;
	nod* left, * right;
};

void rotatie_dreapta(nod*& p)
{
	nod* t = p->left;
	p->left = t->right;
	t->right = p;
	p->bal = p->bal + (1 - min(t->bal, 0));
	t->bal = t->bal + (1 + max(p->bal, 0));
	p = t;
}
void rotatie_stanga(nod*& p)
{
	nod* t = p->right;
	p->right = t->left;
	t->left = p;
	p->bal = p->bal - (1 + max(t->bal, 0));
	t->bal = t->bal - (1 - min(p->bal, 0));
	p = t;
}
void rotatie_dreapta_stanga(nod*& p)
{
	rotatie_dreapta(p->right);
	rotatie_stanga(p);
}
void rotatie_stanga_dreapta(nod*& p)
{
	rotatie_stanga(p->left);
	rotatie_dreapta(p);
}

void echilibreaza(nod*& p)
{
	if (p->bal == -2)
		if (p->left->bal == 1)
			rotatie_stanga_dreapta(p);
		else
			rotatie_dreapta(p);
	else
		if (p->bal == 2)
			if (p->right->bal == -1)
				rotatie_dreapta_stanga(p);
			else
				rotatie_stanga(p);
}

bool adauga(nod*& p, int val)
{
	if (p == NULL)
	{
		p = new nod;
		p->info = val;
		p->bal = 0;
		p->left = NULL;
		p->right = NULL;
		return true;
	}
	else
		if (p->info == val)
			return false;
	if (p->info > val)
		if (adauga(p->left, val) == true)
			p->bal--;
		else
			return false;
	else if (adauga(p->right, val) == true)
		p->bal++;
	else
		return false;

	if (p->bal == 1 || p->bal == -1)
		return true;
	else
	{
		echilibreaza(p);
		return false;
	}
}
void afiseaza_SRD(nod* t)
{
	if (t != NULL)
	{
		afiseaza_SRD(t->left);
		cout << t->info << " ";
		afiseaza_SRD(t->right);
	}
}
void afiseaza_RSD(nod* t)
{
	if (t != NULL)
	{
		cout << t->info << " ";
		afiseaza_RSD(t->left);
		afiseaza_RSD(t->right);
	}
}
int main()
{
	nod* root1 = NULL;

	adauga(root1, 50);
	adauga(root1, 40);
	adauga(root1, 30);
	adauga(root1, 35);
	adauga(root1, 37);
	adauga(root1, 39);
	adauga(root1, 45);
	adauga(root1, 55);
	adauga(root1, 42);
	cout << "Afisare in inordine:\n";
	afiseaza_SRD(root1);
	cout << "\nAfisare in preordine:\n";
	afiseaza_RSD(root1);

	nod* root = NULL;
	int x = 10, a;

	while (x)
	{
		cout << endl << "Alegeti una dintre optiunile de mai jos, sau 0 pentru a opri programul!" << endl;
		cout << "(1) pentru inserare cheie" << endl;
		cout << "(2) pentru parcurgerea cheilor conform strategiei SRD" << endl;
		cout << "(3) pentru parcurgerea cheilor conform strategiei RSD" << endl;
		cout << "(0) oprire program." << endl;
		cin >> x;
		switch (x)
		{
		case 1:
			cout << "Introduceti cheia: ";
			cin >> a;
			adauga(root, a);
			cout<<"Arborele in inordine"<<endl;
			afiseaza_SRD(root);
			break;
		case 2:
			cout << "Parcurgere in inordine (SRD): ";
			afiseaza_SRD(root);
			cout << endl;
			break;
		case 3:
			cout << "Parcurgere in preordine (RSD): ";
			afiseaza_RSD(root);
			cout << endl;
			break;
		case 0:
			break;
		default:
			cout << "Introduceti una dintre optiunile de mai jos, sau 0 pentru a opri programul!" << endl;
			break;
		}
	}
	return 0;
}
