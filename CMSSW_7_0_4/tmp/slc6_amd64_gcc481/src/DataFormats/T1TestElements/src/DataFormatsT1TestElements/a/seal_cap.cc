static  const char* clnames[] = {
  "LCGReflex/T1TestElements",
  "LCGReflex/std::vector<T1TestElements>",
  "LCGReflex/edm::Wrapper<std::vector<T1TestElements> >",
};
extern "C" void SEAL_CAPABILITIES (const char**& names, int& n )
{names = clnames;n = sizeof(clnames)/sizeof(char*);}
