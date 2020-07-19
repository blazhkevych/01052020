#include <iostream>
using namespace std;

//struct
//3
//-
//4
//Fraction Add(Fraction a, Fraction b) {
void Add(int Num1, int Denom1, int Num2, int Denom2, int& NumR, int& DenomR) {
	NumR = Num1 + Num2;
	DenomR = Denom1 + Denom2;
}
struct Fraction
{
	int Whole;
	int Numerator;
	int Denominator;
}globB, * globP;

void Print(Fraction D) {

	if (D.Whole != 0)
		cout << D.Whole;
	if (D.Numerator != 0) {
		if (D.Whole != 0)
			cout << "(";
		cout << D.Numerator << "/" << D.Denominator;
		if (D.Whole != 0)
			cout << ")";
	}
	cout << " ";
}
void Input(Fraction& D) {
	cout << "Enter the whole:      "; cin >> D.Whole;
	cout << "Enter the numerator:  "; cin >> D.Numerator;
	cout << "Enter the denominator:"; cin >> D.Denominator;
}
//алгоритм Евклида
int gcd(int a, int b) {
	return !b ? abs(a) : gcd(b, a % b);
}

void Norm(Fraction& D) {
	if (D.Denominator != 0 && D.Numerator != 0) {
		//D.Numerator = D.Whole * D.Denominator + D.Numerator;
		int dil = gcd(D.Numerator, D.Denominator);
		D.Numerator /= dil;
		D.Denominator /= dil;
		if (D.Whole >= 0)
			D.Whole += D.Numerator / D.Denominator;
		else
			D.Whole -= D.Numerator / D.Denominator;

		if (D.Numerator / D.Denominator)
			D.Numerator = abs(D.Numerator % D.Denominator);
	}

}
Fraction Add(Fraction a, Fraction b) {
	Fraction Rez{ 0 };
	Rez.Whole = a.Whole + b.Whole;
	Rez.Denominator = a.Denominator * b.Denominator;
	Rez.Numerator = b.Denominator * a.Numerator + a.Denominator * b.Numerator;
	Norm(Rez);
	return Rez;
	/*return {
		a.Whole + b.Whole,
		b.Denominator * a.Numerator + a.Denominator * b.Numerator,
		a.Denominator* b.Denominator
	};*/
}

int main()
{
	Fraction A{ 0,8,2 }, B{ 0,16,8 }, C{ 0,-8,3 };
	cout << "--------------------1--------------------\n";
	Print(C);
	Norm(C);
	Print(C);
	cout << "\n---------------------2-------------------\n";
	C = { 0,-30,50 };
	Print(C);
	Norm(C);
	Print(C);
	cout << "\n---------------------3-------------------\n";
	C = { -5,3,2 };
	Print(C);
	Norm(C);
	Print(C);
	cout << "\n---------------------4-------------------\n";
	C = { 5,3,2 };
	Print(C);
	Norm(C);
	Print(C);
	cout << "\n---------------------5-------------------\n";
	//Print(globB);
	//Input(A);
	//Input(B);
	//Input(C);

	A = { 0,1,3 };
	B = { 0,1,3 };
	C = { 0,1,3 };
	Print(A);
	Print(B);
	Print(C);

	//Print(Add(Add(A,B),C));
	Fraction temp = Add(A, B);
	Print(Add(temp, C));

	//	Print(temp);
}