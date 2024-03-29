#ifndef GENERIC_PARSETREE_INL_H
#define GENERIC_PARSETREE_INL_H

#include <memory>
#include "generic_parsetree.h"
#include "utility.h"

namespace Chameleon::Base {

template<Layer T>
bool ParseTree<T>::operator==(
  const ParseTree& other) const {
  // ParseTree is recursive type which requrie that
  // equality check should be recursive too.
  std::function<bool(const ParseTree& l,
    const ParseTree& r)>
    equality_check = [&equality_check](
      const ParseTree& l, const ParseTree& r) {
      // Check node type
      if (!(l.metaRef == r.metaRef)) {
        return false;
      }

      // Check equality of childs
      if (l.childs_.size() != r.childs_.size()) {
        return false;
      } else {
        if (l.childs_.size() == 0) {
          // Terminal
          return l.metaRef == r.metaRef;
        }

        std::vector<ParseTree*> l_children(l.childs_.size());
        std::vector<ParseTree*> r_children(r.childs_.size());

        std::transform(l.childs_.begin(),
                       l.childs_.end(),
                       l_children.begin(),
                       [](const std::unique_ptr<ParseTree>& c) {
                         return c.get();
                       });

        std::transform(r.childs_.begin(),
                       r.childs_.end(),
                       r_children.begin(),
                       [](const std::unique_ptr<ParseTree>& c) {
                         return c.get();
                       });

        auto zipped = Utility::zip_vector<
          ParseTree*>(l_children, r_children);
        if (zipped.size() == 0) { return false; }

        for (auto& [thisChilds, otherChilds]: zipped) {
          if (!equality_check(*thisChilds, *otherChilds)) {
            return false;
          }
        }
        return true;
      }
    };
  return equality_check(*this, other);
}

template<Layer T>
void ParseTree<T>::traverse(
  std::function<bool(ParseTree&)> proc) {

  if (!proc(*this)) return;
  for (auto& c: childs_) {
    c->traverse(proc);
  }
}


template<Layer T>
ParseTree<T>* ParseTree<T>::select(
  std::function<bool(ParseTree&)> predicate) {

  ParseTree* tree = NULL;
  traverse([&](ParseTree& node) {
    if (predicate(node)) {
      tree = &node;
      return false;
    } else {
      return true;
    }
  });
  return tree;
}

} // Base

#endif /* GENERIC_PARSETREE_INL_H */
