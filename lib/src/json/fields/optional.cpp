#include "optional.hpp"
#include <sstream>
#include "../endian.hpp"
#include "../types.hpp"
#include "../units.hpp"
#include "field.hpp"

namespace protodoc
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

void to_json(json_obj &j, const commsdsl::OptionalField &f)
{
    j[kKeyType] = kOptionalType;
    {
        std::stringstream cond_str;
        addCond(cond_str, f.cond());
        j["condition"] = cond_str.str();
    }
    to_json(j[kKeyFieldField], f.field());
}

} // namespace protodoc
