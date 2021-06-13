#include "generator.hpp"
#include <iostream>
#include <sstream>
#include <commsdsl/version.h>
#include <inja/environment.hpp>
#include <spdlog/spdlog.h>
namespace protodoc
{

Generator::Generator()
{}

bool Generator::generate(const FilesList &files)
{
    return parseSchemaFiles(files) && write();
}

bool Generator::parseSchemaFiles(const FilesList &files)
{
    for (auto &f : files)
    {
        spdlog::info("Parsing {}", f.string());
        if (!protocol_.parse(f.string()))
        {
            return false;
        }
    }

    if (!protocol_.validate())
    {
        return false;
    }

    auto schema = protocol_.schema();

    if (commsdsl::versionMajor() < schema.dslVersion())
    {
        spdlog::error("Required DSL version is too big ({}), upgrade your code generator.", schema.dslVersion());
        return false;
    }

    return true;
}

bool Generator::write()
{
    //! \todo base on program options
    inja::Environment env{"D:/dev/protocol-doc-generation/templates/latex/", "D:/dev/commsdsl_latex_text/gen/latex/"};

    env.parse_file("base.tex");


    return writeFrames() && writeMessages();
}

bool Generator::writeFrames()
{

    return true;
}

bool Generator::writeMessages()
{
    return true;
}
} // namespace protodoc
