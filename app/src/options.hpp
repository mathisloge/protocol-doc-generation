#pragma once
#include <cxxopts.hpp>
#include <protodoc/generator.hpp>

void prepareOptions(cxxopts::Options &opts);
void parseOpts(const cxxopts::ParseResult &res, protodoc::GeneratorOpts& opts);
void printVersion();
