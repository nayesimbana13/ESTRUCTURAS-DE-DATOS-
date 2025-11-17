#include <iostream>
#include <cstdarg>
#include <ctime>

class Logger {
public:
    enum Level {
        INFO,
        WARNING,
        ERROR,
        DEBUG
    };

    static void log(Level level, const char* formato, ...) {
        // Obtener tiempo actual
        time_t ahora = time(nullptr);
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&ahora));
        
        // Imprimir nivel y tiempo
        std::cout << buffer << " [";
        switch(level) {
            case INFO: std::cout << "INFO"; break;
            case WARNING: std::cout << "WARNING"; break;
            case ERROR: std::cout << "ERROR"; break;
            case DEBUG: std::cout << "DEBUG"; break;
        }
        std::cout << "] ";
        
        // Imprimir mensaje formateado
        va_list args;
        va_start(args, formato);
        vprintf(formato, args);
        va_end(args);
        
        std::cout << std::endl;
    }
};

int main() {
    Logger::log(Logger::INFO, "Aplicación iniciada");
    Logger::log(Logger::DEBUG, "Valor de x: %d", 42);
    Logger::log(Logger::WARNING, "Memoria baja: %d%% disponible", 15);
    Logger::log(Logger::ERROR, "Error en archivo: %s, línea: %d", "main.cpp", 123);
    Logger::log(Logger::INFO, "Procesando %d archivos en %s", 10, "C:/datos");
    
    return 0;
}