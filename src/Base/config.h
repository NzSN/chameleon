#ifndef CONFIG_H
#define CONFIG_H

#include "gc_defines.h"

// Enable GC by default
#ifndef ENABLE_GC
#define ENABLE_GC true
#endif

/* Macros that enforce to define */
namespace Config {

enum Configs {
  GC = ENABLE_GC
};

template<Configs config>
concept isGCEnable = Configs::GC == true;

} // Config

#endif /* CONFIG_H */
