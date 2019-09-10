#include <iostream>
using namespace std;

class Temperatura {
private:
  double kelvin;
public:
  void setTempKelvin(double tem);
  void setTempFahrenheit(double tem);
  void setTempCelsius(double tem);
  double getTempKelvin();
  double getTempFahrenheit();
  double getTempCelsius();
};

void Temperatura::setTempKelvin(double tem) {
  kelvin = tem;
}

void Temperatura::setTempCelsius(double tem) {
  kelvin = tem + 273.15;
}
void Temperatura::setTempFahrenheit(double tem) {
  kelvin = (tem - 32.0) * (5 / 9.0) + 273.15;
}
double Temperatura::getTempCelsius() {
  return kelvin - 273.15;
}
double Temperatura::getTempFahrenheit() {
  return (kelvin - 273.15) * (9.0 / 5) + 32;
}
double Temperatura::getTempKelvin() {
  return kelvin;
}

int main() {
  Temperatura temp;
  temp.setTempKelvin(0);
  cout << "Kelvin" << endl;
  cout << "\tCelsius: " << temp.getTempCelsius() << endl;
  cout << "\tFarenheit: " << temp.getTempFahrenheit() << endl;
  
  temp.setTempFahrenheit(temp.getTempFahrenheit());
  cout << "Fahrenheit: " << endl;
  cout << "\tCelsius: " << temp.getTempCelsius() << endl;
  cout << "\tKelvin: " << temp.getTempKelvin() << endl;

  temp.setTempCelsius(temp.getTempCelsius());
  cout << "Celsius: " << endl;
  cout << "\tKelvin: " << temp.getTempKelvin() << endl;
  cout << "\tFarenheit: " << temp.getTempFahrenheit() << endl;  
}