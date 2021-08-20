#pragma once
#include <cxxopts.hpp>
#include <generator.hpp>

void prepareOptions(cxxopts::Options &opts);
void parseOpts(const cxxopts::ParseResult &res, protodoc::GeneratorOpts& opts);
