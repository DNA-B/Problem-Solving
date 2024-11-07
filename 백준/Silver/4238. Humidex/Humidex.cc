#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
//========= MACRO =========//
#define PI 3.1415926535897932
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
//=========================//

//======= VARIABLEs =======//
char let1, let2;
double v1, v2;
//=========================//

double calHumidex(double temperature, double dewpoint) {
	double e = 6.11 * exp(5417.7530 * ((1.0 / 273.16) - (1.0 / (dewpoint + 273.16))));
	double h = 0.5555 * (e - 10.0);
	return temperature + h;
}

double calDewpoint(double temperature, double humidex) {
	double h = humidex - temperature;
	double e = (h / 0.5555) + 10.0;
	return 1.0 / ((1.0 / 273.16) - (log(e / 6.11) / 5417.7530)) - 273.16;
}

double calTemperature(double dewpoint, double humidex) {
	double e = 6.11 * exp(5417.7530 * ((1.0 / 273.16) - (1.0 / (dewpoint + 273.16))));
	double h = 0.5555 * (e - 10.0);
	return humidex - h;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cout << fixed << setprecision(1);

	while (cin >> let1 >> v1 >> let2 >> v2) {
		double temperature, dewpoint, humidex;

		if (let1 == 'T' && let2 == 'D') {
			temperature = v1;
			dewpoint = v2;
			humidex = calHumidex(temperature, dewpoint);
		}
		else if (let1 == 'T' && let2 == 'H') {
			temperature = v1;
			humidex = v2;
			dewpoint = calDewpoint(temperature, humidex);
		}
		else if (let1 == 'D' && let2 == 'H') {
			dewpoint = v1;
			humidex = v2;
			temperature = calTemperature(dewpoint, humidex);
		}
		else if (let1 == 'D' && let2 == 'T') {
			dewpoint = v1;
			temperature = v2;
			humidex = calHumidex(temperature, dewpoint);
		}
		else if (let1 == 'H' && let2 == 'T') {
			humidex = v1;
			temperature = v2;
			dewpoint = calDewpoint(temperature, humidex);
		}
		else if (let1 == 'H' && let2 == 'D') {
			humidex = v1;
			dewpoint = v2;
			temperature = calTemperature(dewpoint, humidex);
		}

		cout << "T " << temperature << " D " << dewpoint << " H " << humidex << '\n';
	}

	return 0;
}