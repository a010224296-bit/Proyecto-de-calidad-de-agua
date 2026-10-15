#include <string>
#include <vector>

// Superclase base
class Sensor {
protected:
    std::string idSensor;
    std::string tipo;
    std::string ubicacion;

public:
    void leerDato();
    void obtenerEstado();
};

// Subclases que heredan de Sensor
class SensorPH : public Sensor {
private:
    double nivelPH;
    double rangoSeguro;

public:
    void medirPH();
    void validarPH();
};

class SensorSTD : public Sensor {
private:
    double ppm;
    double limitePPM;

public:
    void medirSTD();
    void validarSTD();
};

class SensorTurbidez : public Sensor {
private:
    double nivelNTU;
    double limiteNTU;

public:
    void medirTurbidez();
    void validarTurbidez();
};

class SensorCloro : public Sensor {
private:
    double nivelCloro;
    double limiteCloro;

public:
    void medirCloro();
    void validarCloro();
};

// Clase Lectura
class Lectura {
private:
    std::string idLectura;
    double valor;
    std::string fechaHora;

public:
    void guardarLectura();
    double obtenerValor();
};

// Clase Alerta
class Alerta {
private:
    std::string idAlerta;
    std::string mensaje;
    std::string fecha;

public:
    void generarAlerta();
    void enviarNotificacion();
};

// Clase Historial (Agregación de Lectura)
class Historial {
private:
    std::vector<Lectura> listaLecturas;
    int totalRegistros;

public:
    void agregarLectura();
    void consultarHistorial();
};

// Clase Predicciones[cite: 4, 5]
class Predicciones {
private:
    std::string algoritmo;
    double resultadoEstimado;

public:
    void calcularTendencia();
    void predecirCalidad();
};