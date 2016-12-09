static  const char* clnames[] = {
  "LCGReflex/mitedm::EvtSelData",
  "LCGReflex/edm::Wrapper<mitedm::EvtSelData>",
};
extern "C" void SEAL_CAPABILITIES (const char**& names, int& n )
{names = clnames;n = sizeof(clnames)/sizeof(char*);}
