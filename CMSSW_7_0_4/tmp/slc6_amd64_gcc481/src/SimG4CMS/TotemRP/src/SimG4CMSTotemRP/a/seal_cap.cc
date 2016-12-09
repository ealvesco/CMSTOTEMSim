static  const char* clnames[] = {
  "LCGReflex/TotemRPHistoClass",
  "LCGReflex/TotemRPHistoClass::Hit",
  "LCGReflex/std::vector<TotemRPHistoClass::Hit>",
};
extern "C" void SEAL_CAPABILITIES (const char**& names, int& n )
{names = clnames;n = sizeof(clnames)/sizeof(char*);}
