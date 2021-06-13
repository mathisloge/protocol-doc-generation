#include "generator.hpp"
#if WIN32
#include <Windows.h>
#endif



int main(int argc, char const *argv[])
{
#if WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    protodoc::Generator gen{};

    gen.generate({"D:\\dev\\commsdsl_latex_text\\schema.xml"});
    return 0;
}
