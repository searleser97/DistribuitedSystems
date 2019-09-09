#ifndef Temperatura_H_
#define Temperatura_H_

class Temperatura {
	private:
		double K;
	public:
		void setTempKelvin(double K);
		void setTempFahrenheit(double F);
		void setTempCelsius(double C);
		double getTempKelvin();
		double getTempFahrenheit();
		double getTempCelsius();
};

#endif
