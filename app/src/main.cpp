#include <iostream>
#include <cxxopts.hpp>
#include <generator.hpp>
#include <spdlog/spdlog.h>
#if WIN32
#define NOMINMAX
#include <Windows.h>
#endif
#include "options.hpp"

int main(int argc, char **argv)
{
#if WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    cxxopts::Options options{"protodoc", "Generates a protocol description document from a commsdsl schema."};
    prepareOptions(options);
    const auto result = options.parse(argc, argv);
    if (result.count("help"))
    {
        std::cout << options.help() << std::endl;
        exit(EXIT_FAILURE);
    }

    protodoc::GeneratorOpts gen_opts;
    try
    {
        parseOpts(result, gen_opts);
    }
    catch (std::exception e)
    {
        spdlog::critical("Error while reading the program options: {}", e.what());
        std::cout << options.help() << std::endl;
        exit(EXIT_FAILURE);
    }

    protodoc::Generator gen;
    gen.generate(gen_opts);

    return 0;
}
