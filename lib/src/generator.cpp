#include "generator.hpp"
#include <iostream>
#include <sstream>
#include <commsdsl/version.h>
#include <spdlog/spdlog.h>
#include "backend.hpp"
namespace protodoc
{

Generator::Generator(std::unique_ptr<Backend> &&backend)
    : backend_{std::move(backend)}
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
    return writeFrames() && writeMessages();
}

bool Generator::writeFrames()
{
    std::stringstream ss;
    ss << backend_->buildChapter(1, "Frames");
    for (const auto &ns : protocol_.namespaces())
    {
        for (const auto &frame : ns.frames())
        {
            ss << backend_->buildChapter(2, frame.name());
            ss << backend_->testFrame(frame);
        }
    }
    std::cout << ss.str() << std::endl;
    return true;
}

bool Generator::writeMessages()
{
    return true;
}
} // namespace protodoc
