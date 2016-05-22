#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using std::string;
using std::cout;
using std::endl;
using std::cin;

void mostrar1(string[],string[],int);
void Selecion(string[],string[],int);
bool GaneRoyal(string[]);
bool GanePoker(string[]);
void EvaluaPares(string[]);
bool GaneEscaleraColor(string[]);
void Escalera(string[]);

int main(int argc, char const *argv[])
{
	int DineroUsuario;
	int UsuarioApuesta;

	//Variables de juego.
	string cartas[52] = {"AC","2C","3C","4C","5C","6C","7C","8C","9C","10C","JC","QC","KC","AP","2P","3P","4P","5P","6P","7P","8P","9P","10P","JP","QP","KP","AD","2D","3D","4D","5D","6D","7D","8D","9D","10D","JD","QD","KD","AT","2T","3T","4T","5T","6T","7T","8T","9T","10T","JT","QT","KT"};
	string mano[5] = {};
	string juego1[5] = {};
	
	//Jugar llenando la mano.
	int tamanoMano = 5;
	mostrar1(cartas,juego1,tamanoMano);
	for (int i = 0; i < 5; ++i)
	{
		cout << juego1[i] << "\t";
	}
	cout << endl;
	cout << "Cuantas cartas quiere?: " << endl;
	cin >> tamanoMano;
	if (tamanoMano < 5)
	{
		Selecion(juego1,mano,tamanoMano);
		int cartasRestantes = 5 - tamanoMano;
		mostrar1(cartas,juego1,cartasRestantes);
		for (int i = 0; i < cartasRestantes; i++)
		{
			mano[tamanoMano + i] = juego1[i];
		}
	}
	for (int i = 0; i < 5; ++i)
	{
		cout << mano[i] << "\t";
	}
	cout << endl;
	//Juega con los dos turnos.
	mano[0] = "AC";
	mano[1] = "2P";
	mano[2] = "3P";
	mano[3] = "4D";
	mano[4] = "5T";
	Escalera(mano);
	//EvaluaPares(mano);

	return 0;
}

//Llenar la mesa de cartas.
void mostrar1(string carta[], string juego1[],int tamano){
	srand (time(NULL));
	int random;
	for (int i = 0; i < 5; ++i)
	{
		juego1[i] = "1";
	}
	for (int i = 0; i < tamano; ++i)
	{
		random = rand() % 52 + 1;
		while(carta[random] == "1"){
			random = rand() % 52 + 1;
		}
		juego1[i] = carta[random];
		carta[random] = "1";
	}
}

//Tomar cartas de la mesa.
void Selecion(string juego1[], string mano[],int tamano){
	int posicion;
	for (int i = 0; i < tamano; ++i)
	{
		cout << "Escoja la posicion: " << endl;
		cin >> posicion;
		mano[i] = juego1[posicion];
	}
}

bool GaneRoyal(string mano[]){
	string Corazon[5] = {"AC","KC","QC","JC","10C"};
	string Pica[5] = {"AP","KP","QP","JP","10P"};
	string Diamante[5] = {"AD","KD","QD","JD","10D"};
	string Trebol[5] = {"AT","KT","QT","JT","10T"};
	int contador1 = 1;
	int contador2 = 1;
	int contador3 = 1;
	int contador4 = 1;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (Corazon[i] == mano[j])
			{
				contador1++;
			}
			if (Pica[i] == mano[j])
			{
				contador2++;
			}
			if (Diamante[i] == mano[j])
			{
				contador3++;
			}
			if (Trebol[i] == mano[j])
			{
				contador4++;
			}
		}
	}
	if (contador1 == 5 || contador2 == 5 || contador3 == 5 || contador4 == 5)
	{
		return true;
	}
	else{
		return false;
	}
}

bool GaneEscaleraColor(string mano[]){
	string Corazon1[5] = {"2C","3C","4C","5C","6C"};
	string Corazon2[5] = {"3C","4C","5C","6C","7C"};
	string Corazon3[5] = {"4C","5C","6C","7C","8C"};
	string Corazon4[5] = {"5C","6C","7C","8C","9C"};
	string Corazon5[5] = {"6C","7C","8C","9C","10C"};
	string Corazon6[5] = {"7C","8C","9C","10C","JC"};
	string Corazon7[5] = {"8C","9C","10C","JC","QC"};
	string Corazon8[5] = {"9C","10C","JC","QC","KC"};

	string Pica1[5] = {"2P","3P","4P","5P","6P"};
	string Pica2[5] = {"3P","4P","5P","6P","7P"};
	string Pica3[5] = {"4P","5P","6P","7P","8P"};
	string Pica4[5] = {"5P","6P","7P","8P","9P"};
	string Pica5[5] = {"6P","7P","8P","9P","10P"};
	string Pica6[5] = {"7P","8P","9P","10P","JP"};
	string Pica7[5] = {"8P","9P","10P","JP","QP"};
	string Pica8[5] = {"9P","10P","JP","QP","KP"};

	string Diamante1[5] = {"2D","3D","4D","5D","6D"};
	string Diamante2[5] = {"3D","4D","5D","6D","7D"};
	string Diamante3[5] = {"4D","5D","6D","7D","8D"};
	string Diamante4[5] = {"5D","6D","7D","8D","9D"};
	string Diamante5[5] = {"6D","7D","8D","9D","10D"};
	string Diamante6[5] = {"7D","8D","9D","10D","JD"};
	string Diamante7[5] = {"8D","9D","10D","JD","QD"};
	string Diamante8[5] = {"9D","10D","JD","QD","KD"};

	string Trebol1[5] = {"2T","3T","4T","5T","6T"};
	string Trebol2[5] = {"3T","4T","5T","6T","7T"};
	string Trebol3[5] = {"4T","5T","6T","7T","8T"};
	string Trebol4[5] = {"5T","6T","7T","8T","9T"};
	string Trebol5[5] = {"6T","7T","8T","9T","10T"};
	string Trebol6[5] = {"7T","8T","9T","10T","JT"};
	string Trebol7[5] = {"8T","9T","10T","JT","QT"};
	string Trebol8[5] = {"9T","10T","JT","QT","KT"};
	int contador1 = 1;
	int contador2 = 1;
	int contador3 = 1;
	int contador4 = 1;
	int contador5 = 1;
	int contador6 = 1;
	int contador7 = 1;
	int contador8 = 1;
	int contador9 = 1;
	int contador10 = 1;
	int contador11 = 1;
	int contador12 = 1;
	int contador13 = 1;
	int contador14 = 1;
	int contador15 = 1;
	int contador16 = 1;
	int contador17 = 1;
	int contador18 = 1;
	int contador19 = 1;
	int contador20 = 1;
	int contador21 = 1;
	int contador22 = 1;
	int contador23 = 1;
	int contador24 = 1;
	int contador25 = 1;
	int contador26 = 1;
	int contador27 = 1;
	int contador28 = 1;
	int contador29 = 1;
	int contador30 = 1;
	int contador31 = 1;
	int contador32 = 1;


	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			//Corazon
			if (Corazon1[i] == mano[j])
			{
				contador1++;
			}
			if (Corazon2[i] == mano[j])
			{
				contador2++;
			}
			if (Corazon3[i] == mano[j])
			{
				contador3++;
			}
			if (Corazon4[i] == mano[j])
			{
				contador4++;
			}
			if (Corazon5[i] == mano[j])
			{
				contador5++;
			}
			if (Corazon6[i] == mano[j])
			{
				contador6++;
			}
			if (Corazon7[i] == mano[j])
			{
				contador7++;
			}
			if (Corazon8[i] == mano[j])
			{
				contador8++;
			}
			//Pica
			if (Pica1[i] == mano[j])
			{
				contador9++;
			}
			if (Pica2[i] == mano[j])
			{
				contador10++;
			}
			if (Pica3[i] == mano[j])
			{
				contador11++;
			}
			if (Pica4[i] == mano[j])
			{
				contador12++;
			}
			if (Pica5[i] == mano[j])
			{
				contador13++;
			}
			if (Pica6[i] == mano[j])
			{
				contador14++;
			}
			if (Pica7[i] == mano[j])
			{
				contador15++;
			}
			if (Pica8[i] == mano[j])
			{
				contador16++;
			}
			//Diamante
			if (Diamante1[i] == mano[j])
			{
				contador17++;
			}
			if (Diamante2[i] == mano[j])
			{
				contador18++;
			}
			if (Diamante3[i] == mano[j])
			{
				contador19++;
			}
			if (Diamante4[i] == mano[j])
			{
				contador20++;
			}
			if (Diamante5[i] == mano[j])
			{
				contador21++;
			}
			if (Diamante6[i] == mano[j])
			{
				contador22++;
			}
			if (Diamante7[i] == mano[j])
			{
				contador23++;
			}
			if (Diamante8[i] == mano[j])
			{
				contador24++;
			}
			//Trebol
			if (Trebol1[i] == mano[j])
			{
				contador25++;
			}
			if (Trebol2[i] == mano[j])
			{
				contador26++;
			}
			if (Trebol3[i] == mano[j])
			{
				contador27++;
			}
			if (Trebol4[i] == mano[j])
			{
				contador28++;
			}
			if (Trebol5[i] == mano[j])
			{
				contador29++;
			}
			if (Trebol6[i] == mano[j])
			{
				contador30++;
			}
			if (Trebol7[i] == mano[j])
			{
				contador31++;
			}
			if (Trebol8[i] == mano[j])
			{
				contador32++;
			}
		}
	}
	if (contador1 == 5 || contador2 == 5 || contador3 == 5 || contador4 == 5 || contador5 == 5 || contador6 == 5 || contador7 == 5 || contador8 == 5|| contador9 == 5 || contador10 == 5 || contador11 == 5 || contador12 == 5 || contador13 == 5 || contador14 == 5 || contador15 == 5 || contador16 == 5 || contador17 == 5 || contador18 == 5 || contador19 == 5 || contador20 == 5 || contador21 == 5 || contador22 == 5 || contador23 == 5 || contador24 == 5 || contador25 == 5 || contador26 == 5 || contador27 == 5 || contador28 == 5 || contador29 == 5 || contador30 == 5 || contador31 == 5 || contador32 == 5)
	{
		return true;
	}
	else{
		return false;
	}
}

bool GanePoker(string mano[]){
	string Cuarteto1[4] = {"AC","AP","AD","AT"};
	string Cuarteto2[4] = {"2C","2P","2D","2T"};
	string Cuarteto3[4] = {"3C","3P","3D","3T"};
	string Cuarteto4[4] = {"4C","4P","4D","4T"};
	string Cuarteto5[4] = {"5C","5P","5D","5T"};
	string Cuarteto6[4] = {"6C","6P","6D","6T"};
	string Cuarteto7[4] = {"7C","7P","7D","7T"};
	string Cuarteto8[4] = {"8C","8P","8D","8T"};
	string Cuarteto9[4] = {"9C","9P","9D","9T"};
	string Cuarteto10[4] = {"10C","10P","10D","10T"};
	string Cuarteto11[4] = {"JC","JP","JD","JT"};
	string Cuarteto12[4] = {"QC","QP","QD","QT"};
	string Cuarteto13[4] = {"KC","KP","KD","KT"};

	int contador1 = 1;
	int contador2 = 1;
	int contador3 = 1;
	int contador4 = 1;
	int contador5 = 1;
	int contador6 = 1;
	int contador7 = 1;
	int contador8 = 1;
	int contador9 = 1;
	int contador10 = 1;
	int contador11 = 1;
	int contador12 = 1;
	int contador13 = 1;

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (Cuarteto1[i] == mano[j])
			{
				contador1++;
			}
			if (Cuarteto2[i] == mano[j])
			{
				contador2++;
			}
			if (Cuarteto3[i] == mano[j])
			{
				contador3++;
			}
			if (Cuarteto4[i] == mano[j])
			{
				contador4++;
			}
			if (Cuarteto5[i] == mano[j])
			{
				contador5++;
			}
			if (Cuarteto6[i] == mano[j])
			{
				contador6++;
			}
			if (Cuarteto7[i] == mano[j])
			{
				contador7++;
			}
			if (Cuarteto8[i] == mano[j])
			{
				contador8++;
			}
			if (Cuarteto9[i] == mano[j])
			{
				contador9++;
			}
			if (Cuarteto10[i] == mano[j])
			{
				contador10++;
			}
			if (Cuarteto11[i] == mano[j])
			{
				contador11++;
			}
			if (Cuarteto12[i] == mano[j])
			{
				contador12++;
			}
			if (Cuarteto13[i] == mano[j])
			{
				contador13++;
			}
		}
	}
	if (contador1 == 5 || contador2 == 5 || contador3 == 5 || contador4 == 5 || contador5 == 5 || contador6 == 5 || contador7 == 5 || contador8 == 5|| contador9 == 5 || contador10 == 5 || contador11 == 5 || contador12 == 5 || contador13 == 5)
	{
		return true;
	}
	else{
		return false;
	}

}


void EvaluaPares(string mano[]){
	string cartas[52] = {"AC","2C","3C","4C","5C","6C","7C","8C","9C","10C","JC","QC","KC","AP","2P","3P","4P","5P","6P","7P","8P","9P","10P","JP","QP","KP","AD","2D","3D","4D","5D","6D","7D","8D","9D","10D","JD","QD","KD","AT","2T","3T","4T","5T","6T","7T","8T","9T","10T","JT","QT","KT"};
	int posiciones[5];
	int prueba;
	int pares1 = 1,pares2 = 1,pares3 = 1,pares4 = 1;
	int color1 = 0,color2 = 0,color3 = 0,color4 = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 52; j++)
		{
			if (mano[i] == cartas[j])
			{
				posiciones[i] = j;
			}
		}
	}

	//Primera lineadel Deck.
	for (int i = 0; i < 5; i++)
	{
		if (posiciones[i] >= 0 && posiciones[i] <= 12)
		{
			color1++;
			prueba = posiciones[i] + 13;
			cout << prueba << endl;
			for (int j = 0; j < 5; j++)
			{
				if (prueba == posiciones[j])
				{
					pares1++;
					posiciones[j] = -1;
				}
			}
			prueba = prueba + 13;
			for (int k = 0; k < 5; k++)
			{
				if (prueba == posiciones[k])
				{
					pares1++;
					posiciones[k] = -1;
				}
			}
			prueba = prueba + 13;
			for (int a = 0; a < 5; a++)
			{
				if (prueba == posiciones[a])
				{
					pares1++;
					posiciones[a] = -1;
				}
			}
			posiciones[i] = -1;
		}
		//Segunda linea del deck.
		else if (posiciones[i] >= 13 && posiciones[i] <= 25)
		{
			color2++;
			prueba = posiciones[i] - 13;
			cout << prueba << endl;
			for (int j = 0; j < 5; j++)
			{
				if (prueba == posiciones[j])
				{
					pares2++;
					posiciones[j] = -1;
				}
			}
			prueba = posiciones[i] + 13;
			for (int k = 0; k < 5; k++)
			{
				if (prueba == posiciones[k])
				{
					pares2++;
					posiciones[k] = -1;
				}
			}
			prueba = prueba + 13;
			for (int a = 0; a < 5; a++)
			{
				if (prueba == posiciones[a])
				{
					pares2++;
					posiciones[a] = -1;
				}
			}
			posiciones[i] = -1;
		}
		//Tercera linea del Deck.
		else if (posiciones[i] >= 26 && posiciones[i] <= 38)
		{
			color3++;
			prueba = posiciones[i] - 13;
			cout << prueba << endl;
			for (int j = 0; j < 5; j++)
			{
				if (prueba == posiciones[j])
				{
					pares3 = pares3 + 1;
					posiciones[j] = -1;
				}
			}
			prueba = prueba - 13;
			for (int k = 0; k < 5; k++)
			{
				if (prueba == posiciones[k])
				{
					pares3 = pares3 + 1;
					posiciones[k] = -1;
				}
			}
			prueba = posiciones[i] + 13;
			for (int a = 0; a < 5; a++)
			{
				if (prueba == posiciones[a])
				{
					pares3 = pares3 + 1;
					posiciones[a] = -1;
				}
			}
			posiciones[i] = -1;
		}
		//Cuarta linea del Deck.
		else if (posiciones[i] >= 39 && posiciones[i] <= 51)
		{
			color4++; 
			prueba = posiciones[i] - 13;
			cout << prueba << endl;
			for (int j = 0; j < 5; j++)
			{
				if (prueba == posiciones[j])
				{
					pares4 = pares4 + 1;
					posiciones[j] = -1;
				}
			}
			prueba = prueba - 13;
			for (int k = 0; k < 5; k++)
			{
				if (prueba == posiciones[k])
				{
					pares4 = pares4 + 1;
					posiciones[k] = -1;
				}
			}
			prueba = prueba - 13;
			for (int a = 0; a < 5; a++)
			{
				if (prueba == posiciones[a])
				{
					pares4++;
					posiciones[a] = -1;
				}
			}
			posiciones[i] = -1;
		}
	}
	for (int i = 0; i < 5; ++i)
	{
		cout << posiciones[i] << endl;
	}
	cout << "--------------" << endl;
	cout << pares1 << endl;
	cout << pares2 << endl;
	cout << pares3 << endl;
	cout << pares4 << endl;
}

void Escalera(string mano[]){
	string cartas[52] = {"AC","2C","3C","4C","5C","6C","7C","8C","9C","10C","JC","QC","KC","AP","2P","3P","4P","5P","6P","7P","8P","9P","10P","JP","QP","KP","AD","2D","3D","4D","5D","6D","7D","8D","9D","10D","JD","QD","KD","AT","2T","3T","4T","5T","6T","7T","8T","9T","10T","JT","QT","KT"};
	int Escalera1[4] = {0,13,26,39};
	int Escalera2[4] = {1,14,27,40};
	int Escalera3[4] = {2,15,28,41};
	int Escalera4[4] = {3,16,29,42};
	int Escalera5[4] = {4,17,30,43};
	int Escalera6[4] = {5,18,31,44};
	int Escalera7[4] = {6,19,32,45};
	int Escalera8[4] = {7,20,33,46};
	int Escalera9[4] = {8,21,34,47};
	int Escalera10[4] = {9,22,35,48};
	int Escalera11[4] = {10,23,36,49};
	int Escalera12[4] = {11,24,37,50};
	int Escalera13[4] = {12,25,38,51};
	int posiciones1[5];
	int numerosDeCartas[5];

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 52; j++)
		{
			if (mano[i] == cartas[j])
			{
				posiciones1[i] = j;
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (Escalera1[j] == posiciones1[i])
			{
				numerosDeCartas[i] = 1;
			}
			else if (Escalera2[j] == posiciones1[i])
			{
				numerosDeCartas[i] = 2;
			}
			else if (Escalera3[j] == posiciones1[i])
			{
				numerosDeCartas[i] = 3;
			}
			else if (Escalera4[j] == posiciones1[i])
			{
				numerosDeCartas[i] = 4;
			}
			else if (Escalera5[j] == posiciones1[i])
			{
				numerosDeCartas[i] = 5;
			}
			else if (Escalera6[j] == posiciones1[i])
			{
				numerosDeCartas[i] = 6;
			}
			else if (Escalera7[j] == posiciones1[i])
			{
				numerosDeCartas[i] = 7;
			}
			else if (Escalera8[j] == posiciones1[i])
			{
				numerosDeCartas[i] = 8;
			}
			else if (Escalera9[j] == posiciones1[i])
			{
				numerosDeCartas[i] = 9;
			}
			else if (Escalera10[j] == posiciones1[i])
			{
				numerosDeCartas[i] = 10;
			}
			else if (Escalera11[j] == posiciones1[i])
			{
				numerosDeCartas[i] = 11;
			}
			else if (Escalera12[j] == posiciones1[i])
			{
				numerosDeCartas[i] = 12;
			}
			else if (Escalera13[j] == posiciones1[i])
			{
				numerosDeCartas[i] = 13;
			}
		}
	}
	int temp;
	for (int q = 0; q < 5; ++q)
	{
		for (int w = 0; w < 5 - 1; ++w)
		{
			if (numerosDeCartas[w] > numerosDeCartas[w + 1])
			{
				temp = numerosDeCartas[w];
				numerosDeCartas[w] = numerosDeCartas[w + 1];
				numerosDeCartas[w + 1] = temp;
			}
		}
	}

	for (int z = 0; z < 5; ++z)
	{
		cout << numerosDeCartas[z] << "\t";
	}

	if ((numerosDeCartas[1] == (numerosDeCartas[0] + 1)) && (numerosDeCartas[2] == (numerosDeCartas[1] + 1)) && (numerosDeCartas[3] == (numerosDeCartas[2] + 1)) && (numerosDeCartas[4] == (numerosDeCartas[3] + 1)))
	{
		cout << "Gano por Escalera" << endl;
	}
	
}