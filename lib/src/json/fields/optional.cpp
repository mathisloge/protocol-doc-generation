#include "optional.hpp"
#include <sstream>
#include "../endian.hpp"
#include "../types.hpp"
#include "../units.hpp"
#include "field.hpp"

using namespace protodoc;
namespace commsdsl
{

static void addCond(std::ostream &cond_str, const commsdsl::OptCond &cond)
{
    if (!cond.valid())
        return;
    switch (cond.kind())
    {
    case commsdsl::OptCond::Kind::Expr: {
        const commsdsl::OptCondExpr expr{cond};
        cond_str << expr.left() << expr.op() << expr.right();
        break;
    }
    case commsdsl::OptCond::Kind::List: {
        commsdsl::OptCondList l{cond};
        auto cl{l.conditions()};
        for (auto &c : cl)
            addCond(cond_str, c);
        break;
    }
    default:
        break;
    }
}

static void to_json(protodoc::json_obj &j, const commsdsl::OptCond &f)
{
    std::stringstream cond_str;
    addCond(cond_str, f);
    j = cond_str.str();
}

void to_json(protodoc::json_obj &j, const commsdsl::OptionalField &f)
{
    j.merge_patch({{kKeyType, kOptionalType}, {kKeyFieldField, f.field()}, {"condition", f.cond()}});
}

} // namespace commsdsl
