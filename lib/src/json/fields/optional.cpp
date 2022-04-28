#include "optional.hpp"
#include <sstream>
#include "../endian.hpp"
#include "../units.hpp"
#include "field.hpp"

using namespace protodoc;
namespace commsdsl::parse
{

static void addCond(std::ostream &cond_str, const OptCond &cond)
{
    if (!cond.valid())
        return;
    switch (cond.kind())
    {
    case OptCond::Kind::Expr: {
        const OptCondExpr expr{cond};
        cond_str << expr.left() << expr.op() << expr.right();
        break;
    }
    case OptCond::Kind::List: {
        OptCondList l{cond};
        auto cl{l.conditions()};
        for (auto &c : cl)
            addCond(cond_str, c);
        break;
    }
    default:
        break;
    }
}

static void to_json(protodoc::json_obj &j, const OptCond &f)
{
    std::stringstream cond_str;
    addCond(cond_str, f);
    j = cond_str.str();
}

void to_json(protodoc::json_obj &j, const OptionalField &f)
{
    j.merge_patch({{kKeyType, kOptionalType}, {kKeyFieldField, f.field()}, {"condition", f.cond()}});
}

} // namespace commsdsl::parse
