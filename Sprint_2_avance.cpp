#include <string>
#include <vector>
using namespace std;

class Sensor {
protected:
    string idSensor;
    string tipo;
    string ubicacion;

public:
    Sensor(string idSensor = "", string tipo = "", string ubicacion = "") {
        this->idSensor = idSensor;
        this->tipo = tipo;
        this->ubicacion = ubicacion;
    }
    virtual ~Sensor() {}
    string obtenerEstado();
    void leerDato();
};

// Subclases que heredan de Sensor
class SensorPH : public Sensor {
private:
    double nivelPH;
    double rangoSeguro;

public:
    SensorPH(string idSensor, string ubicacion, double rangoSeguro = 8.5) {
        this->idSensor = idSensor;
        this->tipo = "pH";
        this->ubicacion = ubicacion;
        this->nivelPH = 7.0;
        this->rangoSeguro = rangoSeguro;
    }
    void medirPH();
    void validarPH();
};

class SensorSTD : public Sensor {
private:
    double ppm;
    double limitePPM;

public:
    SensorSTD(string idSensor, string ubicacion, double limitePPM = 600.0) {
        this->idSensor = idSensor;
        this->tipo = "STD";
        this->ubicacion = ubicacion;
        this->ppm = 0.0;
        this->limitePPM = limitePPM;
    }
    void medirSTD();
    void validarSTD();
};

class SensorTurbidez : public Sensor {
private:
    double nivelNTU;
    double limiteNTU;

public:
    SensorTurbidez(string idSensor, string ubicacion, double limiteNTU = 4.0) {
        this->idSensor = idSensor;
        this->tipo = "Turbidez";
        this->ubicacion = ubicacion;
        this->nivelNTU = 0.0;
        this->limiteNTU = limiteNTU;
    }
    void medirTurbidez();
    void validarTurbidez();
};

class SensorCloro : public Sensor {
private:
    double nivelCloro;
    double limiteCloro;

public:
    SensorCloro(string idSensor, string ubicacion, double limiteCloro = 1.5) {
        this->idSensor = idSensor;
        this->tipo = "Cloro";
        this->ubicacion = ubicacion;
        this->nivelCloro = 0.0;
        this->limiteCloro = limiteCloro;
    }
    void medirCloro();
    void validarCloro();
};

// Clase Lectura
class Lectura {
private:
    string idLectura;
    double valor;
    string fechaHora;

public:
    Lectura(string idLectura, double valor, string fechaHora) {
        this->idLectura = idLectura;
        this->valor = valor;
        this->fechaHora = fechaHora;
    }
    void guardarLectura();
    double obtenerValor();
};

// Clase Alerta
class Alerta {
private:
    string idAlerta;
    string mensaje;
    string fecha;

public:
    Alerta(string idAlerta, string mensaje, string fecha) {
        this->idAlerta = idAlerta;
        this->mensaje = mensaje;
        this->fecha = fecha;
    }
    void generarAlerta();
    void enviarNotificacion();
};

class Historial {
private:
    vector<Lectura> listaLecturas;
    int totalRegistros;

public:
    Historial() {
        this->totalRegistros = 0;
    }
    void agregarLectura();
    void consultarHistorial();
};

class Predicciones {
private:
    string algoritmo;
    double resultadoEstimado;

public:
    Predicciones(string algoritmo) {
        this->algoritmo = algoritmo;
        this->resultadoEstimado = 0.0;
    }
    void calcularTendencia();
    void predecirCalidad();
};
