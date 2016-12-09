static  const char* clnames[] = {
  "LCGReflex/TotRPDetId",
};
extern "C" void SEAL_CAPABILITIES (const char**& names, int& n )
{names = clnames;n = sizeof(clnames)/sizeof(char*);}
