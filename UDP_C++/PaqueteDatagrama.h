#ifndef PaqueteDatagrama_H_
#define PaqueteDatagrama_H_

class PaqueteDatagrama {
	public:
		PaqueteDatagrama(const char * datos, unsigned int longitud, const char * ip, int puerto);
		PaqueteDatagrama(unsigned int longitud);
		~PaqueteDatagrama();
		char *obtieneDireccion();
		unsigned int obtieneLongitud();
		int obtienePuerto();
		char *obtieneDatos();
		void inicializaPuerto(int puerto);
		void inicializaIp(const char * ip);
		void inicializaDatos();
		void inicializaDatos(const char * datos);
	private:
		char *datos;
		char ip[16];
		unsigned int longitud;
		int puerto;
};

#endif
