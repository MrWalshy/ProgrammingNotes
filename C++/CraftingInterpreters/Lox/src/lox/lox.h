#ifndef LOX_H
#define LOX_H
#include <string>
#include <vector>

class Lox
{
    public:
        void run(int argc, char* argv[]);
        void runFile(std::string fileName);
        void runPrompt();
        void run(const std::string& data);

        static void error(int line, const std::string& message);

        static bool hadError;

    private:
        std::string readFile(const std::string& fileName);
        static void report(int line, const std::string& where, const std::string& message);
};
#endif