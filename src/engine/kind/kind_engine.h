/*
 * kind_engine.h
 *
 *  Created on: Nov 23, 2014
 *      Author: dejan
 */

#include "smt/solver.h"
#include "system/context.h"
#include "engine/engine.h"
#include "expr/term.h"

#include <vector>

namespace sal2 {
namespace kind {

/**
 * K-Induction engine.
 *
 * Prove:
 *
 * (1) P holds at 0, ..., k-1, i.e.
 *     I and T_0 and ... and T_{i-1} => P(x_i), for 0 <= i < k
 * (2) P holding at k consecutive step, implies it holds in the next one, i.e.
 *     and_{0 <= i < k} (P_i and T_i) => P_k
 */
class kind_engine : public engine {

  /** SMT solver for proving (1) */
  smt::solver* d_solver_1;

  /** SMT solver for proving (2) */
  smt::solver* d_solver_2;

public:

  kind_engine(const system::context& ctx);
  ~kind_engine();

  /** Query */
  result query(const system::transition_system& ts, const system::state_formula* sf);

};

}
}
