static  const char* clnames[] = {
  "LCGReflex/T1RecHitGlobal",
  "LCGReflex/T1T2Track",
  "LCGReflex/T2Road",
  "LCGReflex/T2Hit",
  "LCGReflex/std::vector<T1RecHitGlobal>",
  "LCGReflex/std::vector<T1T2Track>",
  "LCGReflex/edm::Wrapper<std::vector<T1T2Track> >",
};
extern "C" void SEAL_CAPABILITIES (const char**& names, int& n )
{names = clnames;n = sizeof(clnames)/sizeof(char*);}
